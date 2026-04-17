/*
 * Задача: вычислять скалярное произведение векторов
 * X: (x1, x2, x3, ...)
 * W: (w1, w2, w3, ...)
 * Произведение = x1 * w1 + x2 * w2 + x3 * w3 + ...
 */

#include <cassert>
#include <cmath>
#include <cstddef>
#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


using namespace std;
using namespace std::chrono;

float vector_mul( const vector<float>& x, const vector<float>& y ){
    // TODO: проверить размерности векторов
    float S = 0.0;
    for ( size_t i = 0; i < x.size(); i++ ){
        S += x[i]*y[i];}
    return S;}


float vector_mul_partial( const vector<float>& x, const vector<float>& y, size_t start, size_t end ){
    // TODO: проверить размерности векторов
    float S = 0.0;
    for ( size_t i = start; i < end; i++ ){
        S += x[i]*y[i];}
    return S;}


void test(){
    float EPS = 1e-6;
    vector<float> x = {1.0, 2.0, 3.0};
    vector<float> y = {4.0, 5.0, 6.0};
    float S = vector_mul(x, y);
    assert( fabs(S - 32.0) < EPS);

    // TODO: добавить тесты
}

/// Возвращает случайный вектор длины n ...
vector<float> random_vector(size_t n){
    vector<float> v(n);
    for ( size_t i = 0; i < n; i++ ){
        v[i] = static_cast<float>(rand()) / RAND_MAX;
    }
    return v;}


int main( int argc, char* argv[] ){

    test();
    std::size_t N = std::stoull(argv[1]);

    vector<float> x = random_vector(N);
    vector<float> y = random_vector(x.size());
    float S = 0;


    // Один поток
    auto t0 = chrono::system_clock::now();
    S = vector_mul(x, y);
    auto t1 = chrono::system_clock::now();

    // P потоков
    int P = 10;
    vector<future<float> > futures;           // вектор результатов

    t0 = chrono::system_clock::now();

    size_t n;
    size_t start = 0;
    for (int i = 0; i < P; i++) {
        // количество элементов для каждого потока
        n  = x.size() / P;
        if ( i < N%P) n = n + 1;

        futures.push_back( async(std::launch::async, vector_mul_partial,   std::ref(x), std::ref(y),    start,          start + n ) );
        cout << "start = " << start << ", end = " << start + n << endl;
        start = start + n;
    }

    // получение результатов
    for (int i = 0; i < P; i++) {
        S += futures[i].get();}

    t1 = chrono::system_clock::now();

    cout << "Elapsed time: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;

}


/*
 * 2 потока
 N = 400'000'000
 Elapsed time: 3917 ms
 Elapsed time: 4207 ms
 Elapsed time: 4106 ms


 * 1 поток
 N = 400'000'000
 Elapsed time: 4225 ms
 Elapsed time: 4305 ms
 Elapsed time: 4455 ms
 *
 */
