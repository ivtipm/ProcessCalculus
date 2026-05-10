#include <cassert>
#include <cstddef>
#include <math.h>

#include <iostream>
#include <format>
#include <stdexcept>
#include <vector>

#include <assert.h>
#include <omp.h>

using namespace std;


int main(){
  const size_t N = 300'000'000;

  float *v1 = new float[N];
  float *v2 = new float[N];

  for (size_t i = 0; i < N; i++){
    v1[i] = rand() % 1000 / 1000.0;
    v2[i] = rand() % 1000 / 1000.0;
  }
  // TODO: заполнить массивы

  float r[2] = {0,0};
  auto t0 = omp_get_wtime();
  #pragma omp parallel
     {
         int pi = omp_get_thread_num();         // номер текущего потока

         size_t start = 0, end = N;
         if ( omp_get_num_threads() == 2 ) {
            if (pi == 0) { start = 0;     end = N / 2; }
            else         { start = N / 2; end = N;     }
         }

         cout << format("Thread {} processes {:14d} to {:14d}\n", pi, start, end);
         for (size_t i = start; i<end; i++)
             r[ pi ] += sin(v1[i])*cos(v1[i]) * sin(v2[i])*sqrt(abs(v2[i]));
     }
        auto t1 = omp_get_wtime();
        cout << format("Time: {:.4f} s\n", t1 - t0);


 cout << "R = " << r[0] + r[1] << "\n";

 return 0;}
/*
// Компиляция
g++ hw.cpp -fopenmp -o hw --std=c++20

export OMP_NUM_THREADS=1
time ./hw
Thread 0 processes              0 to      300000000
Time: 13.0999 s
R = 8.38861e+06
./hw  20.63s user 1.27s system 99% cpu 21.982 total


export OMP_NUM_THREADS=2
time ./hw
Thread 0 processes              0 to      150000000
Thread 1 processes      150000000 to      300000000
Time: 6.1537 s
R = 1.67772e+07
./hw  15.34s user 0.75s system 160% cpu 10.018 total

*/
