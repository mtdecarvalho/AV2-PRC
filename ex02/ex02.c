#include "util.h"
#include "estoque.h"
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
    do 
    {
        limpartela();
        op = menu();
        switch (op)
        {
            case 1: lerbrinquedo(&brinquedo, &estoque); inserirbrinquedo(brinquedo, &estoque); break;
            case 2: removerbrinquedo(&estoque); break;
            case 3: atualizarbrinquedo(&estoque); break;
            case 4: listarestoque(estoque); break;
            case 5: listarcategoria(estoque); break;
            case 6: listarfiltro(estoque); break;
        }
    } while (op != 0);
    return 0;
}