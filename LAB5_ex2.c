#include <stdio.h>
#include <string.h>
#define MAX 50
int main()
{
    FILE *parq_entrada;
    FILE *parq_saida;
    char arquivo_entrada[MAX];
    char arquivo_saida[MAX];

    printf("Digite o nome do arquivo de entrada: ");
    fgets(arquivo_entrada, MAX, stdin);
    arquivo_entrada[strlen(arquivo_entrada)-1] = '\0';
    printf("Digite o nome do arquivo de saida: ");
    fgets(arquivo_saida, MAX, stdin);
    arquivo_saida[strlen(arquivo_saida)-1] = '\0';

    if(!(parq_entrada = fopen(arquivo_entrada, "r")))
    {
        perror("Erro ao abrir o arquivo de entrada.");
        return 1;
    }
    if(!(parq_saida = fopen(arquivo_saida, "w")))
    {
        perror("Erro ao abrir o arquivo de saida.");
        return 1;
    }

    float media, P1, P2, T;
    char nome[MAX];

    while(fscanf(parq_entrada, " %49s %f %f %f", nome, &P1, &P2, &T) == 4)
    {
        media = (((P1+P2)/2)*0.8)+(T*0.2);
        fprintf(parq_saida, "%s %.1f \n", nome, media);
    }



}