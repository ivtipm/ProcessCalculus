#include <math.h>
#include <iostream>

#include <thread>  // ещё нужно подключить скомпилированый код библиотеки. см. pro файл: LIBS += -lpthread
#include <future>

// для предачи функции как параметра
#include <functional>

#include <chrono>

// для использования std::thread нужно дополнительно указать
// что к проекту должна быть присоединена библиотека pthread
// в файле пректа: LIBS += -lpthread


using namespace std;


// функции, которые будут выполнятся в отдельных потоках
void foo(unsigned long n, char c){
    // с - символ обозначающий 10% прогресса
    unsigned long d = n/10;
    double sum = 0;
    for (unsigned i = 0; i<n; i++){
     sum += sin(i);
     if (i%d==0) {cout << c;
               cout << flush;}}
}


// плохой пример использования общей переменной
void bar_not_safe1(unsigned long n, double &sum){

    unsigned long d = n/10;
    for (unsigned i = 0; i<n; i++){
     sum += sin(i);                                                                                 // если несколько потоков используют переменную sum. возникает неопределённость пареллелизма
     if (i%d==0) {cout << '*';
        cout << flush;}}
}

// плохой пример использования общей переменной
void bar_not_safe2(unsigned long n, long long &sum){
    unsigned long d = n/10;
    for (unsigned i = 0; i<n; i++){
     sum = sum+1;}                                                                                     // если несколько потоков используют переменную sum. возникает неопределённость пареллелизма
}




const unsigned long N = 300000000; // число слагаемых

// Простой пример запуска функции в отдельном потоке
void example1(){
    auto t0 = chrono::system_clock::now(); // запомним текущее время, для вычисления времени работы

     // поток - это тоже класс std::thread
     // первый параметр - фказатель на функцию
     // остальные - параметры функции

     // потоки запускаются сразу после создания объекта (если в конструктор был передан указатель на функцию)
     // два вызова функции foo будут выполнены параллельно
     std::thread th1(foo, N, '|');
     std::thread th2(foo, N, '.');


     // ожидание завершения первого, _затем_ второго потока
     th1.join();
     th2.join();
     // см. также detach

     // если не ожидать завершения потоков,
     // то они могут быть завершены раньше времени автоматически
     // в момент, когда завершится основной поток программы

     auto t1 = chrono::system_clock::now();
     cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
          << "ms" <<endl;

     cout << endl;
}


// Плохой пример запуска потока
void example1_1_bad(){
     std::thread th1(foo, N, '|');
     // почти наверняка текущая функция завершится раньше, чем функция потока
     // при завещении текущей функции будет уничтожен объект th1,
     // что приведёт к аварийному завершению потока: terminate called without an active exception
}



// Хороший пример запуска потока
void example1_1_good(){
     std::thread th1(foo, N, '|');
     // отсоединение потока от объекта th1
     // теперь уничтожение th1 не приведёт к аварийному завершению потока
     th1.detach();
     // но теперь нужно проследить чтобы основной поток не завершился раньше вновь созданного
    cout << "is joinable: " << th1.joinable() << endl;
     // https://en.cppreference.com/w/cpp/thread/thread/detach
}


// Пример 2: передача данных в поток по ссылке
void example2(){
    auto t0 = chrono::system_clock::now();
    double sum=0;
    // Передача переменных в функцию потока _всегда_ происходит по значению
    // даже если передаётся ссылка.
    // Поэтому большие данные или данные, которые нужно изменить внутри функции
    // нужно передавать с помощью специальных типов cref или ref.
    std::thread th3(bar_not_safe1, N, std::ref(sum));

    // ...

    th3.join();
    cout << endl << "sum = " << sum << endl;
    auto t1 = chrono::system_clock::now();
    cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
      << "ms" <<endl;
}

// пример состояния гонки
void example2_1(){
    long long s;
    std::thread th1(bar_not_safe2, 100000000, std::ref(s));
    std::thread th2(bar_not_safe2, 100000000, std::ref(s));

    // здесь вызывается join только для того,
    // чтобы основной поток не завершился раньше вновь созданного
    th1.join();
    th2.join();
    cout << s;
}


// функция потока, которая возвращает значение
float baz(unsigned long n){
    unsigned long d = n/10;
    float sum = 0;
    for (unsigned i = 0; i<n; i++){
     sum += sin(i);
     if (i%d==0) {cout << '.';
               cout << flush;}}
    return sum;
}


// пример 3: получение данных из потока
void example3(){

    std::future< float > result;  // объект для хранения результатов асинхронных вычислений
    result = std::async( baz, N );  // запуск функции в отдельном потоке

    // ... тут должно быть выполнение какой-то своей работы ...

    result.wait();                              // блокирующее ожидание завершения потока
    cout << "\nsum = " << result.get() << endl; // получение и вывод результата
}


// пример 3: получение данных из потока
void example3_1(){

    std::future< float > result;  // объект для хранения результатов асинхронных вычислений
    result = std::async( baz, N );  // запуск функции в отдельном потоке

    float sum = 0;
    int d = N/20;
    for (unsigned i = 0; i<N; i++){
        if ( result.valid() ){
            cout << "\n" << "второй поток вернул результат: " << result.get() << endl;
        }
        sum += sin(i);
        if (i % N == 0) cout << ".";
    }

//    result.wait();                              // блокирующее ожидание завершения потока
    cout << "\nsum = " << result.get() << endl; // получение и вывод результата
}


// функция потока, которая вызывает другую функцию после завершения основной работы
// в основном потоке больше не нужно ждать пока эта функция завершит вычисления, чтобы показать данные
// вместо этого функция потока сама покажет данные, пока основной поток занят другими действями
void bar2(unsigned n, void(*callback)(float s)  ){
    // указатель на функцию можено передавать и через класс-обёртку std::function
    float sum = 0;
    for (unsigned i = 0; i<n; i++)
     sum += sin(i);

    callback(sum);
}


// используется как callback функция
void bar2_done(float sum){
    // cout потокобезопасен только на уровне символов
    cout << "sum = " << sum << endl;
}


// Пример 4: Вызов callback функции из потока
void example4(){
    // Если по завершении потока нужно выполнить определённое действие,
    // при этом не дожидаясь завершения этого нового потока в основном (не использую join)
    // то в цункцию можно передать адрес другой функции, которая и выполнит необхоимые действия
    unsigned n = 1000;
    std::thread th(bar2, n, bar2_done);

    // здесь вызывается join только для того,
    // чтобы основной поток не завершился раньше вновь созданного
    th.join();
}




int main(){

     cout << "supported number of threads: " << thread::hardware_concurrency() << endl;

    example1();  // Пример 1: запуск функции в отдельном потоке
//    example1_1_bad();  // Как не нужно создавать поток в локальной оласти видимости
//    example1_1_good(); // Как нужно создавать поток в локальной области видимости
//    example2();  // Пример 2: передача данных в поток по ссылке
//     example2_1();
//    example3();  // Пример 3: получение данных из потока
//      example3_1();  // Пример 3: получение данных из потока
//    example4();  // Пример 4: Вызов callback функции


    return 0;
}


// https://habr.com/post/182610/

// https://en.cppreference.com/w/cpp/thread
// см. также функции
// yield
// get_id
// sleep_for


// не равмотренные темы:
// использование функторов
