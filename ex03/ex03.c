#include "util.h"

#include <stdio.h>

int venceu ( int a[][4] )
{
    int i, k, cont1, cont2, venceu=0;
    for ( i = 1 ; i <= 3 && venceu != 1 ; i++ )
        for ( k = 1, cont1 = 0, cont2 = 0 ; k <= 3 ; k++ )
        {
            if ( a[i][k] == 1 ) cont1++;
            else if ( a[i][k] == 2 ) cont2++;
            if ( cont1 == 3 || cont2 == 3) venceu=1;
        }
    for ( i = 1 ; i <= 3 && venceu != 1 ; i++ )
        for ( k = 1, cont1 = 0, cont2 = 0 ; k <= 3 ; k++ )
        {
            if ( a[k][i] == 1 ) cont1++;
            else if ( a[k][i] == 2 ) cont2++;
            if ( cont1 == 3 || cont2 == 3 ) venceu=1;
        }
    if ( venceu != 1 && (a[1][1] == 1 && a[2][2] == 1 && a[3][3] == 1) || (a[1][1] == 2 && a[2][2] == 2 && a[3][3] == 2) ) venceu=1;
    else if ( venceu != 1 && (a[1][3] == 1 && a[2][2] == 1 && a[3][1] == 1) || (a[1][3] == 2 && a[2][2] == 2 && a[3][1] == 2) ) venceu=1;

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
            if ( k == 1 ) printf("\t\t");
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

int verificaentrada ( int area[][4], int linha, int col )
{
    if ( area[linha][col] == 1 || area[linha][col] == 2 ) { printf("\t\tEspaco ja ocupado.\n"); return 0; } 
    else if ( linha > 3 || linha < 1 || col > 3 || col < 1  ) { printf("\t\tValor fora do alcance!\n\tInsira apenas valores entre 1 e 3.\n"); return 0; }
    else return 1;
}

int main ()
{
    int area[4][4];
    int linha, col, i, k, jogador=1;
    do 
    {
        imprimircampo(area);
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
        
        if ( jogador % 2 == 0 && venceu(area) != 1 ) jogador--;
        else if ( jogador % 2 != 0 && venceu(area) != 1) jogador++;

    } while ( venceu(area) != 1 );

    imprimircampo(area);
    printf("\n\tO jogador %d venceu!\n\n", jogador);
    
    return 0;
}