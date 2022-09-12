#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROWS 4
#define COLS 3
void swapLine(double matrix[ROWS][COLS]){
    float temp;
    printf("Digite a primeira linha\n");
    int Line1;
    scanf("%d", &Line1);
    Line1--;
    printf("Digite a segunda linha\n");
    int Line2;
    scanf("%d", &Line2);
    Line2--;
    for(int i = 0; i < COLS; i++){
        temp = matrix[Line1][i];
        matrix[Line1][i] = matrix[Line2][i];
        matrix[Line2][i] = temp;
    }
}
void printMatrix(double matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i += 1)
    {
        for (int j = 0; j < COLS; j += 1)
        {
            printf("%.9lf, ", matrix[i][j]);
        }
        printf("\n");
    }
}
void operaLinha(double matrix[ROWS][COLS])
{
 
    printf("Digite a linha de destino\n");
    int destino;
    scanf("%d", &destino);
    destino -= 1;
    printf("Digite a linha a ser multiplicada\n");
    int i;
    scanf("%d", &i);
    i--;
    printf("Digite o escalar da linha\n");
    double valor;
    scanf("%lf",&valor);
    for (int j = 0; j < COLS; j += 1)
    {
        matrix[destino][j] = valor * matrix[i][j];
    }
}
void operaLinhaLinha(double matrix[ROWS][COLS])
{
    printf("Digite a linha de destino\n");
    int destino;
    scanf("%d", &destino);
    destino -= 1;
    printf("Digite a primeira linha\n");
    int i;
    scanf("%d", &i);
    i--;
    printf("Digite o escalar da primeira linha\n");
    double valor;
    scanf("%lf", &valor);
    printf("Digite a segunda linha\n");
    int i2;
    scanf("%d", &i2);
    i2--;
    printf("Digite o escalar da segunda linha\n");
    double valor2;
    scanf("%lf", &valor2);

    for (int j = 0; j < COLS; j += 1)
    {
        matrix[destino][j] = valor * matrix[i][j] + valor2 * matrix[i2][j];
    }
}
void opera(double matrix[ROWS][COLS])
{
    int escolha = 5;
    while (escolha != 0)
    {
        printf("Digite:\n1 para somar duas linhas\t\t\t2 para trocar duas linhas de lugar\n3 para multiplicar uma linha por um escalar\t0 para sair\n\n");
         printMatrix(matrix);
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            operaLinhaLinha(matrix);
            break;
        case 2:
            swapLine(matrix);
            break;
        case 3:
            operaLinha(matrix);
            break;
        case 0:
            return;

        default:
            break;
        }
    }
}
int main()
{
    double matrix[ROWS][COLS];
    FILE *fr = fopen("matriz.txt", "r+");
    for (int i = 0; i < ROWS; i += 1)
    {
        for (int j = 0; j < COLS; j += 1)
        {
            fscanf(fr, "%lf, ", &matrix[i][j]);
        }
    }
    fclose(fr);
    opera(matrix);
    FILE *fw = fopen("matriz.txt", "w+");
    for (int i = 0; i < ROWS; i += 1)
    {
        for (int j = 0; j < COLS; j += 1)
        {
            fprintf(fw, "%.9lf, ", matrix[i][j]);
        }
        fprintf(fw, "\n");
    }
    fclose(fw);

    return 0;
}