#include "menu.h"

#include "util.h"

#include <stdio.h>

int menu()
{
    int op;
    limpartela();

        printf("\t\tAGENDA ELETRONICA\n"
            "\t1. Inserir contato\n"
            "\t2. Inserir contato via arquivo\n"
            "\t3. Remover contato\n"
            "\t4. Listar todos os contatos\n"
            "\t5. Filtrar contatos\n"
            "\t6. Gravar agenda em arquivo\n"
            "\t0. Sair\n");
        lerint(&op);
        return op;
}