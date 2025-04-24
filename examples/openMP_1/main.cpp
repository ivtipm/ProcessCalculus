/*
Набор примеров использования OpenMP

Для компиляции нужно указать ключ -fopenmp 
Иначе не будут подключены только заголовочный файл, но не статические библиотеки OpenMP с реализациями функций библиотеки
См. СMakeLists.txt или  openMP_1.pro (если программа запускается в QtCreator)

Подготовка сборки Cmake:
> cmake -B build
Сборка:
> cmake --build build

*/
#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <omp.h>        // Анализатор кода Qt Creator тут может выдавать ошибку, но всё на самом деле ок
// см. также pro файл

using namespace std;
using chrono::system_clock;
using Time = decltype ( chrono::system_clock::now() );


/// Простая функция для вывода времени работы программы в миллисекундах
void print_dt(Time t0){
    auto t1 = system_clock::now();
    cout << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << "ms" <<endl;}


/// Пример 1. Простое параллельное выполнение блока кода
void example1_hello_world(){
    // напечатаем текущее число потоков
    cout << "threads: " << omp_get_num_threads() << endl;                  // 1

    // запуск кода в фигурных скобках в 4 потока -- он выполнится 4 раза.
    #pragma omp parallel num_threads(4)
    {
    // cout << "threads: " << omp_get_num_threads() << endl;                // 4
    cout << "Hello, || World from thread" << omp_get_thread_num() << "!" << endl;
    }

    cout << "threads: " << omp_get_num_threads() << endl;                   //  1
    printf("Done");
}


/// Пример 2. Распараллеливание цикла
void example2_ll_for(){

    #pragma omp parallel for
    for (unsigned i = 0; i< 100; i++) {
        cout << i << endl;
    }

    // pragma omp parallel for:
    // 1. определит оптимальное число потоков
    // 2. сделает из тела цикла отдельную функцию
    // 3. разделит общее число итераций цикла между потоками
}




/// Пример 3. Два блока кода (section) будет выполняться параллельно, каждый своим потоком
void example3_ll_sections(){

    #pragma omp parallel sections
    {
        #pragma omp section
        for (unsigned i = 0; i<100; i+=2)
            cout << i << endl;

        #pragma omp section
        for (unsigned i = 1; i<100; i+=2)
            cout << i << endl;
    }
}


/// Пример 4. Синхронизация, использование общих переменных
void example4_shared_private_atomic_reduction(){
    double sum = 0.0;

    // пример с ошибками:
    #pragma omp parallel for private(sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "private sum: " << sum << endl;
    // Ошибки:                                                                                                Каждый поток получит локальную копию переменной sum, будет её изменять, но после завершения цикла эти переменные уничтожатся


    // пример с ошибками:
    sum = 0;
    #pragma omp parallel for shared(sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "shared sum: " << sum << endl;
     // Ошибки:                                                                                                 Здесь используется неатомарная операция над общей для потоков переменной. Возникает неопределённость параллелизма.


    // Пример без ошибок, но медленный.
    sum = 0;
    #pragma omp parallel for
    for (unsigned i = 0; i< 100; i++) {
        #pragma omp atomic
        sum += 1;
    }
    cout << "shared atomic sum: " << sum << endl;

    // private -- у каждого потока будет своя, локальная, копия переменной
    // shared -- переменная будет общей для всех потоков, но ей изменение не потокобезопасно

    // #pragma omp atomic  -- сделать следующий за директивой оператор присваивания атомарным.
    // потоки будут ждать завершения оператора присваивания
    // при этом правая часть оператора = может выполнятся ||


    // Хороший пример
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "reduction sum: " << sum << endl;

   // reduction(+:sum):
   // сделает локальную копию sum в каждом потоке
   // после завершения всех потоков выполнит указанное действие (+) для всех локальных копий
}


// сравнение времени выполнения
void example2_ll_for2(){
    double sum = 0;
    const unsigned long N = 1e8;

    cout << "\nNo OpenMP:" << endl;
    auto t0 = system_clock::now();
    for (unsigned long i = 0; i< N; i++) {
        sum += atan(i);
    }
    cout << "   sum = " << sum << endl;
    cout << "   "; print_dt(t0);


    cout << "\nOpenMP:" << endl;
    t0 = system_clock::now();

    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (unsigned long i = 0; i< N; i++) {
        sum += atan(i);
    }
    cout << "   sum = " << sum << endl;
    cout << "   "; print_dt(t0);
}


// возвращает true если число простое
bool is_prime(unsigned n){
    for (unsigned i=2; i<(int)sqrt(n); i++){
        if (n % i == 0) return false;
    } return true;
}

// Элемент списка
struct Node{
    int x;
    bool is_prime;
    Node* next; };

void set_node_isprime(Node *node){
    node->is_prime = is_prime(node->x);
}

// Задачи
void example_tasks(){


    Node *head;
    head = new Node;
    head->x = rand();

    unsigned N = 1000000;
    Node *node = head;
    for (unsigned i =1; i <N; i++) {
        Node *tmp = new Node;
        tmp->x = rand();
        node->next = tmp;
        node = node->next;
    }
    node->next = nullptr;
    node = head;

//    while (node){
//        cout << node->x << " ";
//        node = node->next;
//    }


       cout << "threads: " << omp_get_num_threads() << endl;
    double t0 = omp_get_wtime();
    #pragma omp parallel
    {
        cout << "threads: " << omp_get_num_threads() << endl;
        #pragma omp single nowait
        {
        node = head;
        while (node) {
            #pragma omp task firstprivate( node )
            {
                set_node_isprime( node );
            }
            node = node->next;
                    }
        }
    }
    cout << "|| alg: " << omp_get_wtime() - t0 << " sec" << endl;


    t0 = omp_get_wtime();
    node = head;
    while (node) {
        set_node_isprime( node );
        node = node->next;
    }
    cout << "-- alg: " << omp_get_wtime() - t0 << " sec" << endl;
}


int main()
{   // максимальное эффективное число потоков для данного компьютера
    cout << "max threads: " << omp_get_max_threads() << endl;

//    example1_hello_world();         // hello, || world!
//    example2_ll_for();              // распараллеливание цикла
//    example3_ll_sections();
//    example4_shared_private_atomic_reduction();
//    example2_ll_for2();              // сравнение после и || циклов
    example_tasks();
    return 0;
}


// Документация OpenMP с примерами:
// https://www.openmp.org/wp-content/uploads/openmp-examples-4.0.2.pdf
