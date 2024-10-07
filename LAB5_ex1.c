#include <stdio.h>
#include <string.h>

#define MAX 50
int main()
{
    FILE *parq;
    char nome[MAX];
    float P1, P2, T;
    int num_alunos;
    char arquivo[MAX];

    printf("Digite o numero de alunos: ");
    scanf("%d", &num_alunos);
    getchar();
    printf("Digite o nome do arquivo: ");
    fgets(arquivo, MAX, stdin);
    arquivo[strlen(arquivo) - 1] = '\0';
    

    if(!(parq = fopen(arquivo, "w")))
    {
        perror("Erro na abertura de arquivo");
        return 1;
    }

    for(int i = 0; i < num_alunos; i++)
    {
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(nome, MAX, stdin);
        nome[strlen(nome) - 1] = '\0';
        printf("Digite a nota da P1 do aluno %d: ", i+1);
        scanf("%f", &P1);
        printf("Digite a nota da P2 do aluno %d", i+1);
        scanf("%f", &P2);
        printf("Digite a nota do Trablho do aluno %d", i+1);
        scanf("%f", &T);
        getchar();
        fprintf(parq, "%s %.2f %.2f %.2f\n", nome, P1, P2, T);
    }
    
}