## О курсе
**Чему научитесь?**
- Изучите основы языка программирования Python
- Основы параллельного программирования,
    - Теоретические основы: виды параллельных архитектур, оценка ускорения вычислений, приёмы и проблемы параллельных алгоритмов
    - Параллельному программированию на основе потоков (thread) для приложений с GUI
    - Созданию параллельных алгоритмов для ускорения решения задач, в том числе на основе пула потоков
    - Некоторым приёмам синхронизации потоков\процессов
    - Созданию параллельных версий алгоритмов программ с помощью библиотеки OpenMP
- Созданию распределённых алгоритмов с использованием библиотеки MPI
- Описанию и анализу асинхронных процессов с помощью сетей Петри


# Лекция 12. Сети Петри
8 мая
- [слайды](https://github.com/ivtipm/ProcessCalculus/blob/master/PC_lec_Petri_Net.pdf)
- Примеры: https://miro.com/app/board/uXjVORmoCO0=

См. также - автоматы
- https://habr.com/ru/articles/273393/
- https://ru.wikipedia.org/wiki/%D0%98%D0%B3%D1%80%D0%B0_%C2%AB%D0%96%D0%B8%D0%B7%D0%BD%D1%8C%C2%BB
- https://playgameoflife.com/

#### Задание
1. https://github.com/ivtipm/ProcessCalculus/blob/master/%D0%97%D0%B0%D0%B4%D0%B0%D0%B8%D0%B5.%20%D0%A1%D0%B5%D1%82%D1%8C%20%D0%9F%D0%B5%D1%82%D1%80%D0%B8.pdf
2. Выберете такую начальную маркировку, чтобы получилось дерево переходов глубиной больше трёх. Постройте это дерево как минимум до третьего уровня. Сделайте выводы о динамических свойствах данной сети Петри.

#### Бонусное задание
1. Запустите программу для выполнения сети Петри из исходников. См. ссылки на программы в дискорде
2. Доработайте программы



# Лекция 12. OpenMP. MPI.
24 апреля
- https://github.com/ivtipm/ProcessCalculus/blob/master/MPI.md
- Пример 1. Распределённые вычисления числа Пи. https://github.com/ivtipm/ProcessCalculus/blob/master/examples/MPI-pi-monte-carlo/main.cpp
- Пример 2. Простая программа и dockerfile. https://github.com/ivtipm/ProcessCalculus/blob/master/examples/MPI-pi-monte-carlo/main.cpp

#### Домашнее задание. MPI
1. Решите произвольную задачу используя библиотеку MPI
2. Протестируйте программу запустив её на одной и нескольких машинах.


## Домашнее задание. Тестовый кластер на основе контейнеров Docker
Создайте кластер для на основе контейнеров Docker для тестирования распределённых вычислений.


# Лекция 11. OpenMP. MPI.
17 апреля
https://github.com/ivtipm/ProcessCalculus/blob/master/MPI.md


# Лекция 10. OpenMP
10 апреля
- Векторизация: https://github.com/ivtipm/ProcessCalculus/blob/master/examples/auto_vectorization/main.cpp
- OpenMP
  - https://github.com/ivtipm/ProcessCalculus/blob/master/OpenMP.md

- Пример: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/openMP_1


#### Домашнее задание. OpenMP
1. Создайте параллельный алгоритм для решения одной или нескольких задач из первого домашнего задания (задачи номерами 5-8). Используйте OpenMP и распараллеливание циклов.
2. Решите произвольную задачу используя библиотеку OpenMP



# Лекция 9. Пул потоков
3 апреля
- Пул потоков. https://github.com/ivtipm/ProcessCalculus/blob/master/ll2.md
- https://github.com/ivtipm/BigDataLanguages/tree/main/Java/Threads


#### Домашнее задание. Пул потоков
1. Создайте версию программы с параллельными потоками (см. [Задание. Параллельный алгоритм](https://github.com/ivtipm/ProcessCalculus/blob/master/plans/tasks/tasks_ll.md), но используйте пул потоков.

2. Дополните [Программу с GUI и дополнительным потоком](https://github.com/ivtipm/ProcessCalculus/blob/master/plans/tasks/task_another_thread.md): добавьте возможность запустить вычисления в пуле потоков.



# Лекция 8. Параллельное программирование
27 апреля
- Синхронизация с помощью мьютекса: https://github.com/ivtipm/ProcessCalculus/blob/master/examples/thread-sync1/main.cpp
- Синхронизация на основе передачи сообщений: https://github.com/ivtipm/ProcessCalculus/blob/master/examples/condition_variables/main.cpp
- https://github.com/ivtipm/ProcessCalculus/blob/master/ll2.md

Java:
- Шпаргалка: https://github.com/ivtipm/BigDataLanguages/tree/main/Java/Threads
- Примеры: https://github.com/ivtipm/ProcessCalculus/blob/master/examples/example_java_threads/src/Main.java
- https://github.com/ivtipm/ProcessCalculus/raw/master/PC.%20lec.%20parallel.pdf






# Лекция 7. Параллельное программирование
20 марта
- Ошибки параллельного программирования. https://github.com/ivtipm/ProcessCalculus/raw/master/PC.%20lec.%20parallel.pdf
- Примеры использования потоков в C++ и Qt: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_qthread
- Примеры использования потоков в Java: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_java_threads
- Примеры использования потоков в Java и JavaFX: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_java_thread-gui
- Примеры использования потоков в С#, асинхронные методы: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/Csharp_async


# Лекция 6. Параллельное программирование
13 марта
- Введение в параллельное программирование: https://github.com/ivtipm/ProcessCalculus/raw/master/PC.%20lec.%20parallel.pdf
- Примеры использования потоков в C++: https://github.com/ivtipm/ProcessCalculus/tree/master/examples/example_thread




# Лекция 5. Параллельное программирование
6 марта
- Введение в параллельное программирование: https://github.com/ivtipm/ProcessCalculus/raw/master/PC.%20lec.%20parallel.pdf

#### [Задание. Скрапер](https://github.com/ivtipm/ProcessCalculus/blob/master/plans/tasks/scraper.md)

#### [Задание. Программа с GUI и дополнительным потоком](https://github.com/ivtipm/ProcessCalculus/blob/master/plans/tasks/task_another_thread.md)

#### [Задание. Параллельный алгоритм](https://github.com/ivtipm/ProcessCalculus/blob/master/plans/tasks/tasks_ll.md)

#### Задание (бонус). Брутфорс по хэшу
Создайте программу для подбора хэшей sha512. Пароль состоит из 7 символов цифр или маленьких букв.
Используйте несколько потоков.

Подберите хэш для своего варианта (номер с списке): [hashes.md.](../tasks/hashes.md)

Можно использовать любой язык программирования. Код функции подбора напишите самостоятельно.


#### Задание (бонус). Брутфорс для веба
Подберите пароль для формы авторизации.

Создайте программу, которая использует несколько потоков (процессов для подбора пароля).

См. логины в таблице.
Адрес сервера см. в дискорде.

# Лекция 4.
28 марта
- Сопоставление с образцом
- CUDA на Python, через PyTorch в Google colaboratory

#### Задание. Бонус. MindMap.

#### Задание. Virtual Enviroment
Отчёт по созданию виртуального окружения Python *(бонусное задание)*: зачем нужно? как сделать? Активировать? Деактивировать? На примере одной из своих программ и установки дополнительных пакетов непостредственно и с использованием файла requirements.txt.


#### Задание. Генераторы (бонус)
Создайте версию программы [139](https://ivtipm.github.io/Programming/Glava06/index06.htm#z139) с использованием функции-генератора.


#### Задание. Полносвязная нейросеть для задачи классификации (бонус)
Решите задачу классификации с помощью полносвязной нейросети, созданной с помощью фреимворка Keras.

Для обучения используйте параллельные вычисления на GPU, на основе CUDA.

Шаблон кода: https://colab.research.google.com/drive/1josHsquNFQH1cfu2jyeFfzQw4c5uTaqG?usp=sharing


#### Задание. List vs NumPy vs Torch
Сравните время перемножения двух матриц
- представляя матрицы как списки Python
- представляя матрицы как numpy array
- представляя матрицы как torch tensor (на GPU и CPU)

Чтобы результаты были надёжными, повторите замеры несколько раз. Используйте такие размеры матриц, чтобы перемножение занимало как минимум несколько десятков секунд на CPU.

О PyTorch: https://colab.research.google.com/drive/1_5JVzwKej5hCe8I_bHfFYC0y8CrjfhJi?usp=sharing

См. также библиотеку Python asyncio для асинхронного программирования.

#### Задание (бонус). CMD UI
Создайте версию программы 5 с командным интерфейсом. Программа должна принимать набор чисел как аргумент программы при запуске.

Можно предложить свой вариант программы с командным интерфейсом.




# Лекция 3.
21 февраля
- zip, map, reduce, enumerate,
    - примеры и материалы: https://miro.com/app/board/uXjVORmoCO0=/?invite_link_id=993701359201
- Основы numpy
    - Учебное пособие: [Математические модели и вычислительные методы обработки экспериментальных данных](https://raw.githubusercontent.com/ivtipm/ML/main/%D0%9C%D0%B0%D1%82%D0%B5%D0%BC%D0%B0%D1%82%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B5%20%D0%BC%D0%BE%D0%B4%D0%B5%D0%BB%D0%B8%20%D0%B8%20%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5%20%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D1%8B%20%D0%BE%D0%B1%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%BA%D0%B8%20%D1%8D%D0%BA%D1%81%D0%BF%D0%B5%D1%80%D0%B8%D0%BC%D0%B5%D0%BD%D1%82%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D1%85%20%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85.pdf), параграф 3.2.1 NumPy
    - Тетрадка с некоторыми примерам: https://colab.research.google.com/drive/1xgjjvDtmcw__xYZtFa0t0InogMcANeQp?usp=sharing#scrollTo=9edMEx5rf9dk
-  python. Сопоставление с образцом


# Лекция 2. Введение в Python
февраль 14
- Повторение
- Кортежи. Операции распаковки. Функции, документация, передача аргументов по ссылке и по значению, возврат значений. Анонимные функции. Модули.
- примеры и материалы: https://miro.com/app/board/uXjVORmoCO0=/?invite_link_id=993701359201


# Лекция 1. Введение в Python
февраль 07
- Python. Особенности. Типы данных. Операторы
- Файлы со слайдами 1-5:
    - https://github.com/VetrovSV/Programming
- примеры и материалы: https://miro.com/app/board/uXjVORmoCO0=/?invite_link_id=993701359201


## Практика 1

**Python** — язык программирования общего назначения с большой коллекцией библиотек написанных на разных языках программирования.
Благодаря этому и ориентации языка на продуктивность разработка Python широко используется для научных вычислений и визуализации данных.
Библиотеки для математических вычислений скомпилированы и содержат оптимизированный код. Некоторые библиотеки дают доступ к распараллеливанию вычислений на GPU. Параллельное и асинхронное программирование доступно из стандартной библиотеки.


В течении курса Python будет использоваться для вычислений на GPU и визуализации.

#### Задание. Основы Python
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
    - Помните про свойство *массовости* алгоритма, создавайте код который решает задачу для разных значений входных данных, а не только для тех, которые указаны в условии задачи.
    - Для задач 5-8 создайте отдельные модули (или один) с набором функций. Напишите тесты для функций (утверждения assert для сравнения результатов работы функций с заранее вычисленными, корректными значениями). Используйте фреимворки для модульного тестирования при желании, но обязательно приведите пример использования оператора assert.
    - В задаче 8 для хранения матрицы используйте тип ndarray из библиотеки numpy. Используйте методы класса ndarray, старайтесь создавать как можно меньше циклов.
    - Пишите аннотации типов (type hints). Документируйте код (см. `__doc__` для функций). Оставляйте комментарии для себя. Соблюдайте стандарт оформления кода PEP8 (перевод на русский: https://pythonworld.ru/osnovy/pep-8-rukovodstvo-po-napisaniyu-koda-na-python.html, оригинал: https://peps.python.org/pep-0008/).
    - Указывайте имя автора программы в переменной `__author__`, условие задачи в начале главного файла.

Рекомендованная среда разработки - Sublime Text 4, для отладки используйте PyCharm. Не используйте PyCharm или похожую среду разработки для написания кода, ибо автоматическое дополнение и подсказки мешают изучению языка.

1. Скачайте рекомендованную литературу по Python
