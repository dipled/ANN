from Python.Interpolacao.methods import *

if __name__ == '__main__':
	

    
    
    x = [0.447, 0.759, 1.582, 1.968, 2.401, 3.43, 3.617, 4.429, 4.899, 5.312, 6.125, 6.863]
    y = [4.721, 4.288, 3.071, 2.634, 2.265, 2.041, 2.111, 2.72, 3.186, 3.564, 3.988, 3.837]
    


    cs = lagrange(x,y)

    for c in cs:
	    print('{:.16f},'.format(c), end=" ")
print()