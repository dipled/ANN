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
    bissec(1.7649, 5.8697, 39, 0, 0);
    return 0;
}
double func(double x)
{

    return x*x-3.793*x+1.7444;
}
void bissec(double a, double b, int n, double tolF, double tolIn)
{
    FILE *f = fopen("out.txt","w+");
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
        if(i+1 == 2 | i+1 == 3|i+1 == 4|i+1 == 5|i+1 == 6|i+1 == 7)//Usado para printar os resultados das iteracoes desejadas
        {
            fprintf(f,"%.7f,",m);
        }
        printf("x%d = %.7f\n",i+1,m);
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
