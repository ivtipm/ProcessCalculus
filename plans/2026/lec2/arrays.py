"""
.......
"""
__author__ = "Vetrov"
# pytest

import random


RND_MIN = -100.0
RND_MAX =  100.0



def print_array(arr):
    """Выводи массив из веществ чисел через запятую в одну строку"""
    for el in arr:
        print(f"{el:.2f}", end=", ")


def sum_array(arr) -> float:
    """Сумма элементов массива"""
    S = 0.0
    for el in arr:
        S += el
    return S


def sqr_array(arr):
    """Возводить в квадрат элементы массива"""
    for i in range( len(arr) ):
        arr[i] = arr[i]**2


# todo: args
def random_array(arr):
    """Заполнение массива случайными числами"""
    for i in range( len(arr) ):
        arr[i] =  random.uniform(RND_MIN, RND_MAX)


def tests():
    assert sum_array( [1] ) == 1
    assert sum_array( [] ) == 0
    assert sum_array( [1,2,3] ) == 6
    assert sum_array( [1,-2,3] ) == 2


tests()
