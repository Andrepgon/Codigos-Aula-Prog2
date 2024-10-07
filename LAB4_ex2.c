#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if(!(argc < 3))
    {
        printf("Erro no terminal.");
        return 1;
    }

    FILE *pentrada;
    FILE *psaida;
    int c;

    if((pentrada = fopen(argv[1], "r")) == NULL )
    {
        // Mensagem de erro detalhada
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }
    if((psaida = fopen(argv[2], "w+")) == NULL )
    {
        // Mensagem de erro detalhada
        perror("Erro ao abrir o arquivo de saida");
        return 1;
    }

    c = fgetc(pentrada);
    while(c != EOF)
    {
        c = toupper(c);
        fputc(c, psaida);
        c = fgetc(pentrada);
    }

    rewind(psaida);
    c = fgetc(psaida);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(psaida);
    }
    fclose(pentrada);
    fclose(psaida);
    return 0;
}