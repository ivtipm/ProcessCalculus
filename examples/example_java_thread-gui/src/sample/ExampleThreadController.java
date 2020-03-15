package sample;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;

import static java.lang.Math.sin;

public class ExampleThreadController {

    @FXML Label status_label;

    private static int N = 100000000;
    private Worker w = new Worker(N);

    
    private static double thread_foo(int n){
        double result = 0.0;
        for (int i =0; i < n; i++){
            result += sin(i);
        }

        return result; }


    public void run_here(MouseEvent mouseEvent) {
        status_label.setText( "Вычисление...");   // это пользователь не увидит
        double res = thread_foo(N);
        status_label.setText( " Sum =  " + res);
    }


    public void run_in_thread2(MouseEvent mouseEvent) {
        status_label.setText( "Вычисление...");

        // Запуск вычислений в отдельном потоке
        new Thread( () -> {
            w.run();
            double res = w.getResult();

            // Обновление данных из основного потока после завершения вычислений
            Platform.runLater(() -> {
                String note = "";
                if (w.stop)
                    note = "(stoped)";
                status_label.setText( "Sum = " + res + " " + note);
            });
        }).start();
    }

    public void stop(MouseEvent mouseEvent) {
        w.stop = true;
    }
}
