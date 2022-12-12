from methods import *

def f(x):
    return  x**2 * math.exp(-x) * math.cos(x) + 1
x0 = 0.6883
order = 5
x = [3.8039, 3.8381, 3.8812, 3.894, 3.9268, 3.9848, 4.0102, 4.0444, 4.0585, 4.0905, 4.1423, 4.1798, 4.219, 4.2449, 4.2737]
values = [4.0358,4.0358,4.0358,4.0358,4.0358]

order1 = 1
order2 = 2
order3 = 3
order4 = 4
order5 = 5

p = 0
n = len(values)
for i in range(n):
    p = f(x0) + finite_diffs(x, order1, x0, f)*(values[i] - x0) + ((finite_diffs(x, order2, x0, f)/2) * ((values[i]-x0)**2)) + ((finite_diffs(x, order3, x0, f)/6) * ((values[i]-x0)**3)) + ((finite_diffs(x, order4, x0, f)/24) * ((values[i]-x0)**4)) + ((finite_diffs(x, order, x0, f)/120) * ((values[i]-x0)**5)) 
    erroN = math.sqrt(((f(values[i]) - p)**2))
    print(f'{p}, {erroN}', end=", ")
print("")
