from methods import *

def f(x):
    return x**2 * math.exp(-x) * math.cos(x) + 1

k = 5 # ordem da derivada
n = 15 # número de pontos

x0 = 4.0358
x = [3.8039, 3.8381, 3.8812, 3.894, 3.9268, 3.9848, 4.0102, 4.0444, 4.0585, 4.0905, 4.1423, 4.1798, 4.219, 4.2449, 4.2737]



y = [f(xi) for xi in x]

coeffs = coeffs_dif_fin(x0, x, k)
aprox = dif_fin(coeffs, y)

print('Coefs:')
for i in coeffs:
    print(i,',')
print('Aproximacao:')
print(f'{aprox}')