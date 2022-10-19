from Python.Interpolacao.methods import *
import math


def f(x):
    return math.exp(-x**2)+math.cos(x)+3

if __name__ == '__main__':
    
    x = [0.26, 0.88, 1.462, 1.693, 2.458, 2.88, 3.531, 3.858, 4.522, 5.054, 5.464, 6.068, 6.802]
    y = []
    for i in x:
	    y.append(f(i))

cs = lagrange(x,y)

for c in cs:
	print('{:.16f},'.format(c), end=" ")
print()