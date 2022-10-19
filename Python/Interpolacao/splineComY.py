from Python.Interpolacao.methods import *
from math import *

def s(x):
	for key, value in eqs.items():
		if value['domain'][0] <= x <= value['domain'][1]:
			return eval(value['eq'])

if __name__ == '__main__':
    
   
    x = [0.421, 0.688, 1.386, 2.241, 2.816, 2.997, 3.673, 4.565, 4.962, 5.559, 5.96, 6.923]
    y = [4.819, 4.469, 3.388, 2.664, 2.773, 2.849, 3.118, 3.477, 4.085, 4.145, 4.318, 4.022]
    valores = [0.61, 1.132, 1.622, 1.925, 5.683]
    eqs = []
    eqs = (spline(x, y))
    print("Valores s(x):")  
    for valor in valores:
    	print('{:.16f},'.format(s(valor)), end=" ")
print()