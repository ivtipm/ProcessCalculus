"""

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


# корутина
async def c2():
    print("c2 started...")
    await asyncio.sleep(2)
    print("c2 completed")


# корутина
async def c3():
    print("c3 started...")
    await asyncio.sleep(3)
    print("c3 completed")


async def main_await_gather():
    """первый пример запуска корутин"""
    await asyncio.gather( c1(), c2(), c3())     # поставить корутины в очередь на выполнение и начать выполнять


async def main_create_await():
    """второй пример запуска корутин"""
    asyncio.create_task( c1() )
    # syncio.create_task - добавление задачи в цикл обработки событий
    asyncio.create_task( c2() )
    await asyncio.create_task( c3() )
    # await позволяет не завершать функцию main2 сразу, а дождаться выполнения c3()


start = time.time()
# asyncio.run( main1() )       # запуск цикл обработки событий (event loop) и главную функцию с корутинами
main1()
# asyncio.run - блокирующая функция, но вызовы корутин внутри будут не блокирующими
print(f"Время выполнения кода: {time.time() - start:.0f} секунды")
