#include <omp.h>
#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using chrono::system_clock;
using Time = decltype ( chrono::system_clock::now() );

/// Простая функция для вывода времени работы программы в миллисекундах
void print_dt(Time t0){
    auto t1 = system_clock::now();
    cout << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << "ms" <<endl;}

int main (){
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
