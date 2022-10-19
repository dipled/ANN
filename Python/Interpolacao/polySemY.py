from math import *
from Python.Interpolacao.methods import *

def p(x):
	return func_poly(x,coeffs)
def func(x):
    return cos(x+sqrt(log(x**2)))
if __name__ == '__main__':
	
    
    #se nao tiver uma lista de y na questao, usar a funcao dada para encontra-la, aplicando os valores de x
    

    
    x = [1.515,1.895,2.247,2.644,2.823,3.16,3.426,3.77,4.086,4.61,4.792]
    values = [-2.307, -1.838, -1.311, 1.664, 2.636]


    y = []
    for i in x:
        y.append(func(i))

    coeffs = poly(x,y)
    print("Coefs:")
for x in (coeffs):
	print("%.16f," %x)

print("|f(x)-p(x)|:")
for i in values:
    print("%.16f," %abs(func(i)-p(i)))