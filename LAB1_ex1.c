#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

int ocorrencia(char* s1, char* s2);

int main()
{
    char* st1 = malloc(MAX);
    char* st2 = malloc(MAX);

    printf("Digite a String 1: ");
    fgets(st1, MAX, stdin);

    printf("Digite a String 2: ");
    fgets(st2, MAX, stdin);

    printf("%d\n", ocorrencia(st1, st2));

    free(st1);
    free(st2);

    return 0;
}

int ocorrencia(char* s1, char* s2)
{
    
    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    

    for (int i = 0; i <= len1 - len2; i++) 
    {
        int j;
        for (j = 0; j < len2; j++) 
        {
            if (tolower(s1[i + j]) != tolower(s2[j]))
            {
                break;
            }
        }

        if (j == len2)
        {
            return 1;
        }
    }
    return 0;
}
