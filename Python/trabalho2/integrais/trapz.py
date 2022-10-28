from math import *
from numpy import double

# Usado para aproximar o valor de uma integral
def trapz(f, a, b, n):
    h = (b-a) / n
    soma = 0
    for k in range(1, n):
        soma += f(a + k*h)
    soma *= 2
    soma += (f(a) + f(b))
    return (h/2) * soma


def f(x):
    return e**-x**2

intervalo = [-1.069, 1.256]
subintervalos = [9, 14, 47, 62, 76, 108, 165, 336, 520, 769, 1893, 8106]


for i in range(len(subintervalos)):
    r = trapz(f, intervalo[0], intervalo[1], subintervalos[i])
    print(r,',')