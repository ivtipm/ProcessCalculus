## О курсе
**Чему научитесь?**
- Изучите основы языка программирования Python
- Основы параллельного программирования,
    - Параллельному программированию на основе потоков (thread) для приложений с GUI
    - Созданию параллельных алгоритмов для ускорения решения задач, в том числе на основе пула потоков
    - Некоторым приёмам синхронизации потоков\процессов
    - Созданию параллельных версий алгоритмов программ с помощью библиотеки OpenMP
- Созданию распределённых алгоритмов с использованием библиотеки MPI
- Описанию и анализу асинхронных процессов с помощью сетей Петри


# Лекция 4.
- Введение в параллельное программирование: https://github.com/ivtipm/ProcessCalculus/raw/master/PC.%20lec.%20parallel.pdf

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

**Python** -- язык программирования общего назначения с большой коллекцией библиотек написанных на разных языках программирования.
Благодаря этому и ориентации языка на продуктивность разработка Python широко используется для научных вычислений и визуализации данных.
Библиотеки для математических вычислений скомпилированы и содержат оптимизированный код. Некоторые библиотеки дают доступ к распараллеливанию вычислений на GPU.


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
    - Для задач 5-8 создайте отдельные модули (или один) с набором функций. Напишите тесты.
    - В задаче 8 для хранения матрицы используйте тип ndarray из библиотеки numpy. Используйте методы класса ndarray, старайтесь писать как можно меньше циклов.
    - Пишите аннотации типов (type hints). Документируйте код (см. `__doc__` для функций). Оставляйте комментарии для себя. Соблюдайте стандарт оформления кода https://pep8.ru/doc/pep8/
    - Указывайте имя автора программы в переменной `__author__`

Рекомендованная среда разработки - Sublime Text 4, для отладки используйте PyCharm.

1. Скачайте рекомендованную литературу по Python