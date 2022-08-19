#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x); // funcao

void secante(double x0, double x1, int n); // recebe inicio do intervalo, fim do intervalo e numero de repeticoes

int main()
{
    secante(-2, 3, 14);
    return 0;
}
double f(double x)
{
    return x * x - 2;
}
void secante(double x0, double x1, int n)
{
    for (int i = 0; i < n; i += 1)
    {
        double fx0 = f(x0);
        double fx1 = f(x1);
        if (fx0 == fx1)
        {
            printf("Divisao por zero na iteracao %d\n", i + 1);
            break;
        }
        double x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
        printf("x_%d = %.7f\n", i + 1, x2);
        x0 = x1;
        x1 = x2;
    }
}