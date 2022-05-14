## Занятие 12. Параллельное программирование
## Не расмотренные темы
- Условные переменные (condidtional variables)
  - [Пример](examples/condition_variables/main.cpp)
- Синхронизация процессов
  - [примеры на python](examples/process_python)
- OpenCL
- Intel TBB
- [MPI](MPI.md)
  - [Пример](examples/MPI-pi-monte-carlo/main.cpp)
- CUDA
- Оптимизация кода компиляторами. Векторизация.
  - [Пример](examples/auto_vectorization/main.cpp)
- [MapReduce](MapReduce.md)
- Пулы потоков
  - [Пример на Java](examples/threads_pool_java/src/com/company)
- Паттерны параллельного программирования
  

<br>

## Занятие 11. Параллельное программирование
- Мьютексы?
  - (Пример на C++)[examples/thread-sync1/main.cpp]
- [OpenMP](OpenMP.md)
  - [Пример 1](examples/MPI/main.cpp)
  - [Пример 2](examples/openMP_1/main.cpp)
- CUDA + pyTorch в Google Colaboratory

### Домашнее задание
- сравните скорость вычислений numpy и pytorch в google colaboratory
- https://github.com/ivtipm/ProcessCalculus/blob/master/examples/performance_and_mem.cpp (см. вопросы в конце программы)
- _Бонус_: CUDA
  - Решите сложную вычислительную задачу
- _Бонус_: OpenMP
  - создайте параллельный алгоритм решения задачи 5 из задания 1
  - решите сложную вычислительную задачу с помошью параллельного алгоритма
- _Бонус_: MPI
  - решите сложную вычислительную задачу с помошью параллельного алгоритма
- _Бонус_: Карта знаний курса ТВП


## Занятие 10. Параллельное программирование
апрель 18
- Повторение. Опрос.
 - Потоки в C++ (продолжение)
   - https://github.com/ivtipm/ProcessCalculus/blob/master/examples/example_thread/main.cpp
- Потоки в Qt:
   - https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_qthread
- Потоки в Java:
   - https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_java_threads
   - https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_java_thread-gui
   -
- Синхронизация потоков.
- https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC.%20lec.%20parallel.pdf


## Занятие 10. Параллельное программирование
апрель 18
- Повторение. Опрос.
- Вилы декомпозиции. Распределение работы по потокам\процессам.
- Атомарность. Потокобезопасность.
- Проблемы || вычислений
   - неопределённость параллелизма
   - взаимноя блокировка
   - проблема ABA
   - Потоки в C++
      - https://github.com/ivtipm/ProcessCalculus/blob/master/examples/example_thread/main.cpp
- https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC.%20lec.%20parallel.pdf


### Домашнее задание

- Скачайте книгу по паралельному программированию для вашего любимого языка
- Конспект. Потоки в вашем любимом языке программирования
   - Создание, остановка, ожидание потока и др. операции.
   - Передача данных в поток (по ссылке и по значению). Получение данных их потока.
   - Создание классов для вычислений в отдельном потоке
- Создайте программу с графическим интерфесом пользователя. Программа должна решить сложную вычислительную задачу, выполненеи которой занимает как минимум несколько секунд. Программа должна запускать вычисления в текущем потоке и в отдельном потоке. Останавливать вычисления в отдельном потоке. Выводить прогресс вычислений и результат.
- Распределение работы среди множества потоков.

<br>

## Занятие 9. Сети Петри. Параллельное программирование
апрель 11
- Повторение, опрос.
- Сети Петри (продолжение)
   - https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC_lec_Petri_Net.pdf
- Параллельное программирование
   - Асинхронность и синхронность; concurency vs parallelism   
   - Классификация Флина
   - Системы с общей и раздельной паматью
   - https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC.%20lec.%20parallel.pdf

