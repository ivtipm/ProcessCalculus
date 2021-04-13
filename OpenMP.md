# OpenMP

OpenMP (Open Multi-Processing) — открытый стандарт для распараллеливания программ на языках Си, Си++ и Фортран.

Даёт описание совокупности директив компилятора, библиотечных процедур и переменных окружения, которые предназначены для программирования многопоточных приложений на многопроцессорных системах с общей памятью.

- Разработка стандарта ведётся некоммерческой организацией OpenMP Architecture Review Board (ARB), в которую входят все основные производители процессоров, а также ряд суперкомпьютерных лабораторий и университетов

- Поддерживается многими современными компиляторами.

- Упрощает создание потоков.

Вычисления распараллеливаются между несколькими потоками, включая основновной, master поток:
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f1/Fork_join.svg/1280px-Fork_join.svg.png)


## ***

![](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/OpenMP_language_extensions.svg/1280px-OpenMP_language_extensions.svg.png)


```
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

Пример: 


https://lms-vault.s3.amazonaws.com/private/1/courses/2016-spring/spb-hp-course/materials/Lecture_OpenMP_Summer2008_uL0moR8.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAUKOEY5ZX6VXK3RWN%2F20210413%2Feu-central-1%2Fs3%2Faws4_request&X-Amz-Date=20210413T172319Z&X-Amz-Expires=10&X-Amz-SignedHeaders=host&X-Amz-Signature=b5212372826ad3e7512514259d3f4c53e88dd07edf1bc8d1cf796bc3b8b5abd8
