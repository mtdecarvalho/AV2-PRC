#include "jogador.h"

#include "campo.h"

#include <stdio.h>

void inicio () 
{
    limpartela();
    printf("\t\tBem vindo ao jogo da velha!\n"
            "Neste jogo, o X representa o jogador 1 e o O representa o jogador 2.\n"
            "\t\t\tDivirtam-se!\n");
    pausartela();
}

void mudajogador( int * jogador, int area[][4] )
{
    if ( (*jogador) % 2 == 0 && venceu(area) != 1 ) (*jogador)--;
    else if ( (*jogador) % 2 != 0 && venceu(area) != 1) (*jogador)++;
} 

int fimdejogo ( int area[][4], int jogador )
{
    char op;
    imprimircampo(area);
    printf("\n\t\tO jogador %d venceu!\n\n", jogador);
    printf("\tDeseja jogar novamente? [s/n]\n");
    scanf(" %c", &op);
    switch (op)
    {
        case 's': case 'S': esvaziarcampo(area); return 1; break;
        default: printf("\n\tFim de jogo.\n\n"); return 0; break;
    }
}