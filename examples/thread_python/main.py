# в стандартной реализации Python из-за Global Interpreter Lock потоки (threads) не могут выполнятся параллельно
# но они полезны, если в них поместить вызов функции ожидающей событие или ресурс, чтобы не блокировать основной поток выполнения

# https://docs.python.org/3/library/threading.html

import threading
from math import sin

# функция, которая будет выполнятся в отдельном потоке
def thread_function(N):
    global sum           # всем потокам доступна одна и та же память
    sum = 0
    d = N//10   # 1/10 все данных. буте использовать для печать прогресбара
    for i in range(N):
        sum += sin(i)
        if i%d == 0:
            print('|', end='', flush=True)



import time
start_time = time.time()

# создание объекта, отвечающего за управление потоком
# args -- параметры, которые будет переданы в функцию потока
th1 = threading.Thread(target=thread_function, args=(100000000,))
# запуск потока
th1.start()
print("Поток запущен")

print("Ждём его завершения")
# ожидание заверешения потока
# поток завершится, когда завершится его функция
th1.join()

print("Поток завершён")
print(f"{sum:.6f}")

print(f"затраченное время: {(time.time() - start_time):.2f} секунд")
