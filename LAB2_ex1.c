#include <stdio.h>

void aumento(int *salario, int percentual);

int main()
{
    int *salario, dinheiro, percentual;
    printf("Digite o salario atual e o percentual de aumento: ");
    scanf("%d %d", &dinheiro,&percentual);
    salario = &dinheiro;

    aumento(salario, percentual);

    printf("Seu salario com aumento: %d\n", dinheiro);
    return 0;
}

void aumento(int *salario, int percentual)
{
    float percentualF = percentual/100.0;
    int temp = *salario + *(salario)*percentualF;
    *salario = temp;
}
