#include "util.h"

#include <stdio.h>

int venceu ( int a[][4] )
{
    int i, cont, venceu;
    for ( i = 1, cont = 0 ; i <= 3 ; i++ )
    {
        if ( a[1][i] == 1 ) cont++;
        if ( cont == 3 ) venceu=1;
    }
    for ( i = 1, cont = 0 ; i <= 3 ; i++ )
    {
        if ( a[i][1] == 1 ) cont++;
        if ( cont == 3 ) venceu=1;
    }
    for ( i = 1, cont = 0 ; i <= 3 ; i++ )
    {
        if ( a[i][i] == 1 ) cont++;
        if ( cont == 3 ) venceu=1;
    }
    return venceu;
}

void imprimircampo( int area[][4] )
{
    int i, k;
    limpartela();
    printf("\n");
    for (i = 1 ; i <= 3 ; i++ )
    {
        for (k = 1; k <= 3; k++)
        {
            if ( k == 1 ) printf("\t");
            if ( area[i][k] == 1 )
                printf(" X ");
            else if ( area[i][k] == 2 )
                printf(" O ");
            else 
                printf("   ");
            if ( k != 3 ) printf ("|");
        }
    printf("\n");
    }
    printf("\n");
}

int main ()
{
    int area[4][4];
    int linha, col, i, k, jogador=1;
    do 
    {
        imprimircampo(area);
        printf("Onde colocar o cursor, jogador %d?\n", jogador);
        do
        {
            lerint(&linha, &col);
            if ( area[linha][col] == 1 || area[linha][col] == 2 ) printf("Espaco ja ocupado.\n");
        } while ( linha == 0 || col == 0 || linha > 3 || col > 3 || area[linha][col] == 1 || area[linha][col] == 2 );
        
        if ( jogador == 1 ) area[linha][col] = 1;
        else area[linha][col] = 2;
        
        if ( jogador % 2 == 0 && venceu(area) != 1 ) jogador--;
        else if ( jogador % 2 != 0 && venceu(area) != 1) jogador++;

    } while ( venceu(area) != 1 );

    imprimircampo(area);
    printf("\n\tO jogador %d venceu!\n", jogador);
    
    return 0;
}