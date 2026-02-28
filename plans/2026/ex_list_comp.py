import math
from random import randint


N = 10

# l = [0]*N


# for i in range(N):
#     l[i] = randint(-100, 100 )
#     l[i] = i

# print( l )


# l = [ i   for i in range(N) ]
l = [ math.log( abs(randint(-100, 100)+1))   for i in range(N) ]

# фильтрация (if)
# генерация вложенных списков
# генераторы для кортежей, множеств и словарей

print(l)
