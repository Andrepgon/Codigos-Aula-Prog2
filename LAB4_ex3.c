#include <stdio.h>
#include <string.h>
#define MAX 80
int main(int argc, char* argv[])
{
    FILE *pa;
    char *palavra = argv[1];
    char linha[MAX];
    int count_linha = 0;

    if((pa = fopen(argv[2], "r")) == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while(fgets(linha, MAX, pa) != NULL)
    {
        count_linha++;
        if (strstr(linha, palavra))
        {
            printf("%d ", count_linha);
            printf("%s", linha); // Esta linha já termina com '\n', então não precisa adicionar outra quebra
        }
    }
    fclose(pa);
    return 0;
}