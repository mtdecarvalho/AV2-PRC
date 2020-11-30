#include <stdio.h>

int main ()
{
    int area[4][4];
    int linha, col, i, k, cont;
    do 
    {
        for (i = 1 ; i <= 3 ; i++ )
        {
            for (k = 1; k <= 3; k++)
            {
                if ( area[i][k] == 1 )
                    printf("X ");
                else 
                    printf("  ");
            }
        printf("\n");
        }
        printf("Onde colocar o cursor, jogador 1?\n");
        do
        {
            scanf("%d %d",&linha, &col);
        } while ( linha > 3 || col > 3 || area[linha][col] == 1);
        area[linha][col] = 1;
     } while (linha != -1) ;
    return 0;
}