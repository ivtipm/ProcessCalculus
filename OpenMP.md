# OpenMP

OpenMP (Open Multi-Processing) — открытый стандарт для распараллеливания программ на языках C, C++ и Фортран.

Даёт описание совокупности директив компилятора, библиотечных процедур и переменных окружения, которые предназначены для программирования многопоточных приложений на многопроцессорных системах с общей памятью.

- Разработка стандарта ведётся некоммерческой организацией OpenMP Architecture Review Board (ARB), в которую входят все основные производители процессоров, а также ряд суперкомпьютерных лабораторий и университетов

- Поддерживается многими современными компиляторами (входит в стандартную поставку). [https://www.openmp.org/resources/openmp-compilers-tools/]

- Сильно упрощает создание потоков и распределение между ними вычислений для уже написанного кода.

- SPMD (Single Program Multiple Data) подход

- Последняя версия (на апрель 2023) - 5.2.

Вычисления распараллеливаются между несколькими потоками, включая основной (master) поток:
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f1/Fork_join.svg/1280px-Fork_join.svg.png)

Это fork-join подход к организации параллелизма.

При этом потоки могут быть логически вложенными друг в друга.

## Устройство OpenMP

OpenMP состоит из трёх компонентов:
- директивы компилятора (`#pragma omp ...`)
- переменные среды окружения (можно задавать в командной строке)\
   например.
   windows: `set OMP_NUM_THREADS = 8`\
   linux: `export OMP_NUM_THREADS = 8`
- вспомогательные (библиотечные) функции; описаны в omp.h


Логические части OpenMP

![](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/OpenMP_language_extensions.svg/1280px-OpenMP_language_extensions.svg.png)


**Структура директивы**
```C++
#pragma omp <directive-name> [опция1, опция2]
```

Такая директива влияет на следующей за ней оператор или блок операторов.

Пример. fork-join
```C++
#include <omp.h>

int main(){
  // последовательный код
  #pragma omp parallel
     {
    // параллельный код
    }
 // последовательный код

 return 0;}
```

### Компиляция программы
С++, gcc:

```bash
g++ main.cpp -fopenmp -o myprog
```
- `-fopenmp` -- флаг: подключить OpenMP и другие нужные OpenMP библиотеки (*.lib или .a файлы).
-o myprog -- имя исполняемого файла -- `myprog`


**Включить поддержку OpenMP в IDE**
- Qt Creator.
 в pro файл добавить: `QMAKE_LFLAGS +=  -fopenmp`
- Vusial Studio. Свойства проекта > С\С++ > Все параметры > поддержка OpenMP


#### Общие и локальные переменные для потоков
Все переменные, созданные до директивы parallel
являются общими для всех потоков. Переменные, созданные внутри потока являются локальными (приватными) и доступны только текущему потоку.

Общие переменные при этом не потокобезопасны:
```C++
int value = 123;

#
#pragma omp parallel
{
 value++;
 std::cout << value++ << std::endl;
}
```

Пример:
https://lms-vault.s3.amazonaws.com/private/1/courses/2016-spring/spb-hp-course/materials/Lecture_OpenMP_Summer2008_uL0moR8.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAUKOEY5ZX6VXK3RWN%2F20210413%2Feu-central-1%2Fs3%2Faws4_request&X-Amz-Date=20210413T172319Z&X-Amz-Expires=10&X-Amz-SignedHeaders=host&X-Amz-Signature=b5212372826ad3e7512514259d3f4c53e88dd07edf1bc8d1cf796bc3b8b5abd8


### Директивы компилятора для || вычислений
`#pragma omp ... `

Для распараллеливания вычислений:
- `parallel` 	Defines a parallel region, which is code that will be executed by multiple threads in parallel.
- `for` 	Causes the work done in a for loop inside a parallel region to be divided among threads.
- `sections` 	Identifies code sections to be divided among all threads.
- `single` 	Lets you specify that a section of code should be executed on a single thread, not necessarily the master thread.

#### parallel
```C++
#pragma omp parallel
```
Требования к || учатску кода
- один вход, один выход. Условные переходы из\в || участка кода в последовательный запрещены.

- внутри || участка кода может быть вызвана функция

Явное задание числа потоков \
   ```... num_thread( 12 )```

Задать число потоков можно с помощью:
- переменной среды окрыжения `OMP_NUM_THREADS`. Это значение имеет низший приоритет.
- функции `omp_set_num_threads()`. Средний приоритет.
- директивы `num_thread ( )`. Высший приоритет, но только для последующей || области

#### Вложенный параллелизм
По умолчанию

