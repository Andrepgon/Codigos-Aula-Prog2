#include <stdio.h>

int max_index(int *vetor_inteiro, int tamanho);

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho];
    
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int indice = max_index(vetor, tamanho);
    printf("O indice eh: %d\n", indice);
    return 0;
}

int max_index(int *vetor_inteiro, int tamanho)
{
    if (tamanho == 0) 
    {
        return -1; // Caso o vetor esteja vazio
    }
    int maior = *vetor_inteiro;
    int indice_maior = 0;

    for (int i = 1; i < tamanho; i++) // Começamos de 1, já que 0 foi inicializado
    {
        if (*(vetor_inteiro + i) > maior)
        {
            maior = *(vetor_inteiro + i);
            indice_maior = i;
        }
    }

    return indice_maior;
}
