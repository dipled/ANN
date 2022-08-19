#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); // funcao

double df(double x); // derivada

void newton(double x0, int n); // recebe x inicial, numero de repeticoes
int main()
{
    newton(10, 5);
    return 0;
}

double f(double x)
{
    return x * x - 2;
}
double df(double x)
{
    return 2 * x;
}

void newton(double x0, int n)
{
    for (int i = 0; i < n; i += 1)
    {
        double dfx0 = df(x0);
        if (dfx0 == 0)
            break;
        double x1 = x0 - (f(x0) / dfx0);
        printf("x_%d = %.7f\n", i + 1, x1);
        x0 = x1;
    }
}