Разрешить вложенный параллелизм :
- переменная среды окружения: `OMP_NESTED = true`
- функция `omp_set_nested( true )`


##### См. также
- условный параллелизм
```С++
#pragma omp parallel if ( x > 5)
```


#### single
Задаёт участок кода, который будет выполнятся только одним потоком (не известно каким). single имеет смысл приводить только внутри блока кода parallel

В конце single блока используется неявная *барьерная синхронизация* -- все потоки будут ждать

Опции:
- `copyprivate( список переменных )`
После завершения, скопирует значения переменных в одноимённые частные переменные родительской параллельной области. Полезно использовать в середине || области, где встречаются вычисления, которые нельзя распараллелить.

- `nowait`


#### master
Выполнится главным потоком. В отличии от single нет будет неявной синхронизации потоков.

### Разделеное и совместное использование перемеренных
- **Общие переменные** -- как глобальные переменные, доступны всем потокам. Все переменные, объявленные вне || области считаются общими. Исключения -- счётчики циклов.

```C++
#pragma omp parallel shared(A, B, C)
```
Не защищены от неопределённости параллелизма.

- **Локальные переменные** -- у каждого потока своя копия переменной. Даже если переменная объявлена в общей области видимости. Начальное значение переменной не определено. Все переменные объявленные в || области считаются локальными.
```C++
int A = -1, b;
#pragma omp parallel private(A, b)
{
 A = rand();
 printf("A = %d\n", A);    // будет выведено несколько (по числу потоков) значений
}

 printf("A = %d\n", A);  // будет выведено -1
```

**см. также `firstprivate`, `lastprivate`,

**reduction (операция : список переменных)**
- создаёт инициализированные копии глобальной переменной в каждом потоке
- в конце || секции выполняется указанная операция с локальными копиями, результат записывается в исходные глобальные переменные

#### Директивы компилятора для синхронизации
For master and synchronization:

- `master` 	Specifies that only the master thread should execute a section of the program.

- `critical` 	Specifies that code is only executed on one thread at a time.

- `barrier` 	Synchronizes all threads in a team; all threads pause at the barrier, until all threads execute the barrier.

- `atomic` 	Specifies that a memory location that will be updated atomically.

- `flush` 	Specifies that all threads have the same view of memory for all shared objects.

- `ordered` 	Specifies that code under a parallelized for loop should be executed like a sequential loop.

For data environment:
- `threadprivate` 	Specifies that a variable is private to a thread.

https://docs.microsoft.com/ru-ru/cpp/parallel/openmp/reference/openmp-directives?view=msvc-160



## Векторизация
**Векторизация** — вид распараллеливания программы, при котором однопоточные приложения, выполняющие одну операцию в каждый момент времени, модифицируются для выполнения нескольких однотипных операций одновременно.


```C++
for (i=0; i<n; i++)
   c[i] = a[i] + b[i];
```
Если оператор сложения имеет перегруженную векторную форму, то код можно переписать так:
```C++
c = a + b;
```
Однако, чаще всего такое сложение массивов можно векторизовать частными сложениями отдельных блоков массивов (например по 4 элемента).


- современные компиляторы (с включёнными опциями оптимизации) могут поддерживать автоматическую векторизация.
- автоматическая векторизация может происходить и во время выполнения программы


*Векторные операции в процессоре*
- набор инструкций SSE процессоров intel
- набор инструкций 3DNow! в процессорах AMD

Процессоры поддерживающие векторные операции (все современный процессоры) хранят данные в *векторных регистрах*.

#### Пример
[Пример](examples/auto_vectorization)

Компиляция примера:

| команда компиляции             | время выполнения программы |
|--------------------------------|----------------------------|
| `g++ main.cpp -o main-novec`     | 3536 ms                    |
| `g++ main.cpp -o main-vec   -O3` | 1597 ms                    |

   Компиляция с отчётом о векторизации цислов:\
   `g++ main.cpp -o main-vec -O3 -fopt-info-vec`\
   Вывод:\
   `main.cpp:21:27: optimized: loop vectorized using 16 byte vectors`


Комнады компиляция приведены для linux, С++ компилятора GCC. В Windows имя исполняемого файла аналогичного компилятора отличается (см. MinGW)

Флаги коппилятора, связанные с векторизацией:
- `-O -fopt-info`             -- показать все подробности об оптимизации. не покажет ничего, если оптимизация не производилась
- `-fopt-info-vec`            -- показать информации о векторизации циклов
- `-fopt-info-vec-missed`     -- показать не векторизованные операции
- `-fopt-info-vec-note`       -- Detailed info about all loops and optimizations being done.
- `-fopt-info-vec-all`        -- All previous options together.

