#include "arqtxt.h"

#include "contatos.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerAte(FILE *arq, char sep, char strdest[], int max)
{
    int i=0;
    int letra;
    while ( (letra = fgetc(arq)) > 0 && letra!=sep && i<max-1)
    {
        strdest[i] = letra;
        i++;
    }
    strdest[i] = '\0'; //terminador da string
    return strdest;
}
void leragenda (char nomearq[], Tcontatos * a)
{
    int cont=0;
    FILE *arq;
    arq = fopen(nomearq, "rt");
    if (arq!=NULL)
    {
        //(*a).qtd = 0;
        Tcontato b;
        while ( !feof(arq) )
        {
            lerAte(arq, ',' , b.nome, TAMNOME );
            lerAte(arq, ',', b.email, TAMEMAIL);
            lerAte(arq, '\n', b.telefone, TAMTEL);
            if ( validaremail(b.email, *a) == 1 && validartelefone(b.telefone) == 1 ) inserircontato(b, &*a);
            else cont++;
        }
        if ( cont != 0 ) { printf("Um ou mais contatos invalidos foram ignorados.\n"); pausartela(); }
        else { printf("Todos os contatos foram inseridos com sucesso!\n"); pausartela(); }
    } else { printf("Arquivo nao encontrado.\n"); pausartela(); }
}

void gravaragenda (char nomearq[], Tcontatos a)
{
    FILE *arq; 
    arq = fopen(nomearq, "wt");
    if ( arq!= NULL )
    {
        int i; 
        for ( i = 0 ; i < a.qtd ; i++ )
        {
            Tcontato b = a.v[i];
            if ( i == a.qtd-1 ) fprintf(arq, "%s,%s,%s", b.nome, b.email, b.telefone);
            else fprintf(arq, "%s,%s,%s\n", b.nome, b.email, b.telefone);
        }
        fclose(arq);
    }
}