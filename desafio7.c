#include <stdio.h>
#include <stdlib.h>

#define MAX 52

typedef struct {
    int numero;
    char naipe;
} tCarta;

typedef struct aux {
    tCarta reg;
    struct aux* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO *topo;
} PILHA;

void exibeCarta(tCarta carta) {
    if(carta.numero >= 2 && carta.numero <= 10)
        printf("%d ", carta.numero);
    else {
        switch(carta.numero) {
            case 11: printf("Valete "); break;
            case 12: printf("Dama "); break;
            case 13: printf("Rei "); break;
            case 1:  printf("As "); break;
            default: printf("Invalida "); 
        }
    }
    switch(carta.naipe) {
        case 'o': printf("de Ouros\n"); break;
        case 'c': printf("de Copas\n"); break;
        case 'p': printf("de Paus\n"); break;
        case 'e': printf("de Espadas\n"); break;
        default: printf("Naipe Invalido\n"); break;
    }
}

void empilhaBaralho(PILHA* p) {
    char naipes[4] = {'o', 'c', 'p', 'e'};
    p->topo = NULL;  // Inicializa a pilha

    for(int j = 0; j < 4; j++) {
        for(int i = 1; i <= 13; i++) {
            tCarta carta;
            carta.numero = i;
            carta.naipe = naipes[j];

            ELEMENTO* novo = malloc(sizeof(ELEMENTO));
            novo->reg = carta;
            novo->prox = p->topo;
            p->topo = novo;
        }
    }
}

int buscaCarta(PILHA *p, char naipe, int num) {
    int count = 0;
    ELEMENTO* atual = p->topo;

    while(atual != NULL) {
        count++;
        if(atual->reg.naipe == naipe && atual->reg.numero == num) 
        {
            
            return count - 1; // Retorna o número de cartas descartadas antes da carta encontrada
        }
        atual = atual->prox;
    }
    return -1; // Carta não encontrada
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Modo de uso: ./ex1 <numero> <naipe>\n");
        return -1;
    }

    PILHA p;
    empilhaBaralho(&p);

    tCarta carta_usuario;
    carta_usuario.numero = atoi(argv[1]);  // Converte para int
    carta_usuario.naipe = argv[2][0];  // Pega o primeiro caractere

    // Exibe a carta do usuário
    exibeCarta(carta_usuario);
    
    // Busca a carta na pilha
    int descartadas = buscaCarta(&p, carta_usuario.naipe, carta_usuario.numero);

    // Exibe resultado da busca
    if (descartadas == -1) {
        printf("Sua carta não foi achada\n");
    } else {
        printf("%d cartas descartadas para chegar na sua.\n", descartadas);
    }

    return 0;
}
