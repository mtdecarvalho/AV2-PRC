#include "contatos.h"
#include "uteis.h"
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
    char nomearq[100];
    int fim = 0;
    inicializarcontatos(&contatos);
    do
    {
        switch ( menu() )
        {
            case 1: limpa(); lercontato(&contato); inserircontato(contato, &contatos); break;
            case 2: limpa(); printf("Insira o nome do arquivo a ser lido: "); lerstring( nomearq, 100 );
            leragenda(nomearq, &contatos); break;
            case 3: limpa(); removercontato (&contatos); break;
            case 4: limpa(); listarcontatos(contatos); pausartela();  break;
            case 5: limpa(); filtrarcontato(contatos); pausartela(); break;
            case 6: limpa(); printf("Insira um nome para o arquivo: "); lerstring( nomearq, 100 );
            gravaragenda(nomearq, contatos); break;
            case 0: printf("Encerrando...\n"); fim=1; break;
        }
    }
    while (fim != 1);

    return 0;
}