#### Домашнее задание
- Изучите динамические свойства сети Петри из своего варианта.
- Получите четыре новых маркировки сети Петри используя вектор из числа срабатываний и матрицу инцидентности. Используйте заданную в передыдущем задании маркировку.
- Дополнительно: создайте веб-сервис для создания сети Петри. С возможностями
   - Рисование графа сети Петри
   - Создание матрицы инцидентности по графу
   - Создание описания сети Петри по четвёрке: (P,T,I,O)
   - Запуск отдельных переходов
   - Построение диаграммы переходов
   - Задание можно выполнять в парах

### Источники
- Computer Science Center -- Курс "Пареллельное программирование"
<br>
- https://habr.com/ru/company/intel/blog/243385/ -- Процессоры, ядра и потоки. Топология систем

## Занятие 8. Сети Петри
апрель 4
- Повторение, опрос.
- Сети Петри (продолжение)
- https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC_lec_Petri_Net.pdf


### Домашнее задание
- Пункт 3 из задания
https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/%D0%97%D0%B0%D0%B4%D0%B0%D0%B8%D0%B5.%20%D0%A1%D0%B5%D1%82%D1%8C%20%D0%9F%D0%B5%D1%82%D1%80%D0%B8.pdf
- Постройте граф переходов для придуманной на прошлом занятии маркировки


## Занятие 7. Сети Петри
март 28
- Повторение, опрос.
- Сети Петри
- https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/PC_lec_Petri_Net.pdf

### Дополнительно
- https://ru.wikipedia.org/wiki/%D0%90%D0%B1%D1%81%D1%82%D1%80%D0%B0%D0%BA%D1%82%D0%BD%D1%8B%D0%B9_%D0%B0%D0%B2%D1%82%D0%BE%D0%BC%D0%B0%D1%82 -- Абстрактный автомат
- http://is.ifmo.ru/books/_book.pdf -- Автоматное программирование А. А. Шалыто

### Домашнее задание
- Пункты 1 и 2 из задания
https://raw.githubusercontent.com/ivtipm/ProcessCalculus/master/%D0%97%D0%B0%D0%B4%D0%B0%D0%B8%D0%B5.%20%D0%A1%D0%B5%D1%82%D1%8C%20%D0%9F%D0%B5%D1%82%D1%80%D0%B8.pdf
- Подберите начальную маркировку, для которой можно запустить переходы минимум три раза


## Занятие 6. Схемы
март 21
- Повторение, опрос.
- Верификация программ; вывод предусловий
- Схемы программ
   - сложность синтаксическог анализа и неопределённое поведение (undefined behavior)

```         
           // Примеры на С++
           int foo() {}   // что вернёт функция?

           int arr[4] = {0, 1, 2, 3};
           arr[4];        // что записано по этому адресу?

           i = 1;
           i++ + i++      // чему равно i?      
```
   - https://cc.dvo.ru/docs/lectures-tvps/lecture02.pdf

#### Домашнее задание
- Конспект:
    - запуск программ на python в консоли; как сделать интерпретатор доступным из консоли?
    - pip
    - настройка вашего любимого текстового редактора для удобного запуска программ на python
    - upd: проделайте все операции из конспекта (настройки переменных окружения, запуск программы в консоли, установка библиотек)
      - сделайте отчёт
- Опишите схему программы 4 из первого задания


