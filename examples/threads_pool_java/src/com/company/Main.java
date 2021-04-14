package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Main {

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        // Executors -- служебный класс, создающий различные пулы потоков
        // будет создан пул из 10 потоков
        ExecutorService threads_pool = Executors.newFixedThreadPool(10);

        // в примере потоки будут возвращать значения,
        // для хранения возвращаемых значений из потоков в Java и многих других ЯП
        // используется класс Future. Он позволяет проверять, не возвратил ли ещё поток значение
        // Future -- параметризованный тип, т.к. он должен подходить для потоков возвращающих разные значения

        List<Future<String>> results_list = new ArrayList< Future<String> >();

        Random random = new Random();
        for (int i = 0; i < 15; i++) {      // задач больше чем потоков
            MyTask t = new MyTask(random.nextInt(1000000)+100000);

            // передаём Задачу пулу потоков, он сам решит какому из потоков назначить выполнение Задачи
            Future<String> result = threads_pool.submit( t );

            results_list.add( result );
        }
        
        // ожидание завершения задач (но не потоков)
        for (Future<String> f : results_list) {
            System.out.println( f.get() );

        }

        // завершение всех потоков
        threads_pool.shutdown();
    }
}

// Другие классы для организации пула потоков:
// https://javarush.ru/groups/posts/2078-threadom-java-ne-isportishjh--chastjh-v---executor-threadpool-fork-join-pool
