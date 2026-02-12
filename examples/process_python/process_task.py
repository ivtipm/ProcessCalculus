"""
Пример параллельного выполнеия задач, представленных классами
Параллелизм организован процессами
Обмен данных через очереди
"""
import multiprocessing

class Task1:
	""" Класс -- вычислительная задача
	Содержит исходные данные, метод вычисслений, поле для результата
	todo: сделать наследование от класса с методом run
	"""
	n = 0
	res = None
	def run(self):
		s = 0
		for i in range(self.n):
			s += 1
		self.res = s
		# return s


class Task2:
	""" Класс -- вычислительная задача
	Содержит исходные данные, метод вычисслений, поле для результата
	todo: сделать наследование от класса с методом run
	"""
	res = None
	def run(self):
		self.res = "Hello, || world!"
		# return "Hello, || world!"



def process_function(data_in, data_out):
    """ проверяет, является ли число из data_in простым. результат (число, true\false) записывает в data_out
    если вместо числа передано 'EXIT', то процесс завершается """
    while True:
        t = data_in.get()
        if t == 'EXIT':
            break
        t.run()
        data_out.put( t )



DataSend = multiprocessing.Queue()		# для отправки задач отдельному процесу
DataRecv = multiprocessing.Queue()		# для получения результатов выполнения каждой задачи
# см. также другие классы для обмена данными: Value, Array и др.
# https://docs.python.org/3/library/multiprocessing.html#module-multiprocessing.sharedctypes

# создание процесса
p = multiprocessing.Process(target = process_function, args = (DataSend, DataRecv))
p.start()  # запуск


t1 = Task1()
t1.n = 10

t2 = Task1()
t2.n = 100;

t3 = Task2()


DataSend.put( t1 )
DataSend.put( t2 )
DataSend.put( t3 )
DataSend.put('EXIT')
# ...

t = DataRecv.get()
print(f"r1: {t.res}")
t = DataRecv.get()
print(f"r2: {t.res}")
t = DataRecv.get()
print(f"r3: {t.res}")

p.join()  # ожидание завершения
