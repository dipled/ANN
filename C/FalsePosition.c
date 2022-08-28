#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x);

void fpos(double a, double b, int n); // Recebe lim. esq. e dir. do intervalo e n de iteracoes

int main()
{
    fpos(0.49,17.01, 100);
    return 0;
}

double f(double x)
{
return -7.97+sqrt(2*9.81*x)*tanh(sqrt(2*9.81*x)/(2*6.08)*6.94);}

void fpos(double a, double b, int n)
{
    int iterations[] = {2,4,7,11};
    int i2 = 0;
    FILE *fp = fopen("out.txt", "w+");
    double fa = f(a);
    double fb = f(b);
    if (fa * fb >= 0)
    {
        printf("Falhou o teorema de Bolzano\n");
        return;
    }
    for (int i = 0; i < n; i += 1)
    {
        double x = (a * fb - b * fa) / (fb - fa);
        printf("x_%d = %.16f\n", i + 1, x);
        if (i + 1 == iterations[i2]) // Usado para printar os resultados das iteracoes desejadas
        {
            i2+=1;
            fprintf(fp, "%.16f,", x);
        }
        double fx = f(x);
        if (fx == 0)
        {
            printf("Raiz: %.16f\n", x);
            return;
        }
        else
        {
            if (fa * fx < 0)
            {
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
    }
}
