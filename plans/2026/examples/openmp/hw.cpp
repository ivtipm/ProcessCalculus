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
  #pragma omp parallel
     {
         int pi = omp_get_thread_num();

         size_t start = 0, end = N;
         if ( omp_get_num_threads() == 2 ) {
            if (pi == 0) { start = 0;     end = N / 2; }
            else         { start = N / 2; end = N;     }
         }

         cout << format("Thread {} processes {} to {}\n", pi, start, end);
         for (int i = start; i<end; i++)
             r[ pi ] += sin(v1[i]) * sin(v2[i]);
     }

 cout << "R = " << r[0] + r[1] << "\n";

 return 0;}
