# ProcessCalculus
Теория вычислительных процессов

#### [Заочное. Курс 2024](plans/2024/plan-distance.md)

#### [Курс 2023](plans/2023/plan.md)

#### [Курс 2022](plans/2022/plan.md)

#### [Курс 2021](plans/2021/plan.md)

### Примерная структура курса
0. Введение в Pyhton [https://github.com/VetrovSV/Programming]
1. Верификация программ и контрактное программирование [PC_lec1.verifacation.pdf](https://github.com/ivtipm/ProcessCalculus/blob/master/PC_lec1.verifacation.pdf).
1. Стандартные схемы программ (https://cc.dvo.ru/docs/lectures-tvps/lecture02.pdf)
1. Сети Петри [1,2]
    1. Идея сети Петри. Позиция, переходы, входная и выходная функции.
    1. Маркировка и выполнение сети Петри. Диаграмма переходов.
    1. Некоторые примеры моделирования с помощью сетей Петри. простой процесс, одноканальная СМО, моделирование выполнения циклической программы.
    1. Анализ сети Петри. Свойства сетей Петри. Задача достижимости. Матричный способ решения задачи достижимости. Матрица инцидентности.
1. Параллельное программирование. [ [Computer Science Center -- Курс "Параллельное программирование"](https://compscicenter.ru/courses/hp-course/2016-spring/classes/) ]
    1. Процессы и потоки. Синхронизация потоков. Проблемы синронизации., [ [PC. lec. parallel.pdf](https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC.%20lec.%20parallel.pdf),  [ll2.md](ll2.md), [4](https://compscicenter.ru/courses/hp-course/2016-spring/classes/) ]
    1. [OpenMP](OpenMP.md)
    1. [MPI](MPI.md)
    2. [MapReduce](MapReduce.md)
    3. CUDA через pyTorch https://colab.research.google.com/drive/1qm3deqBHBP2gqRQ-WioyIiYD0I7scnhB?usp=sharing

## Примеры
- Потоки в C++: создание потоков, передача параметров по ссылке, возвращение значение из потока, callback функции [examples/example_thread](https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_thread)

- Потоки в Qt: QThread, отслеживание выполнения потока [examples/example_qthread](https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_qthread)

- Потоки в Java: создание потока, возврат значения из потока [examples/example_java_threads](https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_java_threads)

- Синхронизация с помощью ***мьютексов*** на примере потоков в С++ [examples/thread-sync1](https://github.com/ivtipm/ProcessCalculus/tree/master/examples/thread-sync1)

- Синхронизация с помощью ***условных переменных (condation variables)*** на примере потоков в С++ [examples/condition_variables](https://github.com/ivtipm/ProcessCalculus/blob/master/examples/condition_variables)

[ещё примеры](https://github.com/ivtipm/ProcessCalculus/tree/master/examples)

## Ссылки
1. Моделирование параллельных процессов. Сети Петри. Мараховский В. Б., Розенблюм Л. Я., Яковлев А. В. — СПб.:
Профессиональная литература, 2014. – 400 с

1. Теория вычислительных процессов, методическое пособие, В. Т. Калайда, 2007 г, 130 с.

1. [Сладйы лекций](https://cc.dvo.ru/uchebnaya-literatura.html) -- Голенков Е.А., Харитонов Д.И., Тарасов Г.В., Парахин Р.В. Курс лекций «Теория вычислительных процессов и структур»

1. [Computer Science Center -- Курс "Пареллельное программирование"](https://compscicenter.ru/courses/hp-course/2016-spring/classes/)
- [Симуляция сети Петри](http://petri.hp102.ru/pnet.html)
- [Построение и анализ сетей Петри](https://apo.adrian-jagusch.de/#/Sample%20Net)
- [Онлайн-доска](https://webwhiteboard.com/)
