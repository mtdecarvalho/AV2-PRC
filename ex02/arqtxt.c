#include "arqtxt.h"

#include "estoque.h"
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
void lerestoque (char nomearq[], Testoque * a)
{
    FILE *arq;
    arq = fopen(nomearq, "rt");
    if (arq!=NULL)
    {
        (*a).qtd = 0;
        Tbrinquedo b;
        while ( !feof(arq) )
        {
            fscanf( arq, "%d,", &b.codigo);
            lerAte(arq, ',' , b.categoria, TAMCATEGORIA );
            lerAte(arq, ',', b.nome, TAMNOME );
            fscanf( arq, "%lf,", &b.preco );
            fscanf( arq, "%d", &b.qtd );
            if ( obterindiceestoque(*a, b.codigo) == -1 ) inserirbrinquedo(b, &*a);
        }
    }
}

void gravarestoque (char nomearq[], Testoque a)
{
    FILE *arq; 
    arq = fopen(nomearq, "wt");
    if ( arq!= NULL )
    {
        int i; 
        for ( i = 0 ; i < a.qtd ; i++ )
        {
            Tbrinquedo b = a.v[i];
            if ( i == a.qtd-1 ) fprintf(arq, "%d,%s,%s,%.2lf,%d", b.codigo, b.categoria, b.nome, b.preco, b.qtd);
            else fprintf(arq, "%d,%s,%s,%.2lf,%d\n", b.codigo, b.categoria, b.nome, b.preco, b.qtd);
        }
        fclose(arq);
    }
}