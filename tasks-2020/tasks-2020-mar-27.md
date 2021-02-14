# март 27
- Игнорировать задания по ТВП на сайте университета
##  Лекция
### Синхронизация с помощью мьютексов.
- Изучить [lec.sync.md](lec.sync.md)
  - Изучить пример синхронизации из лекции
  - Запустить пример
- Составить конспект, если конспект в электронном виде то его нужно распечатать и добавить к бумажному

- изучить документацию по классам
  - [timed_mutex](https://en.cppreference.com/w/cpp/thread/timed_mutex)
  - [recursive_mutex](https://en.cppreference.com/w/cpp/thread/recursive_mutex) [youtube](https://www.youtube.com/watch?v=_jZlmgDoDOM)
  - [recursive_timed_mutex](https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex)
  - [lock_guard](https://en.cppreference.com/w/cpp/thread/lock_guard)
  - [unique_lock](https://en.cppreference.com/w/cpp/thread/unique_lock)


- Ответить на вопросы:
  - Какую метафору "из жизни" вы бы предложили для описания мьютекса?
  - Что будет если два раза подряд заблокировать mutex?
  - Какое соотношение в коде между количеством блокировок и разблокировав должно соблюдаться для рекурсивного мьютекса?
  - Чем отличаются мьютексы представленные классами: mutex, timed_mutex, recursive_mutex, recursive_timed_mutex?
  - Для чего нужны классы lock_guard и unique_lock?

- Если ваш любимый язык программирования не С++, то изучить документацию по мьютексам для этого языка программирования (его стандартной библиотеки)





## Лабораторное занятие
- За основу программы взять программу нахождения суммы массива (задание приведено в конце файла)
- Модифицировать эту программу так, чтобы каждый поток в конце своей работы записывал сумму в общую для всех потоков переменную.
- Общая для потоков переменная должна быть помещена в критическую секцию, защищённую мьютексом
- Создать большое число потоков (несколько сотен или больше), измерить время работы программы.
- Для надёжности измерений программа должна работать порядка нескольких секунд, лучше 20+ секунд. Если программа работает слишком быстро то стоит увеличить размер массива или сложность вычислений. Например суммировать не элементы массива и синусы этих элементов, или синусы синусов и т.д.
- Сравнить время работы данной программы, с тем что требуется программе без синхронизации потоков (предыдущий вариант программы, где суммирование частичных сумм потоков происходило в главном потоке)
- Как синхронизация повлияла на быстродействие программы? При каком числе потоков в данной программе, синхронизация заметно влияет на время выполнения программы?
- Загрузить код на github, отправить ссылку преподавателю

### вопросы
- Какую проблему в данной задаче решает критическая секция, реализованная с помощью мьютекса?


#### задание с занятия 20 марта
- создать || программу вычисления суммы массива
- число потоков, которые будут считать сумму, должно задаваться пользователем
- Каждый поток должен записывать сумму в свою переменную, потом в основном потоке находится общая сумма
- Измерить время работы программы для разного числа потоков, составить таблицу (или график)
- Для надёжности измерений программа должна работать порядка нескольких секунд, лучше 20+ секунд. Если программа работает слишком быстро то тоит увеличить размер массива или сложность вычислений. Например суммировать не элементы массива и синусы этих элементов, или синусы синусов и т.д.
- Можно ли определить оптимальное число потоков по результатам измерений? Если да, то как это количество соотносится с числом ядер процессора и оптимальным числом потоков полученных программным способом (функция std::thread::hardware_concurrency() в C++)