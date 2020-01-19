#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <chrono>

/* Условные переменные.
Позволяют блокировать один или более потоков, пока либо не будет получено уведомление от другого потока
*/

using namespace std;

typedef vector<int> vector_int;
typedef queue<int> queue_num;

mutex global_mutex;
condition_variable global_condition;


// суммирует элементы очереди и удаляет их
void sum_data(queue_num &v, double &sum){
    unsigned to_process = 10; // минимальное число элементов в очереди для обработки

    while(1){
        cout << "> sum: lock" << endl;

        // блокирует мьютекс при создании (вызове своего конструктора) и освобождает при вызове своего декструктора
        unique_lock<mutex> lock(global_mutex);

//        cout << "> sum: locked" << endl;

        if ( v.size() < to_process ){
            cout << "+ sum: waiting ..." << endl;

            // ожидает сигнала ( вызова notify_one или notify_all ) от другого потока
            // автоматически разблокирует мьютекс lock позволяя выполняться другим потокам
            global_condition.wait(lock);
        }

        cout << "+ sum: processing sum: ";
        for (unsigned i=0; i<v.size(); i++)
            {auto x = v.front();
            v.pop();
            sum += x;
            cout << x << " ";}

        cout << "sum = " << sum << endl;
        cout << endl;

    // тут мьютекс global_mutex освободится...
    }
}



// добавляет элементы в очередь
void gen_data(queue_num &v){
    v = queue_num(); // создаёт пустую очередь

    while( true ){
        this_thread::yield(); // даёт сигнал ОС о том, что можно выполнить другой поток
        // но немедленное выполнение других потоков не гарантировано

        // чтобы повысить шансы переключения на другой поток (пока текущий не захватил мьютекс)
        // тут можно просто приостановить поток на некоторое время

        unique_lock<mutex> lock(global_mutex); // создаёт обёртку для мьютекса и блокирует его

        this_thread::sleep_for(std::chrono::milliseconds(500)); // чтобы удобно было следить за выводом данных

        v.push( rand()%100 );
        cout << v.back() << " " << flush;

        if (v.size() >= 10){  // если элементов сгенерировано достаточно ...

            global_condition.notify_all(); // оповещает другие потоки (те, что вызвали wait()), что они могут разблокироваться

            cout << endl;
            cout << "> gen: notify" << endl;}

        // тут мьютекс global_mutex освободится...
    }
}





int main(){
    double sum = 0;
    queue<int> v;

    thread th_sum(sum_data, std::ref(v), std::ref(sum));
    std::this_thread::sleep_for(chrono::milliseconds(1000));

    thread th_gen(gen_data, std::ref(v));

    th_gen.join();
    th_sum.join();

    cout << endl;
    return 0;
}


// https://ru.cppreference.com/w/cpp/thread/condition_variable/wait
