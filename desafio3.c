#include <stdio.h>
#include <stdlib.h>

int main() {
    int L, C, M, N;

    // Leitura dos valores
    printf("Digite os valores, respectivamente de L, C, M, N: ");
    scanf("%d %d %d %d", &L, &C, &M, &N);

    // Verificação das condições
    if (L % M != 0 || C % N != 0) {
        printf("Os tamanhos nao correspondem ao do seu leopoldo\n");
        return -1;
    }

    // Aloca a matriz plantacao
    int **plantacao = malloc(L * sizeof(int *));

    for (int i = 0; i < L; i++) 
    {
        plantacao[i] = malloc(C * sizeof(int));
    
        for (int j = 0; j < C; j++) 
        {
            int valor; // número de margaridas
            scanf("%d", &valor);
            plantacao[i][j] = valor;
        }
    }

    // Calcula o número máximo de margaridas em um lote M x N
    int max_margaridas = 0;

    for (int i = 0; i <= L - M; i++) 
    {
        for (int j = 0; j <= C - N; j++) 
        {
            int soma = 0;
            for (int mi = 0; mi < M; mi++) 
            {
                for (int nj = 0; nj < N; nj++) 
                {
                    soma += plantacao[i + mi][j + nj];
                }
            }
            if (soma > max_margaridas) 
            {
                max_margaridas = soma;
            }
        }
    }

    // Imprime o número máximo de margaridas em um lote
    printf("%d\n", max_margaridas);

    // Libera a memória alocada
    for (int i = 0; i < L; i++) {
        free(plantacao[i]);
    }
    free(plantacao);

    return 0;
}
