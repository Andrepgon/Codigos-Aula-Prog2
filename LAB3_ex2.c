#include <stdio.h>
#include <stdlib.h>

int **aloca_linhas(int linhas);
void aloca_colunas (int **matriz, int linhas, int colunas);
void le_dados(int **matriz, int linhas, int colunas);
void imprime_matriz(int **matriz, int linhas, int colunas);
void troca_linhas (int **matriz, int linha1, int linha2);


int main (void) 
{
    int **matriz;
    int linha1, linha2;
    int lin, col;

    puts("Qual o numero de linhas?");
    scanf("%d",&lin);
    matriz = aloca_linhas(lin);

    puts("Qual o numero de colunas?");
    scanf("%d",&col);

    printf("Alocando espaço para linhas.\n");
    aloca_colunas(matriz, lin, col);

    le_dados(matriz, lin, col);
    imprime_matriz(matriz, lin, col);

    puts("Qual a primeira linha a ser trocada?");
    scanf("%d",&linha1);
    puts("Qual a segunda linha a ser trocada?");
    scanf("%d",&linha2);
    troca_linhas(matriz, linha1, linha2);
    imprime_matriz(matriz, lin, col);
    return 0;
}

int **aloca_linhas(int linhas)
{
    int **matriz;
    matriz = (int **) malloc(linhas*sizeof(int*)); 
    return matriz;
}

void aloca_colunas (int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        *(matriz + i) = (int *) malloc(colunas*sizeof(int)); 
    }
}

void le_dados(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o termo [%d][%d]: ", i, j);
            scanf("%d", *(matriz + i)+j);
        } 
    }
}

void imprime_matriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", *(*(matriz+i)+j));
        } 
        printf("\n");
    }       
}

void troca_linhas (int **matriz, int linha1, int linha2)
{
    int *temp = *(matriz+linha1);
    *(matriz+linha1) = *(matriz+linha2);
    *(matriz+linha2) = temp;
}
