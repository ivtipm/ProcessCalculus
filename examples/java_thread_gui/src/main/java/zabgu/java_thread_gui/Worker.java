package zabgu.java_thread_gui;

import static java.lang.Math.sin;

public class Worker {

    public int n = 1;
    private double result = 0.0;
    public volatile boolean stop = false;  // отвечает за остановку потока
    // volatile переменная может безопасно изменятся несколькими потоками


    Worker(int n1){
        if (n1 > 0)
            n = n1;
        else
            n = 1;
    }

    public void run(){
        stop = false;
        result = 0.0;
        for (int i =0; i < n; i++){
            if (!stop)
                result += sin(i);
            else
                return;
        }
    }

    public double getResult() {
        return result;
    }
}
