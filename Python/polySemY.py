from math import *
from methods import *

def p(x):
	return func_poly(x,coeffs)
def func(x):
    return cos(x)**3+2*cos(x)**2+1
if __name__ == '__main__':
	
    
    #se nao tiver uma lista de y na questao, usar a funcao dada para encontra-la, aplicando os valores de x
    

    
    x = [-2.895, -1.56, -1.051, -0.164, 0.931, 1.516, 2.514, 3.001, 3.954]
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