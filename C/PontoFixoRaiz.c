// Programa usado para encontrar a raiz a partir da funcao g(x) a partir da funcao f(x)
#include <stdio.h>
#include <math.h>
double g(double x);
void fpoint(double x0, int n);
int main()
{
    fpoint(1.0123, 10);
    return 0;
}
double g(double x)
{
    return x / 2.0 + 1.0 / x; // Funcao encontrada a partir de f(x)
}
void fpoint(double x0, int n)
{
    int iterations[] = {250, 2, 3, 4, 5, 6, 7, 8};

    FILE *fp = fopen("out.txt", "w+");

    for (int i = 0; i < n; i += 1)
    {
        x0 = g(x0);
        printf("x_%i = %.16f\n", i + 1, x0);
        if (i + 1 == iterations[i])
        {
            fprintf(fp, "%.16f,", x0);
        }
    }
}