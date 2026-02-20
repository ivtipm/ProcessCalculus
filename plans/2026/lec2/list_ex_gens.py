"""
Дан массив a размером n
для каждого a[i] = a[i]**2
вычислить сумму элементов
"""

from arrays import *
import numpy

def main():
    # n = int(input("n = "))
    n = 5
    a = [0] * n
    random_array(a)
    print_array(a)
    print()
    sqr_array(a)
    print_array(a)
    print()
    S = sum_array(a)
    print(f"\nS = {S:.2f}")
    print()


if __name__ == "__main__" :
   main()
