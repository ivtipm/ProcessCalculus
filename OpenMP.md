# OpenMP

OpenMP (Open Multi-Processing) — открытый стандарт для распараллеливания программ на языках Си, Си++ и Фортран.

Даёт описание совокупности директив компилятора, библиотечных процедур и переменных окружения, которые предназначены для программирования многопоточных приложений на многопроцессорных системах с общей памятью.

- Разработка стандарта ведётся некоммерческой организацией OpenMP Architecture Review Board (ARB), в которую входят все основные производители процессоров, а также ряд суперкомпьютерных лабораторий и университетов

- Поддерживается многими современными компиляторами.

- Сильно упрощает создание потоков и распределение между ними вычислений.

Вычисления распараллеливаются между несколькими потоками, включая основновной, master поток:
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f1/Fork_join.svg/1280px-Fork_join.svg.png)


## ***

![](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/OpenMP_language_extensions.svg/1280px-OpenMP_language_extensions.svg.png)


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


#### Директивы компилятора для || вычислений
`#pragma omp ... `

Для распараллеливания вычислений:
- `parallel` 	Defines a parallel region, which is code that will be executed by multiple threads in parallel.
- `for` 	Causes the work done in a for loop inside a parallel region to be divided among threads.
- `sections` 	Identifies code sections to be divided among all threads.
- `single` 	Lets you specify that a section of code should be executed on a single thread, not necessarily the master thread.


**Общие пепеременные** -- как глобальные переменные, доступны всем потокам
```C++
#pragma omp parallel shared(A, B, C)
```

**Локальные пепеременные** -- у каждого потока своя копия переменной. Даже если переменная объявлена в общей области видимости.
```C++
#pragma omp parallel private(A, B, C)
```


#### Директивы компилятора 
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
