from methods import *

def f(x):
    return x**2 * math.exp(-x) * math.cos(x) + 1

k = 5 # ordem da derivada
n = 15 # número de pontos

x0 = -0.2415
x = [-0.4646, -0.4295, -0.4217, -0.3669, -0.3522, -0.2946, -0.261, -0.2328, -0.2242, -0.187, -0.1434, -0.1099, -0.0633, -0.0419, -0.0008]



y = [f(xi) for xi in x]

coeffs = coeffs_dif_fin(x0, x, k)
aprox = dif_fin(coeffs, y)

print('Coefs:')
for i in coeffs:
    print(i,',')
print('Aproximacao:')
print(f'{aprox}')