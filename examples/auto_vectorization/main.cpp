#include <iostream>
#include <chrono>

using namespace std;
using chrono::system_clock;



int main()
{
    auto t0 = system_clock::now();


    const unsigned N = 1024*1024*512;
    double *a, *b, *c;

    a = new double[N];
    b = new double[N];
    c = new double[N];

    for (unsigned i = 0; i<N; i++)
        c[i] = a[i] * b[i];

    cout << c[random()%N];
    auto t1 = system_clock::now();
    cout << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << "ms" <<endl;

    return 0;
}


// Компиляция:
// Вариант 1, без векторизации:
// g++ main.cpp -o no_vectorization

// Вариант 2, оптимизация (включая векторизацияю):
// g++ main.cpp -o no_vectorization -O3

// Примеры приведены для linux. В Windows имя исполняемого файла компилятора отличается (см. MinGW)
// g++ main.cpp -o no_vectorization

// -O -fopt-info            -- показать все подробности об оптимизации. не покажет ничего, если оптимизация не производилась
// -fopt-info-vec           -- показать информации о векторизации циклов
// -fopt-info-vec-missed    -- показать не векторизованные операции
//-fopt-info-vec-note       -- Detailed info about all loops and optimizations being done.
//-fopt-info-vec-all        -- All previous options together.

// Больше примеров опций векторизации: https://stackoverflow.com/questions/29292818/how-to-vectorize-my-loop-with-g
//https://hpac.cs.umu.se/teaching/sem-accg-16/slides/08.Schmitz-GGC_Autovec.pdf



