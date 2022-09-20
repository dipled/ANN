from methods import *
from math import *
def func(x):
    return cos(x + sqrt(log(x**2)))
if __name__ == '__main__':
	

    
    x = [1.505, 1.698, 2.025, 2.21, 2.418, 2.642, 2.907, 3.217, 3.521, 3.624, 3.893, 4.217, 4.455, 4.623, 4.952]

    y = []
    for i in x:
        y.append(func(i))    


    coeffs = divDiff(x, y)

    for coeff in coeffs:
    	print("%.16f,"%coeff)
