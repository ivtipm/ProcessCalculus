"""
Простой пример асинхронной программы из 3 функций возвращающих значение; ожидание через Future

Три асинхронных функции, каждая из которых работает 1, 2 и 3 секунды выполняются суммарно за 3 с небольшим секунды.
Это возможно за счёт того, что функции позволяют выполняться друг другу, пока каждая из них ожидает событие (окончание таймера)
"""

import asyncio
import time


# async def - объявление корутину (сопрограммы), а не функции
# корутины могут приостанавливать свою работу давая возможность выполняться другим корутинам
async def c1():
    print("c1 started...")
    await asyncio.sleep(1)      # функция с11 тут может встать на паузу
                                # её разбудят, когда выполнение кода вызванного после await завершится
    # asyncio.sleep - неблокирующая функция, которая позволяет приостановить выполнение корутины
    # time.sleep - блокирующая функция
    print("c1 completed")
    return 100


# корутина
async def c2():
    print("c2 started...")
    await asyncio.sleep(2)
    print("c2 completed")
    return 200


# корутина
async def c3():
    print("c3 started...")
    await asyncio.sleep(3)
    print("c3 completed")
    return 300


async def main_await_results():
    """первый пример запуска корутин c ожиданием через результат"""
    future_results = asyncio.gather( c1(), c2(), c3())     # поставить корутины в очередь на выполнение и начать выполнять;

    # здесь будет напечатан _GatheringFuture без результата (с состоянием pending), т.к. к этому моменту функции не успеют вернуть результат
    print("Results (before wait): ", end=""); print(future_results)

    # неблокирующее ожидание завершения всех задач
    await future_results

    # здесь будет напечатан _GatheringFuture c результатом
    print("Results (after wait): ", end=""); print(future_results)
    print(future_results.result())



start = time.time()
asyncio.run( main_await_results() )       # запуск цикл обработки событий (event loop) и главную функцию с корутинами
# asyncio.run - блокирующая функция, но вызовы корутин внутри будут не блокирующими

#  неправильный способ вызова main
# main1()

print(f"Время выполнения кода: {time.time() - start:.0f} секунды")
