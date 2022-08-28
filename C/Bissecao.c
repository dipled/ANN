#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x); // funcao
// numero maximo de iteracoes = |b-a|/tol
void bissec(double a, double b, int n, double tolF, double tolIn); // recebe limite esquerdo e direito do intervalo,
                                                                   // numero de iteracoes, tolerancia do valor de y,
                                                                   // tolerancia do intervalo

int main()
{
    bissec(0.24,17.97, 39, 0, 0);
    return 0;
}
double func(double x)
{

    return -7.97+sqrt(2*9.81*x)*tanh(sqrt(2*9.81*x)/(2*6.08)*6.94);
}
void bissec(double a, double b, int n, double tolF, double tolIn)
{
    int iterations[] = {2,4,8,12};
    int i2 = 0;

    FILE *f = fopen("out.txt", "w+");
    double fa = func(a), fb = func(b);
    if ((fa * fb) == 0)
    {
        printf("Erro, falhou devido ao teorema de Bolzano");
        return;
    }
    for (int i = 0; i < n; i += 1)
    {
        double m = (a + b) / 2.0;
        double fm = func(m);
        if (fm == 0)
        {
            printf("Raiz da funcao encontrada: %.16f", m);
            return;
        }
        if (fabs(fm) <= tolF)
        {
            printf("Raiz aproximada (tolerancia m) encontrada x%d = %.16f\n", i + 1, m);
            return;
        }
        if (fabs(b - a) <= tolIn)
        {
            printf("Raiz aproximada (tolerancia intervalo) encontrada x%d = %.16f\n", i + 1, m);
            return;
        }
        if (i == n - 1)
        {
            printf("Raiz aproximada (numero de iteracoes) encontrada x%d = %.16f\n", i + 1, m);
            return;
        }
        if (i + 1 == iterations[i2])
        {
            i2+= 1;
            fprintf(f, "%.16f,", m);
        }
        printf("x%d = %.16f\n", i + 1, m);
        if (fm * fa < 0)
        {
            b = m;
        }
        else
        {
            a = m;
        }
    }
}
