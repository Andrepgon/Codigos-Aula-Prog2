#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hora, minuto;
}t_momento;

void tempoatual(int percorrido, t_momento*momento);

int main(int argc, char* argv[])
{
    int hora1, minuto1;
    int hora2, minuto2;
 
    int t_percorrido;
    t_momento t;
    t_momento *pt = &t;
    int num = atoi(argv[1]);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &hora1, &minuto1);
        scanf("%d %d", &hora2, &minuto2);
        scanf("%d", &t_percorrido);

        if(hora1 < 0 || hora1 > 23 || minuto1 < 0 || minuto1 > 59)
        {
            return -1;
        }
        if(hora2 < 0 || hora2 > 23 || minuto2 < 0 || minuto1 > 59)
        {
            return -1;
        }
        if(t_percorrido > 24*60 - 1 || t_percorrido < 0)
        {
            return -1;
        }

        tempoatual(t_percorrido, pt);
        printf("tempo atual: %02d:%02d \n", t.hora, t.minuto);
        if(abs(hora1 - t.hora) <= abs(hora2 - t.hora))
        {
            printf("%02d:%02d \n", hora1, minuto1);
        }
        else
        {
            printf("%02d:%02d \n", hora2, minuto2);
        }
    }
    return 0;
}

void tempoatual(int percorrido, t_momento*momento)
{
    int hora_atual = percorrido / 60;

    int minuto_atual = percorrido - hora_atual*60;

    momento->hora = hora_atual;
    momento->minuto = minuto_atual;
}
