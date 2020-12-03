#include "entrada.h"

#include "util.h"

#include <stdio.h>

int verificaentrada ( int area[][4], int linha, int col )
{
    if ( linha > 3 || linha < 1 || col > 3 || col < 1  ) { printf("\t\tValor fora do alcance!\n\tInsira apenas valores entre 1 e 3.\n"); return 0; }
    else if ( area[linha][col] == 1 || area[linha][col] == 2 ) { printf("\t\tEspaco ja ocupado.\n"); return 0; } 
    else return 1;
}

void lerentrada ( int area[][4], int jogador )
{
    int linha, col;
    printf("\tOnde colocar o cursor, jogador %d?\n", jogador);
        printf("Insira a linha [1-3] e a coluna [1-3], respectivamente.\n");
        do
        {
            lerint(&linha, &col);
            //verificaentrada(area, linha, col);
        } while //( linha == 0 || col == 0 || linha > 3 || col > 3 || area[linha][col] == 1 || area[linha][col] == 2 );
        ( verificaentrada(area, linha, col) != 1 );
        if ( jogador == 1 ) area[linha][col] = 1;
        else area[linha][col] = 2;
}