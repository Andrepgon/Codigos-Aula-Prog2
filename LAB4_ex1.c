#include <stdio.h>
#include <ctype.h>

int main()
{
    char* texto = "texto.txt";
    FILE* pa;
    int c;
    int contagemA = 0, contagemE = 0, contagemI = 0, contagemO = 0, contagemU = 0;

    // Tentativa de abrir o arquivo
    if((pa = fopen(texto, "r")) == NULL )
    {
        // Mensagem de erro detalhada
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    c = fgetc(pa);
    while(c != EOF)
    {
        c = tolower(c);
        if(c == 'a')
        {   
            contagemA++;
        }
        else if(c == 'e')
        {   
            contagemE++;
        }
        else if(c == 'i')
        {   
            contagemI++;
        }
        else if(c == 'o')
        {   
            contagemO++;
        }
        else if(c == 'u')
        {   
            contagemU++;
        }
        c = fgetc(pa);
    }

    // Exibição das contagens
    printf("a %d \n", contagemA);
    printf("e %d \n", contagemE);
    printf("i %d \n", contagemI);
    printf("o %d \n", contagemO);
    printf("u %d \n", contagemU);

    // Fecha o arquivo
    fclose(pa);

    return 0;
}
