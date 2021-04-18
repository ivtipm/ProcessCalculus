package com.company;

import java.util.concurrent.Callable;

// Callable -- интерфейс с обязательным методом call, который возвращает значение

// класс реализует Задачу -- нахождение суммы из N синусов чисел 0, 0.001, ...
public class MyTask implements Callable<String> {
    private int n;
    private Double sum;

    public MyTask(int n1) {
        sum = 0.0;
        setN(n1);
    }

    public String call(){
        Double sum = 0.0;
        for (int i = 0; i < this.n; i++) {
            sum += Math.tan( i/100.0 );
        }
        this.sum = sum;
        return Thread.currentThread().getName() + ": result " + sum;
    }

    public int getN() {
        return n;
    }

    public void setN(int n) {
        // todo: проверять предусловие
        this.n = n;
    }

    public Double getSum() {
        return sum;
    }
}

// Runnable -- класс похожий на Callable, но с обязательным методом run, который не возвращает никакого значения