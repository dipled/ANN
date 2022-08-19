#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);
                                                                   // numero maximo de iteracoes = |b-a|/tol
void bissec(double a, double b, int n, double tolF, double tolIn); // limite esquerdo do intervalo, limite direito do intervalo,
                                                                   // numero de iteracoes, tolerancia do valor de y, 
                                                                   //tolerancia do intervalo
int main()
{
    bissec(3.300878, 4.213126, 50, 0, 2.10923 * pow(10, -13));
    return 0;
}
double func(double x)
{

    return x * x * x - 7 * x * x + 14 * x - 7;
}
void bissec(double a, double b, int n, double tolF, double tolIn)
{
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
            printf("Raiz da funcao encontrada: %.7f", m);
            return;
        }
        if (fabs(fm) <= tolF)
        {
            printf("Raiz aproximada (tolerancia m) encontrada x%d = %.7f\n", i + 1, m);
            return;
        }
        if (fabs(b - a) <= tolIn)
        {
            printf("Raiz aproximada (tolerancia intervalo) encontrada x%d = %.7f\n", i + 1, m);
            return;
        }
        if (i == n - 1)
        {
            printf("Raiz aproximada (numero de iteracoes) encontrada x%d = %.7f\n", i + 1, m);
            return;
        }
        // printf("x%d = %.7f\n",i+1,m);
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
