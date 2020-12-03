#include "conjuntos.h"

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

void imprimirconjunto ( Tconjunto X )
{
    int i, cont=0;
    for ( i = 0 ; i < X.qtd ; i++ )
    {
        if ( X.v[i] != 0 )
            printf("\t%.2lf\n", X.v[i]);
        else cont++;
    }
    if ( cont == X.qtd ) printf("\tN/A\n");
}

void imprimiruniao ( Tuniao X )
{
    int i, cont=0;
    for ( i = 0 ; i < X.qtd ; i++ )
    {
        if ( X.v[i] != 0 )
            printf("\t%.2lf\n", X.v[i]);
        else cont++;
    }
    if ( cont == X.qtd ) printf("\tN/A\n");
}

void inicializarconjunto ( Tconjunto * X )
{
    (*X).qtd = 0;
}

int validarconjunto ( Tconjunto X, double valor )
{
    int i;
    if ( valor == 0 ) return 2;
    for ( i = 0 ; i < X.qtd ; i++ )
        if ( valor == X.v[i] ) return 0;
    return 1;
}

void lerconjunto ( Tconjunto * X )
{
    int i, k;
    double valor = 1;
    printf("Para terminar a leitura, digite 0.\n");
    for ( i = 0 ; i < 100 && valor != 0 ; i++ )
    {
        lerdouble(&valor);
        while ( validarconjunto( *X, valor ) == 0 )
        {
            printf("O elemento inserido eh repetido ou invalido. Tente novamente.\n"); limpa(); scanf(" %lf", &valor);
        }
        if ( validarconjunto( *X, valor ) == 1 ) { (*X).v[i] = valor; (*X).qtd++; }
        else if ( validarconjunto( *X, valor ) == 2 ) break;
    }
}

void uniao ( Tconjunto A, Tconjunto B )
{
    Tuniao AUB;
    int i, k, entra;
    AUB.qtd = 0;
    for ( i = 0 ; i < A.qtd ; i++ )
    {
        AUB.v[i] = A.v[i]; AUB.qtd++;
    }
    for ( i = 0 ; i < B.qtd ; i++ )
    {
        for ( k = 0 ; k < AUB.qtd && entra != 0 ; k++)
        {
            if ( B.v[i] == AUB.v[k] ) entra = 0;
            else entra = 1;
        }
        if ( entra == 1 ) { AUB.qtd++; AUB.v[AUB.qtd-1] = B.v[i]; } 
    }
    imprimiruniao(AUB);
}

void intersecao ( Tconjunto A, Tconjunto B )
{
    Tconjunto AeB;
    int i, k, j=0;
    AeB.qtd=0;
    for ( i = 0 ; i < A.qtd ; i++ )
        for ( k = 0 ; k < B.qtd ; k++)
            if ( A.v[i] == B.v[k] )
            {    AeB.v[j] = A.v[i]; AeB.qtd++; j++;  }
    imprimirconjunto(AeB);
}

void diferenca ( Tconjunto A, Tconjunto B )
{
    Tconjunto AdifB;
    int i, k, entra;
    AdifB.qtd=0;
    AdifB = A;
    for ( i = 0 ; i < B.qtd ; i++ )
        for ( k = 0 ; k < AdifB.qtd ; k++ )
            if ( AdifB.v[k] == B.v[i] ) { AdifB.v[k] = AdifB.v[AdifB.qtd-1]; AdifB.qtd--; }
    if ( AdifB.qtd == 0 ) AdifB.v[0] = 0;
    imprimirconjunto(AdifB);
}
