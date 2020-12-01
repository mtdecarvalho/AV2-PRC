#include "menu.h"

#include <stdio.h>

int menu ()
{
    int op;
    printf("Bem vindo ao controle de estoque.\n\nO que deseja fazer?\n");
    printf("1. Inserir brinquedo no estoque\n"
           "2. Remover brinquedo(s)\n"
           "3. Atualizar dados de um brinquedo\n"
           "4. Listar todos os brinquedos\n"
           "5. Listar todos de uma categoria\n"
           "6. Listar filtrando por parte do nome ou categoria\n"
           "0. Sair\n");
    lerint( &op );
    return op;
}