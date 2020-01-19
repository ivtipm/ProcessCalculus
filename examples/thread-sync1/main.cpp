#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

/* Синхронизация потоков при общем доступе для записи в переменную */

int shared_var = 0;

void foo_no_sync(){
    this_thread::sleep_for(chrono::milliseconds(rand()%10));

    for (unsigned i =0; i<100;i++) {
        shared_var++;
    }
}

mutex mtx;

void foo_sync(){
    this_thread::sleep_for(chrono::milliseconds(rand()%10));

    // поток блокирует (отмечает) мьютекс.
    // Остальные потоки будут ждать в строке ниже
    mtx.lock();


    // Мьютекс заблокирован. Никто не помешает изменять переменную.
    for (unsigned i =0; i<100;i++) {
        shared_var++;
    }

    // работа с переменной завершена, освободим
    mtx.unlock();
}


int main()
{
    unsigned Nth = 10000; // количество потоков
    vector<thread> threads_poll(Nth);

    cout << "Starting " << Nth << " threads" << endl;

    for (unsigned i = 0; i < Nth; i++){
//        threads_poll[i] = thread(foo_no_sync); // изменение переменной без синхронизации
        threads_poll[i] = thread(foo_sync);      // изменение переменной с синхронизацией
    }

    cout << "waiting for threads termination..." << endl;
    for(unsigned i = 0; i < Nth; i++){
        threads_poll[i].join();
    }

    cout << "shared_var = " << shared_var << endl;

    return 0;
}

// см. так же: метод try_lock - если мьютекс не принадлежит никакому потоку, тогда поток,
// вызвавший try_lock, становится его обладателем и метод возвращает true. В противном случае возвращает false.
// try_lock не блокирует текущий поток.


// см. еще один пример использования мьютекса в документации стандартной библиотеки:
// http://www.cplusplus.com/reference/mutex/mutex/
