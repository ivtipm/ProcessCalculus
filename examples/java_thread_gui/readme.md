# Java

## Запуск отдельного потока в JavFX приложении через Thread
```java
// Создание нового объекта типа Thread (который создат поток в текущем процессе)
// В конструктор передаётся экземпляр потока Runnable 
 new Thread( () -> {
    // выполнение основной работы:
    w.run();    
    double res = w.getResult();
     
    // После выполнения основной работы, обновим UI
    // Platform.runLater выполнит код (метод экземпляра класса Runnable) из основного потока приложения
    Platform.runLater(() -> {
            String note = "";
            if (w.stop)
                note = "(stoped)";
            status_label.setText( "Sum = " + res + " " + note);
        });
        }).start();

// .start() - запуск потока
```

Запуск кода в отдельном потоке получится асинхронным, не заблокирует текущий поток, .т.к. отсутствует операция ожидания завершения потока.

Аналог callback функции -  `Platform.runLater` позволит обновить UI после завершения работы. 


## Запуск отдельного потока в JavFX приложении через javafx.concurrent.Task;

`avafx.concurrent.Task` - специальный класс для выполнения фоновых задач в JavaFX. 
https://openjfx.io/javadoc/23/javafx.graphics/javafx/concurrent/Task.html

* в task передаётся объект, с реализацией интерфейса Callable, т.е. с определённым методом T call()
* call будет выполнятся в отдельном потоке
* значение, которое вернёт call будет запомнено экземпляром класса Task; оно доступно через геттер: `T getValue()` 
* дополнительно в метод класса `Task` 
`setOnSucceeded(EventHandler<WorkerStateEvent> value)`  можно передать обработчик, который выполнится при успешном завершении потока
* см. примеры использования и другие полезные методы класса Task в документации


## Запуск стороннего процесса в Java
```java
ProcessBuilder processBuilder = new ProcessBuilder( cmd );
    List<String> cmd = new ArrayList<>();       // программа + список её аргументов
    // например: mkvmerge -o out.mp4 1.mp4 + 2.mp4
    cmd.add("mkvmerge");
    cmd.add("-o");
    cmd.add("out.mp4");
    cmd.add("1.mp4");
    cmd.add("+.mp4");
    cmd.add("2.mp4");

    processBuilder.directory( new File( "/path/to/workdir" ) );
    processBuilder.redirectErrorStream(true); // Объединяем stdout и stderr
    
    // Запускаем процесс
    Process process = processBuilder.start();
    
    // Читаем вывод команды
    BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
    String line;
    StringBuilder output = new StringBuilder();
    while ((line = reader.readLine()) != null) {
        output.append(line).append("\n");
    }
```