#### Литература
1. [Computer Science Center -- Курс "Пареллельное программирование"](https://compscicenter.ru/courses/hp-course/2016-spring/classes/)


## Лекция 5. Верификация
март 14
- Верификация программ
    - формальная верификация; тройка Хоара; вывод слабейшего предусловия
    - контрактное программирование
    - https://github.com/ivtipm/ProcessCalculus/blob/master/PC_lec1.verifacation.pdf

#### Домашнее задание
- Конспект: инспекция кода; статические анализаторы кода
    - Выясните, какие статические анализаторы кода существуют для ваших любимых языков программирования. Используйте хотя бы один их них. Составьте короткий отчёт.
    - *Рекомендуется оформить конспект и отчёт в markdown и загрузить в репозиторий. Можно оформить это в текстовом документе.*

#### Литература
1. А. С. Камкин. Введение в формальные методы верификации программ. 2018

<br>

## Лекция 4. Numpy. Classes.
февраль 28

- Слайды:
    - https://raw.githubusercontent.com/VetrovSV/Programming/master/Python_math.pdf
    - https://github.com/VetrovSV/Programming/blob/master/Programming_14_data_structures.pdf

Пример:
https://colab.research.google.com/drive/1xgjjvDtmcw__xYZtFa0t0InogMcANeQp?usp=sharing


### Практика
Защита работ

#### Домашнее задание




## Лекция 3
февраль 21
- Python.
    - Повторение.
    - Модули. Установка. Создание; Компиляция; Добавление путей; `__main__`; virtual enviroment
    - matplotlib. numpy. scipy
    - Классы. Поля и методы; конструктор; операторы; наследование; сокрытие; функции как объекты;
    - файлы
- Слайды:
    - https://github.com/VetrovSV/Programming/blob/master/Programming_13_modules.pdf
    - https://github.com/VetrovSV/Programming/blob/master/Programming_14_data_structures.pdf


#### Домашнее задание
1. Создайте интеллект-карту или систематизируйте в виде другой диаграммы темы и понятия из языка программирования Python
    - сайты для создания диаграмм: (miro.com, draw.io)
2. Python    
   - создать случайную матрицу numpy array
   - решить СЛАУ (numpy)
   - построить тепловую карту на основе созданной матрицы
   - превратть матрицу в массив, построить гистограмму (seaborn)
   - построить график любой сложной функции. построить график этой же функции с добавлением шума (numpy, matplotlib); не забудьте подпис к подписи к осям, заголовок графика, легенду, координатную сетку
   - *дополнительно*: вычислите среднее значение элемента в матрицах реализованых через список и numpy array; сравните время вычисления
   - *дополнительно*: постройте графики выявленых заражений COVID-19 и смертности для нескольких стран
        - данные https://data.humdata.org/dataset/coronavirus-covid-19-cases-and-deaths
        - подсказка: используте библиотеку pandas
3. Конспект. Документирование

### Практика
Защита работ

## Лекция 2
февраль 14
- доклады
- Python.
    - Повторение.
    - Анонимные функции. map, zip, enumerate
    - Параметры-ссылки и параметры-значения.
- см. примеры в Discord и miro
- Слайды:
    - https://github.com/VetrovSV/Programming/blob/master/Programming_11_func1.pdf
    - https://github.com/VetrovSV/Programming/blob/master/Programming_12_func2.pdf
    - https://github.com/VetrovSV/Programming/blob/master/Programming_09.pdf
    - https://github.com/VetrovSV/Programming/blob/master/Programming_14_data_structures.pdf



### Практика 2
Защита работ


#### Дополнительно
- https://colab.research.google.com - Google Colab - виратульная машина с IDE Jupyter Notebook
- Python для сложных задач: наука о данных и машинное обучение. — СПб.: Питер, 2018. — 576 с
- O‘Conor T.J. Violent Python: A Cookbook for Hackers, Forensic Analysts, Penetration Testers and Security Engineers. 2012 — 288 p.
- Numerical methods in engineering with Python 3 / Jaan Kiusalaas

<br/><br/>

## Лекция 1
февраль 07
- Python. Особенности. IDE Pycharm. Типы данных. Операторы. Функции
- Файлы со слайдами 1-5:
    - https://github.com/VetrovSV/Programming
- примеры и материалы: https://miro.com/app/board/uXjVORmoCO0=/?invite_link_id=993701359201


### Практика 1

**Python** -- язык программирования общего назначения с большой коллекцией библиотек написанных на разных языках программирования.
Благодаря этому и ориентации языка на продуктивность разработка Python широко используется для научных вычислений и визуализации данных.
Библиотеки для математических вычислений скомпилированы и содержат оптимизированный код. Некоторые библиотеки дают доступ к распараллеливанию вычислений на GPU.


В течении курса Python будет использоваться для вычислений на GPU и визуализации.

#### Домашнее задание
Для того чтобы освоить базовые элементы синтаксиса языка программирования решите несколько задач.
<table>
<thead>
  <tr>
    <th rowspan="2">Тема</th>
    <th rowspan="2">№</th>
    <th colspan="10">Вариант</th>
  </tr>
  <tr>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
    <th>9</th>
    <th>10</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>Арифметика действительных чисел</td>
    <th>1</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z1">1</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z2">2</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z3">3</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z4">4</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z5">5</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z6">6</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z7">7</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z8">8</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z9">9</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava01/index01.htm#z10">10</a></td>
  </tr>
  <tr>
    <td>Разветвления</td>
    <th>2</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z44">44</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z43">43</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z42">42</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z41">41</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z40">40</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z39">39</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z38">38</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z37">37</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z36">36</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava02/index02.htm#z35">35б</a></td>
  </tr>
  <tr>
    <td>Простейшая целочисленная арифметика</td>
    <th>3</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z66">66</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z64">64</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z63">63</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z62">62</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z61">61</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z76">76в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z76">76б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z76">76а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z74">74</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava03/index03.htm#z73">73</a></td>
  </tr>
  <tr>
    <td>Простейшие циклы </td>
    <th>4</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114г</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114д</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114е</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114ж</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z114">114з</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z115">115а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z115">115б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava04/index04.htm#z115">115в</a></td>
  </tr>
  <tr>
    <td>Массивы. Простейшие массивы</td>
    <th>5</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136н</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136д</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136о</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136н</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136м</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136л</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136к</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136и</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136з</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava06/index06.htm#z136">136ж</a></td>
  </tr>
  <tr>
    <td>Массивы. Циклы и разветвления</td>
    <th>6</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178г</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178д</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178е</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z178">178б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z180">180</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava07/index07.htm#z181">181а</a></td>
  </tr>
  <tr>
    <td>Вложенные циклы и итерации</td>
    <th>7</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z320">320</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z334">334а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z334">334б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z334">334в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z334">334г</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z335">335а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z335">335б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z335">335в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z334">334г</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava10/index10.htm#z336">336а</a></td>
  </tr>
  <tr>
    <td>Обработка матриц</td>
    <th>8</th>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z673">673</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z674">674</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z675">675</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z676">676а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z676">676б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z677">677а</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z677">677б</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z677">677в</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z677">677г</a></td>
    <td align="left"><a href="https://ivtipm.github.io/Programming/Glava20/index20.htm#z678">678</a></td>
  </tr>
</tbody>
</table>


1. Задачи на Pyhton
Задачник -- https://ivtipm.github.io/Programming/Files/spisocall.htm
    - Все алгоритмы (поиск элемента в последовательности, сортировка, нахождения минимума и максимума и т.п.) требуется реализовывать самостоятельно.
    - Для задач 5-8 создайте отдельные модули (или один) с набором функций.
    - В задаче 8 для хранения матрицы используйте тип ndarray из библиотеки numpy.
    - Документируйте код. Оставляйте комментарии для себя. Соблюдайте стандарт оформления кода https://pep8.ru/doc/pep8/
Рекомендованная среда разработки - PyCharm
1. Скачайте рекомендованную литературу по Python
2. **Конспект**
    - тип данных dict


# Источники
1. А. С. Камкин. Введение в формальные методы верификации программ. 2018
2. https://cc.dvo.ru/uchebnaya-literatura.html
3. Моделирование параллельных процессов. Сети Петри. Мараховский В. Б., Розенблюм Л. Я., Яковлев А. В. — СПб.: Профессиональная литература, 2014. – 400 с
