#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <omp.h>
// см. также pro файл

using namespace std;

// простой пример распараллеливания кода
void example1_hello_world(){
    // напечатаем текущее число потоков
    cout << "threads: " << omp_get_num_threads() << endl;                  // 1

    // запуск кода в фигурных скобках в 4 потока -- он выполнится 4 раза.
    #pragma omp parallel num_threads(4)
    {
//    cout << "threads: " << omp_get_num_threads() << endl;                // 4
    cout << "Hello, || World from thread" << omp_get_thread_num() << "!" << endl;
    }

    cout << "threads: " << omp_get_num_threads() << endl;                   //  1
    printf("Done");
}


// распараллеливание цикла
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


// явное || разных блоков кода
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

    // pragma omp parallel for:
    // 1. определит оптимальное число потоков
    // 2. сделает из тела цикла отдельную функцию
    // 3. разделит общее число итераций цикла между потоками
}



void example4_shared_private_atomic_reduction(){
    double sum = 0.0;

    // плохой пример
    #pragma omp parallel for private(sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "private sum: " << sum << endl;

    // плохой пример
    sum = 0;
    #pragma omp parallel for shared(sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "shared sum: " << sum << endl;

    // медленный пример
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


    // хороший пример
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (unsigned i = 0; i< 100; i++) {
        sum += 1;
    }
    cout << "reduction sum: " << sum << endl;

//    reduction(+:sum):
   // сделает локальную копию sum в каждом потоке
   // после завершения всех потоков выполнит указанное действие (+) для всех локальных копий
}

using vector_int = vector<int>;

double sum_l(unsigned long n){
    double s = 0;
    for(unsigned long i=0; i<n; i++){
        s += sin(i);
    }

    return s;
}


double sum_ll(unsigned long n){

    double s = 0;
    #pragma parallel omp for num_threads(6) // reduction(+:s)
    for(unsigned long i=0; i<n; i++){
        s += sin(i % 100);
    }

    return s;
}


void print_array(vector_int *v){
    for(unsigned long i=0; i<v->size(); i++){
        cout << v->at(i) << " ";
    }
}

int main()
{
    cout << "max threads: " << omp_get_max_threads() << endl;

//    example1_hello_world();         // hello, || world!
//    example2_ll_for();              // распараллеливание цикла
//    example3_ll_sections();
//    example4_shared_private_atomic_reduction();

    const unsigned long N = 1e9/3;
    auto t0 = chrono::system_clock::now();
    sum_l(N);
    auto t1 = chrono::system_clock::now();
    cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
              << "ms" <<endl;


    t0 = chrono::system_clock::now();
    sum_ll(N);
    t1 = chrono::system_clock::now();
    cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
              << "ms" <<endl;

//    print_array(v);

    return 0;
}


// Документация OpenMP с примерами:
// https://www.openmp.org/wp-content/uploads/openmp-examples-4.0.2.pdf
