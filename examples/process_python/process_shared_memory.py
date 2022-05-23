import multiprocessing
from multiprocessing import Queue, Array, Value
from multiprocessing import Process
from numpy.random import uniform

import time

from math import *


def sum_array_sin(data: Array, start, end: Value, result: Value):
		"""Вычисляет частичную (от индекса start до end-1) сумму синусов элементов массива, размещённого в общей для процессов памяти
		Записывает результат в result
		"""
		sum = 0
		# result.value = 0
		for i in range( start, end ):
				sum = sum + sin(data[i])
		result.value = sum


def randomize_array(arr: Array):
		for i in range(len(arr)):
				# arr[i] = uniform(0, 100, 1)
				arr[i] = 1



N = int(1e8)
arr = Array('d', N)					# массив из N элементов типа double ('d'), размещается в общей для процессов памяти

print('Array initializing...')
randomize_array(arr)

S1 = Value('d', 0.0)				# объект размещённый в общей памяти, хранит значение типа double
S2 = Value('d', 0.0)


print('Calculating...')
t0 = time.time()


proc1 = Process(target = sum_array_sin, args=(arr, 0, 	 N, S1))	
# proc2 = Process(target = sum_array_sin, args=(arr, N//2, N, 	 S2))
proc1.start()
# proc2.start()
# текущий процесс ничего полезного не делает...
proc1.join()
# proc2.join()

print(f'Fineshed in {(time.time()-t0)} seconds')
S = S1.value + S2.value

print(f'sum = {S}')		

# проверка
assert abs(S - 0.84147098*N) < 1