from methods import *
from math import *
def func(x):
    return 1/(1+25*x**2)
if __name__ == '__main__':
	
    
    
    
    x = [-0.914, -0.756, -0.55, -0.37, -0.199, -0.136, 0.141, 0.267, 0.372, 0.564, 0.765, 0.873]


    y = []
    for i in x:
        y.append(func(i))



    eqs = spline(x, y)