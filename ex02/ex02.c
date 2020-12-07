#include "util.h"
#include "estoque.h"
#include "arqtxt.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    Tbrinquedo brinquedo;
    Testoque estoque;
    int op;
    inicializarestoque(&estoque);
    lerestoque("estoque.txt", &estoque);
    do 
    {
        limpartela();
        op = menu();
        switch (op)
        {
            case 1:
            if ( lerbrinquedo(&brinquedo, &estoque) == 1 ) inserirbrinquedo(brinquedo, &estoque);
            break;
            case 2: removerbrinquedo(&estoque); break;
            case 3: atualizarbrinquedo(&estoque); break;
            case 4: listarestoque(estoque); break;
            case 5: listarcategoria(estoque); break;
            case 6: listarfiltro(estoque); break;
            case 0: gravarestoque("estoque.txt", estoque); break;
            default: printf("\nInsira um comando valido.\n"); break;
        }
    } while (op != 0);
    return 0;
}