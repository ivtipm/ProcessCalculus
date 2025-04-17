# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import numpy as np
from PIL import Image


def min_devider(x):
    """ возвр минимальный возможный делитель """
    # todo: оптимизировать
    for i in range(2, x):
        if x % i == 0:
            return i
    return x


def dividers_matrix(n, m):
    """создаёт матрицу n x m
    нумерует все элементы матрицы слева на права, сверху вниз
    записывает в элемент матрицы его минимальный делитель (начиная с 2)"""
    d = n // 10
    M = np.zeros( shape=(n, m) )
    for i in range(n):
        for j in range(m):
            M[i,j] = min_devider( i*m + j + 1 )

    return M


M = dividers_matrix(256, 256)


image = Image.fromarray(M)
image.show()
