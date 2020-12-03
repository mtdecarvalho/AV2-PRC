#include "util.h"
#include "entrada.h"
#include "campo.h"
#include "jogador.h"

#include <stdio.h>

int main ()
{
    int area[4][4];
    int jogador=1;
    do 
    {
        inicio();
        do 
        {
            imprimircampo(area);
            lerentrada(&*area, jogador);
            mudajogador(&jogador, area);
        } while ( venceu(area) != 1 );
    } while ( fimdejogo( area, jogador ) == 1 );
    return 0;
}