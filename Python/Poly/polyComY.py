from math import *
from methods import *


def p(x):
	return func_poly(x,coeffs)
if __name__ == '__main__':
	
    
    #se nao tiver uma lista de y na questao, usar a funcao dada para encontra-la, aplicando os valores de x
    #se ele pedir o valor de p(x) depois de achar os coeficientes, basta printar p(x) para os valores
    
        
    x = [0.242, 0.69, 1.055, 1.537, 1.915, 2.489, 2.97, 3.459, 3.69]
    y = [0.617, 1.049, 1.475, 1.921, 1.965, 1.044, 0.045, 0.704, 1.501]
    values = [0.279, 0.283, 0.326, 0.685]
    




    coeffs = poly(x,y)
    print("Coefs:")

for x in (coeffs):
	print("%.16f," %x)

print("Aproximacoes de p(x)")

for i in values:
    print("%.16f," %p(i))
    