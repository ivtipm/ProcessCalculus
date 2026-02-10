"""
Простой пример без асинхронности и callback
"""
import httpx
from time import sleep

def download_file(url):
    data = httpx.get(url)  # ЖДЁМ здесь
    return data


result = download_file("https://habr.com/ru/feed/")

# Выполнится только после загрузки
print(result)

# имитация работы, которую стоит выполнять в основном потоке, пока идёт загрузка
for i in range(101):
    sleep(0.01)
    c = '.' if i%10 != 0 else '|'
    print(c, end="", flush=True)
print()
