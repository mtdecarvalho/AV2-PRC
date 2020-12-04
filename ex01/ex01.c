#include "contatos.h"
#include "util.h"
#include "menu.h"
#include "arqtxt.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    Tcontato contato;
    Tcontatos contatos;
    char nomearq[100] = "agenda.txt";
    int fim = 0;
    inicializarcontatos(&contatos);
    leragenda( nomearq , &contatos );
    do
    {
        switch ( menu() )
        {
            case 1: limpa(); lercontato(&contato, &contatos); inserircontato(contato, &contatos); break;
            case 2: limpa(); removercontato (&contatos); pausartela(); break;
            case 3: limpa(); listarcontatos(contatos); pausartela();  break;
            case 4: limpa(); filtrarcontato(contatos); pausartela(); break;
            case 0: gravaragenda(nomearq, contatos); printf("Encerrando...\n"); fim=1; break;
        }
    }
    while (fim != 1);

    return 0;
}