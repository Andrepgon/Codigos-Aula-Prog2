#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func
{
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;

Tfunc* inicializa(int quantidade);
Tfunc* inclui_novos(Tfunc *vetor_func, int quantidade_inicial, int extras);
void imprime(Tfunc *vetor_func, int inicio, int max_func);

int main(void)
{
    Tfunc *cadastro;
    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    scanf("%d", &funcionarios);
    getchar(); // Consome o newline deixado por scanf

    cadastro = inicializa(funcionarios); // Alterado para não passar 'cadastro'

    if (!cadastro)
    {
        return -1;
    }

    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d", &adicionais);
    getchar(); // Consome o newline deixado por scanf
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);

    if (!cadastro)
    {
        return -1;
    }

    printf("Lista de funcionarios cadastrados\n");
    imprime(cadastro, 0, funcionarios + adicionais);
    free(cadastro);
    return 0;
}

Tfunc* inicializa(int quantidade)
{
    Tfunc *vetor_func = (Tfunc *) malloc(sizeof(Tfunc) * quantidade);
    if (!vetor_func)
    {
        printf("Erro na alocação de memória!\n");
        return NULL; // Verifica se a alocação foi bem-sucedida
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Qual o nome do funcionario %d: ", i + 1);
        fgets((*(vetor_func + i)).nome, sizeof((*(vetor_func + i)).nome), stdin);
        printf("Qual ano de nascimento do funcionario %d: ", i + 1);
        scanf("%d", &(*(vetor_func + i)).ano_nasc);
        printf("Qual o salario do funcionario %d: ", i + 1);
        scanf("%f", &(*(vetor_func + i)).renda);
        getchar(); // Consome o newline deixado por scanf
    }

    return vetor_func;
}

Tfunc* inclui_novos(Tfunc *vetor_func, int quantidade_inicial, int extras)
{
    for (int i = 0; i < extras; i++)
    {
        printf("Qual o nome do funcionario %d: ", i + 1 + quantidade_inicial);
        fgets((*(vetor_func + quantidade_inicial + i)).nome, sizeof((*(vetor_func + quantidade_inicial + i)).nome), stdin);
        printf("Qual ano de nascimento do funcionario %d: ", i + 1 + quantidade_inicial);
        scanf("%d", &(*(vetor_func + quantidade_inicial + i)).ano_nasc);
        printf("Qual o salario do funcionario %d: ", i + 1 + quantidade_inicial);
        scanf("%f", &(*(vetor_func + quantidade_inicial + i)).renda);
        getchar(); // Consome o newline deixado por scanf
    }
    return vetor_func;
}

void imprime(Tfunc *vetor_func, int inicio, int max_func)
{
    for (int i = inicio; i < max_func; i++)
    {
        printf("Dados do funcionario %d \n", i + 1);
        printf("Nome: %s", (*(vetor_func + i)).nome);
        printf("Ano de nascimento: %d \n", (*(vetor_func + i)).ano_nasc);
        printf("Salario: %.2f \n", (*(vetor_func + i)).renda);
        printf("\n");
    }
}3
