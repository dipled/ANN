#include <stdlib.h>
#include <stdio.h>

#define NUMROWS 4
#define NUMCOLS 5

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
}
void jacobi(double E[NUMROWS][NUMCOLS], double chute[NUMROWS], int n)
{
    int iterations[] = {7, 8, 11, 12, 15, 17, 18 ,19};
    int i2 = 0;
    int achou = 0;
    FILE *fp = fopen("out.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        double resp[NUMROWS] = {};
        for (int j = 0; j < NUMROWS; j++)
        {
            double bj = E[j][NUMCOLS - 1];
            double soma = 0;
            for (int k = 0; k < NUMCOLS - 1; k++)
            {
                if (k != j)
                {
                    soma += E[j][k] * chute[k];
                }
            }
            double xj = (bj - soma) / E[j][j];
            resp[j] = xj;
            if (i+1 == iterations[i2])
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
        for (int i = 0; i < NUMROWS; i++)
        {
            chute[i] = resp[i];
        }
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

    double chute[NUMROWS] = {-2.64, -4.63, -3.14};
    jacobi(E, chute, 30);
    print_matrix(E);
    return 0;
}