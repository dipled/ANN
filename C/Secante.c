#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x); // funcao

void secante(double x0, double x1, int n); // recebe inicio do intervalo, fim do intervalo e numero de repeticoes

int main()
{
    secante(0.83 ,3.73, 50);
    return 0;
}
double f(double x)
{
    return (24000*pow(x,2)-220480*x+332343)/2000;
}
void secante(double x0, double x1, int n)
{
    int iterations[] = {1, 2, 5};
    int i2 = 0;
    FILE *fp = fopen("out.txt", "w+");
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
        if (i + 1 == iterations[i2])
        {
            i2 += 1;
            fprintf(fp, "%.16f,", x2);
        }
        printf("x_%d = %.16f\n", i + 1, x2);
        x0 = x1;
        x1 = x2;
    }
}