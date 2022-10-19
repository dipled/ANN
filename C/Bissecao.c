#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); // funcao
// numero maximo de iteracoes = |b-a|/tol
void bissec(double a, double b, int n, double tolF, double tolIn); // recebe limite esquerdo e direito do intervalo,
                                                                   // numero de iteracoes, tolerancia do valor de y,
                                                                   // tolerancia do intervalo

int main()
{
    bissec(0,4.46, 200, 0, 0);
    return 0;
}
double f(double x)
{
    return (24000*pow(x,2)-220480*x+332343)/2000;
}
void bissec(double a, double b, int n, double tolF, double tolIn)
{
    int iterations[] = {2, 4, 8, 12};
    int i2 = 0;

    FILE *fp = fopen("out.txt", "w+");
    double fa = f(a), fb = f(b);
    if ((fa * fb) == 0)
    {
        printf("Erro, falhou devido ao teorema de Bolzano");
        return;
    }
    for (int i = 0; i < n; i += 1)
    {
        double m = (a + b) / 2.0;
        double fm = f(m);
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
            i2 += 1;
            fprintf(fp, "%.16f,", m);
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
