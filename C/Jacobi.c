#include "stdlib.h"
#include "stdio.h"

#define NUMROWS 3
#define NUMCOLS 4

void jacobi(double E[NUMROWS][NUMCOLS], double chute[NUMROWS], int n);
void print_matrix(double m[NUMROWS][NUMCOLS]);

int main()
{
    double E[NUMROWS][NUMCOLS] =
        {4, 2, -1, 11,
         1, -5, 1, -4,
         1, 1, -6, 9};

    double chute[NUMROWS] = {0,0,0};
    jacobi(E,chute,10);
    return 0;
}
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUMROWS; j++)
        {
            double bj = E[j][NUMCOLS - 1];
            double soma = 0;
            for (int k = 0; k < j; k++)
            { // percorre toda a linha, se não estiver na diagonal...
                if (k != j)
                {
                    soma -= E[j][k] * chute[k];
                }
                double xj = (bj + soma) / E[j][j];
                chute[j] = xj;
                printf("x_ %d (%d)= %.10f",j+1, i+1,xj );
            }
            printf("\n");
        }
    }
}
