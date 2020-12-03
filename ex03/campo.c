#include "campo.h"

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
    printf("\t\t    | 1 | 2 | 3 |\n");
    for (i = 1 ; i <= 3 ; i++ )
    {   
        for (k = 1; k <= 3; k++)
        {
            if ( k == 1 ) printf("\t\t  %d |", i);
            if ( area[i][k] == 1 )
                printf(" X ");
            else if ( area[i][k] == 2 )
                printf(" O ");
            else 
                printf("   ");
            printf ("|");
        }
    printf("\n");
    }
    printf("\n");
}

void esvaziarcampo ( int area[][4] )
{
    int i, k;
    for ( i = 1 ; i < 4 ; i++ )
        for ( k = 1 ; k < 4 ; k++)
            area[i][k] = 0;
}