def sum_and_prod(x,y):
    return x+y, x*y
    # кортеж: x+y, x*y


t = sum_and_prod( 1,2 )
print( t )
# распаковка кортежа
s, p = sum_and_prod( 1,2 )

print(f"s = {s}, p = {p}")
t1 = sum_and_prod( 1,2 )[1]
# t1 = 2


# кортежное присваивание (обмен значений переменных)
a = 10
b = 20
c = False
a,b = b,a
print(f"a = {a}, b = {b}")
a,b,c = c,b,a


t = 10, True, "abc", 1.121
t0, *t_other = t
# t0:int = 10, t_other: tuple = True, "abc", 1.121

*t_other, t_last = t
# t_other: tuple = 10, True, "abc"; t_last = 1.121
print(t_other)


t2 = 1,2,3,4,5,6
t0, *t_other, t_last_2, t_last1 = t2
# t0 = 1, t_last_2 = 5, t_last1 = 6, t_other = 2,3,4
print(t0)
print( type(t_other) )
print(t_last_2)
print(t_last1)
