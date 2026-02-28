from random import randint
import numpy as np
import time



N = 100_000_000
# N = 1000
# list_a = [ randint(-100, 100)   for i in range(N) ]

# t0 = time.time()
# S = sum( list_a )
# print( f"Dt = {time.time() - t0}")      # 1 sec


# a = np.zeros( N )
# a = np.ones( N )
a = np.random.randint( -100, 100, size=N)

t0 = time.time()
# S = a.sum()
S = sum( a )
print( f"Dt = {time.time() - t0}")      # 0.05 sec


# a.sum()
