#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); // funcao

double df(double x); // derivada

void newton(double x0, int n); // recebe x inicial, numero de repeticoes
int main()
{
    newton(1.86, 200);
    return 0;
}

double f(double x)
{
return -7.97+sqrt(2*9.81*x)*tanh(sqrt(2*9.81*x)/(2*6.08)*6.94);}
double df(double x)
{
    return 2.21472*tanh(2.52799*sqrt(x))/sqrt(x)+5.5988*1/(cosh(2.52799*sqrt(x)));
}

void newton(double x0, int n)
{
    int iterations[] = {1,3,5};
    int i2 = 0;
    FILE *fp = fopen("out.txt", "w+");
    for (int i = 0; i < n; i += 1)
    {
        double dfx0 = df(x0);
        if (dfx0 == 0)
            break;
        double x1 = x0 - (f(x0) / dfx0);
        if (i + 1 == iterations[i2])
        {
            i2+= 1;
            fprintf(fp, "%.16f,", x1);
        }
        printf("x_%d = %.16f\n", i + 1, x1);
        x0 = x1;
    }
}