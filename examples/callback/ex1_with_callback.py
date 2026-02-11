"""
Простой пример без асинхронности и callback
"""
import threading
import httpx
from time import sleep


def download_file(url, callback):

    # Пример для объяснения логики callback; Но в питоне анонимная функция обязана содержать выражение (expression) и не может содержать последовательность операторов (statements)
    # th = threading.Thread( target = lambda : data = httpx.get(url); callback(data) )

    th = threading.Thread( target = lambda : callback( httpx.get(url) ) )
    th.start()


def print_result( data ):
    print(data)


download_file("https://habr.com/ru/feed/", print_result)

# имитация работы, которую стоит выполнять в основном потоке, пока второй поток ожидает получения данных
for i in range(101):
    sleep(0.01)
    c = '.' if i%10 != 0 else '|'
    print(c, end="", flush=True)
print()
