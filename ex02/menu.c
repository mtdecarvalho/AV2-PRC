#include "menu.h"

#include <stdio.h>

int menu ()
{
    int op;
    printf("\t\tBem vindo ao controle de estoque.\n\t\t\tO que deseja fazer?\n\n");
    printf("\t1. Inserir brinquedo no estoque\n"
           "\t2. Remover brinquedo(s)\n"
           "\t3. Atualizar dados de um brinquedo\n"
           "\t4. Listar todos os brinquedos\n"
           "\t5. Listar todos de uma categoria\n"
           "\t6. Listar filtrando por parte do nome ou categoria\n"
           "\t0. Sair\n");
    lerint( &op );
    return op;
}