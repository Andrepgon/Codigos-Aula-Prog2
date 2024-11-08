#include <stdio.h>
#include <string.h>

typedef struct pessoa 
{
    char nome[30];
    int idade;
} Tpessoa;

void merge_sort(Tpessoa grupo[], int ini, int fim);
void merge(Tpessoa grupo[], int esquerda, int direita, int meio);
void print_array(Tpessoa grupo[], int tam);

int main()
{
    int tam;
    scanf("%d", &tam);
    Tpessoa pessoas[tam];
    
    for(int i = 0; i < tam; i++)
    {
        scanf("%s %d", pessoas[i].nome, &pessoas[i].idade);
    }

    merge_sort(pessoas, 0, tam - 1);
    print_array(pessoas, tam);
    return 0;
}

void merge(Tpessoa grupo[], int esquerda, int direita, int meio)
{
    int tam_metade_um = meio - esquerda + 1;  
    int tam_metade_dois = direita - meio;   

    Tpessoa array_esquerdo[tam_metade_um];
    Tpessoa array_direito[tam_metade_dois];

    // Copiar os dados para os arrays temporários
    for (int i = 0; i < tam_metade_um; i++)
    {
        array_esquerdo[i] = grupo[esquerda + i];
    }
    for(int j = 0; j < tam_metade_dois; j++)
    {
        array_direito[j] = grupo[meio + 1 + j];  
    }

    int i = 0, j = 0, k = esquerda;

    // Mesclar as duas metades
    while(i < tam_metade_um && j < tam_metade_dois)
    {      
        if (strcmp(array_esquerdo[i].nome, array_direito[j].nome) < 0)
        {
            grupo[k] = array_direito[j];  
            j++;
        } 
        else 
        {
            grupo[k] = array_esquerdo[i];
            i++;
        }
        k++;
    }

    // Copiar os elementos restantes da metade esquerda, se houver
    while (i < tam_metade_um) 
    {
        grupo[k] = array_esquerdo[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes da metade direita, se houver
    while (j < tam_metade_dois) 
    {
        grupo[k] = array_direito[j];
        j++;
        k++;
    }
}

void merge_sort(Tpessoa grupo[], int ini, int fim)
{
    if(ini < fim) 
    {
        int meio = (ini + fim) / 2;

        merge_sort(grupo, ini, meio);
        merge_sort(grupo, meio + 1, fim);

        merge(grupo, ini, fim, meio);
    }   
}

void print_array(Tpessoa grupo[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%s: %d anos\n", grupo[i].nome, grupo[i].idade);  // Corrigido para formatar a saída corretamente
    }
}