Опции оптимизации C++ компилятора GCC:\
![](img/gcc-ox.png)

https://stackoverflow.com/questions/29292818/how-to-vectorize-my-loop-with-g

Документация об оптимизации GCC: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

**Оптимизация кода в Microsoft Visual C++**: Свойства проекта > раздел С\С++ > оптимизация\
**Передача опций компилятору (GCC) в Qt Creator**: в pro-файле проекта добавить: `QMAKE_CFLAGS += -O3`


#### pragma ivdep, vector always
```#pragma ivdep```\
ivdep – ignore vector dependencies. Изменяет способ принятия решения о возможности векторизации данного цикла: компилятор по-прежнему анализирует все возможные зависимости между данными, но недоказанные зависимости не принимаются во внимание (считаются несуществующими). Таким образом, если существование зависимости доказано, то векторизация произведена не будет, но все недоказанные зависимости более не будут препятствием для векторизации.


Пример рискованной, с точки зрения компилятора векторизации цикла:
```
void sum(float *a, float b*, float *c, float *d, float *e, unsigned n){
 for (unsigned i =0; i<n; i++)
   a[i] = a[i] + b[i] + c[i] + d[i] + c[i];
}
```

В ряде случаев компилятор может счесть, что векторизация возможна, но для данного цикла неэффективна. Если же программист считает, что векторизация все равно будет эффективна, можно дать соответствующую рекомендацию компилятору при помощи `#pragma vector always`. Часто #pragma ivdep и #pragma vector always используются вместе. Важно отметить, что #pragma vector always является лишь рекомендацией и в случае обнаружения зависимости или наличия других веских причин векторизация все равно произведена не будет.

`#pragma simd`
Дает компилятору явное указание произвести векторизацию данного цикла


### pragma omp simd
- то же самое, что и `#pragma simd`, но включённое в стандарт OpenMP


**Опции**
- `safelen( целая константа )` -- задаёт максимальное расстояние (в итерациях) между итерациями, которые могут выполняться параллельно

```C++
...
#pragma omp simd safelen(8)
for (unsigned i=8; i<n; i++){
 a[i] = a[i-8]
}
```


- `simdlen ( число )` -- предпочтительное число || выполняющихся итераций

- `alignment (список, целое число)`

- `linear ( переменная : положительное число)`


*Ограничения*
Если в цикле вызывается функция, то в общем случае этот цикл не векторизуется. Чтобы избежать этого, отдельные функция можно сделать векторизуемыми

```C++
#pragma omp declare simd
float sum(float a, float b){return a+b;}

#pragma omp simd
for (unsigned i=0; i<n; i++)
 c[i] = sum(a[i], b[i]);
```


## task

Один поток генерирует задачи, другие -- выполняют, подход похожий на пулл потоков

Задача может выполнятся немедленно или спустя некоторое время после её назначения потоку.
Выполнение задачи может быть прервано, а потом продолженно.

Опции:
- shared
- private
- firstprivate
- default
- if
- untied. Если задача была начата одним потоком, то может быть продолженна любым другим потоком. По умолчанию, отложенная задача выполняется тем же потоком, что начинал её выполнение.

**Пример**

Обход списка с выполенением длительных операций над каждым элементом
```C++
#pragma omp parallel
{
    // выдавать задачи должен выдавать один поток. он же будет обходить список
    // nowait -- отключить барьерную синхронизацию
    #pragma omp single nowait
    {
      node = list_head;
      while (node){
        // создание задачи, которую будет выполнять другие потоки
        // firstprivate -- создание локальной копии переменной в каждом отдельном потоке, выполнящем каждую одельную задачу.
        // локальная для потока переменная будет инициализирована значением глобальной переменной node
        #pragma omp task firstprivate(node)
        {
            independent_work( node );
        }
        node = node->next;    
      }

    }


}
```

- В чём разница между parallel и task?
- В чём разница между section и task?


#### Дополнительно
Больше примеров опций векторизации:
- https://stackoverflow.com/questions/29292818/how-to-vectorize-my-loop-with-g
- https://hpac.cs.umu.se/teaching/sem-accg-16/slides/08.Schmitz-GGC_Autovec.pdf


## См. также
`#pragma omp traget`


```C++
#pragma omptarget map(to:b,c,d) map(from:a)
// перед циклом переместит переменные b,c,d на отдельное устройтво,
// после цикла переместит переменную a с устройства
//
{
 #pragma omp parallel for
   for (i=0; i<count; i++) {
     a[i] = b[i] * c + d;}
}
```


# Ссылки
- https://www.openmp.org//
- https://www.coursera.org/learn/parallelnoye-programmirovaniye/home/welcome
