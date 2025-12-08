import asyncio
import time


async def c1():
    print("c1 started...")
    await asyncio.sleep(1)      # функция с11 тут может встать на паузу
                                # её разбудят, когда выполнение кода вызванного после await завершится
    print("c1 completed")


async def c2():
    print("c2 started...")
    await asyncio.sleep(2)
    print("c2 completed")


async def c3():
    print("c3 started...")
    await asyncio.sleep(3)
    print("c3 completed")


async def main():
    asyncio.create_task( c1() )
    # syncio.create_task - добавление задачи в цикл обработки событий
    asyncio.create_task( c2() )
    await asyncio.create_task( c3() )


start = time.time()
asyncio.run( main() )       # запуск цикл обработки событий (event loop) и главную функцию с корутинами
# asyncio.run - блокирующая функция, но вызовы корутин внутри будут не блокирующими
print(f"Время выполнения кода: {time.time() - start:.0f} секунды")