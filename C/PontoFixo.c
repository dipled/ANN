// Programa para achar o ponto fixo
#include <stdio.h>
#include <math.h>
double f(double x);
void fpoint(double x0, int n);
int main()
{
    fpoint(1.36485, 10);
    return 0;
}
double f(double x)
{
    return ((3 * pow(x, 4) + 2 * pow(x, 2) + 3) / (4 * pow(x, 3) + 4 * x - 1));
}
void fpoint(double x0, int n)
{
    int iterations[] = {1, 2, 3, 4, 5, 6, 7, 8};

    FILE *fp = fopen("out.txt", "w+");
    for (int i = 0; i < n; i += 1)
    {
        double x1 = f(x0);
        printf("x_%i = %.16f\n", i + 1, x1);
        x0 = x1;
        if (i + 1 == iterations[i])
        {
            fprintf(fp, "%.16f,", x1);
        }
    }
}