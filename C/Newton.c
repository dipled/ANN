#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); // funcao

double df(double x); // derivada

void newton(double x0, int n); // recebe x inicial, numero de repeticoes
int main()
{
    newton(3.36207885, 200);
    return 0;
}

double f(double x)
{
    return x*(x-1.0)*(x-2.0)+0.42;
}
double df(double x)
{
    return 3.0*(x*x)-6.0*x+2.0;
}

void newton(double x0, int n)
{
    FILE *fp = fopen("out.txt","w+");
    for (int i = 0; i < n; i += 1)
    {
        double dfx0 = df(x0);
        if (dfx0 == 0)
            break;
        double x1 = x0 - (f(x0) / dfx0);
        if(i+1 == 5 |i+1 == 10|i+1 == 15|i+1 == 20|i+1 == 25|i+1 == 30|i+1 == 35|i+1 == 40|i+1 == 45|i+1 == 50|i+1 == 55|i+1 == 60|i+1 == 65|i+1 == 70|i+1 == 75|i+1 == 80|i+1 == 85|i+1 == 90|i+1 == 95|i+1 == 100|i+1 == 105|i+1 == 110|i+1 == 115|i+1 == 120|i+1 == 125|i+1 == 130|i+1 == 135|i+1 == 140|i+1 == 145|i+1 == 150|i+1 == 155|i+1 == 160|i+1 == 165|i+1 == 170|i+1 == 175|i+1 == 180|i+1 == 185|i+1 == 190|i+1 == 195    ) //Usado para printar os resultados das iteracoes desejadas
        {
            fprintf(fp,"%.7f,",x1);
        }
        printf("x_%d = %.7f\n", i + 1, x1);
        x0 = x1;
    }
}