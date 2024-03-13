# Вычисления в отдельном потоке

В приложении с GUI реализовать:
1. Запуск вычислений в основном потоке.
2. Запуск вычислений в отдельном потоке. При этом окно программы должно быть доступно для взаимодействия с пользователем.
3. Дополнительно:
    - Показывать прогресс вычислений
4. Предусмотреть остановку вычислений по желанию пользователя.

Примеры вычислительных задач:
- Задачи из численных методов: численное интегрирование, решение дифференциальных уравнений, задачи оптимизации; вычисление числа Пи, …
- Компьютерное моделирование, клеточные автоматы. 
- Операции с большими массивами: сортировка, нахождение суммы, ...
- Обработка изображений, применение фильтров.
- Фракталы, построение множеств Мандельброта или Жулиа.
- Генетический алгоритм.
- Загрузка большого числа файлов из Интернета или создание большого числа запросов.
- Алгоритмы и методы анализа данных и машинного обучения.
- Перебор текста по значению хеш-функции, перебор паролей.

### Рекомендации к выполнению
Примеры работы с потоками: github.com/ivtipm/ProcessCalculus/tree/master/examples

В программе из этого задания поток с отдельными вычислениями должен быть запущен в методе –  обработчике нажатия на кнопку.  Сложность заключается в том, что нужно после завершения вычислений в отдельном потоке обновить данные в окне программы. Однако обработчики событий окна программы находятся в основном потоке.
#### Qt
В Qt для этого выгодно использовать механизм сигналов и слотов. Создать отдельный класс – для вычислений в отдельном потоке, вызвать в нём сигнал finished(). Соединив (QObject::connect) этот сигнал с обработчиком – методом на форме можно обновить данные, когда вычисления завершатся. 
Пример:  github.com/ivtipm/ProcessCalculus/tree/master/examples/example_qthread


#### JavaFX
Создавая интерфейс пользователя с помощью JavaFX можно обернуть обращение к элементам интерфейса из другого потока в производный от Runnable класс следующим образом:
```java
// запуск потока в одном из методов контролёра
в new Thread( () -> {
    // продолжительные вычисления
    Platform.runLater(() -> {
    // обновление Lable в окне программы
    status_label.setText( "Done!" );          });
  }).start();
```
Статический метод runLater1 поставит переданный в него объект типа Runnable в очередь обработки сообщений программы. При этом внутри runLater не должно быть продолжительных операций, так как этот код выполняется в основном потоке приложения.

#### С#
[Пример](https://github.com/ivtipm/ProcessCalculus/tree/master/examples/Csharp_async)

### Вопросы
1. Что такое блокирующий и не блокирующий вызовы?
2. Как в программе организован неблокирующий вызов вычислений?
3. Как в программе организовано обновление данных в окне после завершения работы потока с вычислениями?

### Ссылки
- docs.microsoft.com/ru-ru/dotnet/csharp/programming-guide/concepts/async – С# Асинхронное программирование с использованием ключевых слов async и await
- github.com/ivtipm/ProcessCalculus/tree/master/examples/example_qthread – Пример работы с Qthread
- docs.oracle.com/javase/10/docs/api/java/lang/Thread.html – Thread (Java class)