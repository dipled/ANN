#include "stdlib.h"
#include "stdio.h"

#define NUMROWS 4
#define NUMCOLS 5
// so funciona para sistema n x n

void print_matrix(double m[NUMROWS][NUMCOLS])
{
    for (int i = 0; i < NUMROWS; i++)
    {
        for (int j = 0; j < NUMCOLS; j++)
        {
            printf("%.8f\t", m[i][j]);
        }
        printf("\n");
    }
} // so funciona para sistemas n x n
void seildel(double E[NUMROWS][NUMCOLS], double chute[NUMROWS], int n)
{
    int iterations[] = {4, 6, 8, 12, 13, 14, 16, 19};
    int i2 = 0;
    int achou = 0;
    FILE *fp = fopen("out.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUMROWS; j++)
        {
            double bj = E[j][NUMCOLS - 1];
            double soma = 0;
            for (int k = 0; k < NUMCOLS - 1; k++)
            { // percorre toda a linha, se não estiver na diagonal...
                if (k != j)
                {
                    soma += E[j][k] * chute[k];
                }
            }
            double xj = (bj - soma) / E[j][j];
            chute[j] = xj;
            if (i + 1 == iterations[i2])
            {
                fprintf(fp, "%.16f,\t", xj);
                achou = 1;
            }
        }
        if (achou == 1)
        {
            i2 += 1;
            achou = 0;
        }
        printf("\n");
    }
}

int main(void)
{
    double E[NUMROWS][NUMCOLS];
     FILE *fr = fopen("matriz.txt", "r+");
    for (int i = 0; i < NUMROWS; i += 1)
    {
        for (int j = 0; j < NUMCOLS; j += 1)
        {
            fscanf(fr, "%lf, ", &E[i][j]);
        }
    }
    print_matrix(E);

    double chute[NUMROWS] = {-4.19, 4.29, 2.25, -2.58};
    seildel(E, chute, 30);
    return 0;
}