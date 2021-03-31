import multiprocessing
from math import sin, sqrt
from random import randint

def is_prime(n):
    res = True
    for i in range(2, int(sqrt(n))):
        if n % i == 0:
            res = False
    return res

def process_function(data_in, data_out):
    """ проверяет, является ли число из data_in простым. результат (число, true\false) записывает в data_out
    если вместо числа передано 'EXIT', то процесс завершается """
    while True:
        x = data_in.get()
        if x == 'EXIT':
            break
        data_out.put( (x, is_prime(x)) )



DataSend = multiprocessing.Queue()
DataRecv = multiprocessing.Queue()
# Queue -- очередь. любой процесс может писать туда данные .put( ... ), любой процесс может данные получать .get()

# создание процесса
p = multiprocessing.Process(target = process_function, args = (DataSend, DataRecv))
p.start()  # запуск

for i in range(10):
    A = 1000000000000000
    x = randint(A, A*10)
    print(f"Проверяем число {x}")
    DataSend.put( x )

    print("Ожидаем ответ...")
    num, res = DataRecv.get()
    print("Это "+("НЕ "if res == False else " ")+"простое число")

DataSend.put('EXIT')
p.join()  # ожидание завершения