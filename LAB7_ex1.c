#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int num_casa;
    struct aux* prox;
}ELEMENTO;

typedef struct
{
    ELEMENTO* topo;
}PILHA;


void converter(int num_base10)
{
    PILHA* p = malloc(sizeof(PILHA));
    p->topo = NULL;

    while(num_base10 / 2 != 0)
    {
        int num_base2 = num_base10%2;
        num_base10 /= 2;
        ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
        novo->num_casa = num_base2;
        novo->prox = p->topo;
        p->topo = novo;
    }

    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->num_casa = num_base10;
    novo->prox = p->topo;
    p->topo = novo;

    ELEMENTO* ler;
    printf("Numero na base 2: ");
    ler = p->topo;
    while(ler != NULL)
    {
        printf("%d", ler->num_casa);
        ler = ler->prox;
    }
    printf("\n");
    return;
}

int main()
{
    int num = 159;
    converter(num);
    return 0;
}
