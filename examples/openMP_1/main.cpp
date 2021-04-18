#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <omp.h>        // Анализатор кода Qt Creator тут может выдавать ошибку, но всё на самом деле ок
// см. также pro файл

using namespace std;
using chrono::system_clock;
using Time = decltype ( chrono::system_clock::now() );

void print_dt(Time t0){
    auto t1 = system_clock::now();
    cout << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << "ms" <<endl;}


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


// синхронизация во время работы с перемнными
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



int main()
{   // максимальное эффективное число потоков для данного компьютера
    cout << "max threads: " << omp_get_max_threads() << endl;

//    example1_hello_world();         // hello, || world!
//    example2_ll_for();              // распараллеливание цикла
//    example3_ll_sections();
//    example4_shared_private_atomic_reduction();
    example2_ll_for2();              // сравнение после и || циклов

    return 0;
}


// Документация OpenMP с примерами:
// https://www.openmp.org/wp-content/uploads/openmp-examples-4.0.2.pdf
