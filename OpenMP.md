# OpenMP

OpenMP (Open Multi-Processing) — открытый стандарт для распараллеливания программ на языках Си, Си++ и Фортран.

Даёт описание совокупности директив компилятора, библиотечных процедур и переменных окружения, которые предназначены для программирования многопоточных приложений на многопроцессорных системах с общей памятью.

- Разработка стандарта ведётся некоммерческой организацией OpenMP Architecture Review Board (ARB), в которую входят все основные производители процессоров, а также ряд суперкомпьютерных лабораторий и университетов

- Поддерживается многими современными компиляторами (входит в стандартную поставку).

- Сильно упрощает создание потоков и распределение между ними вычислений для уже написанного кода.

- SPMD (Single Program Multiple Data) подход

- Последняя версия (на апрель 2012) - 5.2.

Вычисления распараллеливаются между несколькими потоками, включая основновной, master поток:
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f1/Fork_join.svg/1280px-Fork_join.svg.png)

Это fork-join подход к организации параллелизма.

При этом потоки могут быть логически сложенными друг в друга.

## Устройство OpenMP

OpenMP состоит из трёъ компонентов:
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

Такая директива влияет на следюющей за ней оператор или блок операторов.

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
- один вход, один выход. Условные переходы из\в || учатска кода в последовательный запрещены.

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

В конце single блока используется неявная *барьераная синхронизация*.

Опции:
- `copyprivate( список переменных )`
После заверешния, скопирует значения переменных в одноимённые частные переменные родительской параллельной области
- `nowait`


#### master
Выполнится главным потоком. В отличии от single нет будет неявной синзронизации потоков.

### Разделеное и совместное использование пермеременных
- **Общие пепеременные** -- как глобальные переменные, доступны всем потокам. Все переменные, объявленные вне || области считаются общими. Исключения -- счётчики циклов.

```C++
#pragma omp parallel shared(A, B, C)
```
Не защищены от неопределённости параллелизма.

- **Локальные пепеременные** -- у каждого потока своя копия переменной. Даже если переменная объявлена в общей области видимости. Начальное значение переменной не определено. Все переменнеы объявленные в || области считаются локальными.
```C++
int A = -1, b;
#pragma omp parallel private(A, b)
{
  A = rand();
  printf("A = %d\n", A);    // будет выведно несколько (по числу потоков) значений
}

  printf("A = %d\n", A);  // будет выведено -1
```

**см. также `firstprivate`, `lastprivate`,

**reduction (операция : список перменных)**
- создаёт инициализированные копии глобальной переменной в каждом потоке
- в конце || секции выполняется указанная операция с локальными копиями, результат записывается в исходные глобальные переменные

#### Директивы компилятора для синхронизации
For master and synchronization:

`master` 	Specifies that only the master thread should execute a section of the program.
`critical` 	Specifies that code is only executed on one thread at a time.
`barrier` 	Synchronizes all threads in a team; all threads pause at the barrier, until all threads execute the barrier.
`atomic` 	Specifies that a memory location that will be updated atomically.
`flush` 	Specifies that all threads have the same view of memory for all shared objects.
`ordered` 	Specifies that code under a parallelized for loop should be executed like a sequential loop.

For data environment:
`threadprivate` 	Specifies that a variable is private to a thread.

https://docs.microsoft.com/ru-ru/cpp/parallel/openmp/reference/openmp-directives?view=msvc-160

# Ссылки
- https://www.openmp.org//
- https://www.coursera.org/learn/parallelnoye-programmirovaniye/home/welcome
