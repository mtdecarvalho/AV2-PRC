#include "menu.h"

#include "util.h"

#include <stdio.h>

int menu()
{
    int op;
    limpartela();

        printf("\t\tAGENDA ELETRONICA\n\n"
            "\t1. Inserir contato\n"
            "\t2. Remover contato\n"
            "\t3. Listar todos os contatos\n"
            "\t4. Filtrar contatos\n"
            "\t0. Sair e gravar agenda\n");
        lerint(&op);
        return op;
}