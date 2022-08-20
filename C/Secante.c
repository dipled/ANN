#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x); // funcao

void secante(double x0, double x1, int n); // recebe inicio do intervalo, fim do intervalo e numero de repeticoes

int main()
{
    secante(-0.20192, 0.72682, 14);
    return 0;
}
double f(double x)
{
    return 2*(x+1)*(x-0.5)*(x-1);
}
void secante(double x0, double x1, int n)
{
     FILE *fp = fopen("out.txt","w+");
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
        if(i+1==2|i+1==4|i+1==6) //Usado para printar os resultados das iteracoes desejadas
        {
            fprintf(fp,"%.7f,",x1);
        }
        printf("x_%d = %.7f\n", i + 1, x2);
        x0 = x1;
        x1 = x2;
    }
}