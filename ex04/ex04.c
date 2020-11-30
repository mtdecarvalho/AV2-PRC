#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double v[100];
    int qtd;
} Tconjunto;

typedef struct
{
    double v[200];
    int qtd;
} Tuniao;

void limpartela()
{
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}

void pausartela()
{
    #ifdef __unix__
        system("read -r -p \"Pressione qualquer tecla...\" key");
    #elif _WIN32
        system("pause");
    #elif _WIN64
        system("pause");
    #endif
}

void limpa()
{
    while ((getchar()) != '\n');
}

void lerdouble ( double * a )
{
    while ( scanf(" %lf", &(*a) ) != 1 )
    {
        printf("O elemento inserido eh invalido. Tente novamente.\n");
        limpa();
    }
}

void imprimirconjunto ( Tconjunto X )
{
    int i, cont=0;
    for ( i = 0 ; i < X.qtd ; i++ )
    {
        if ( X.v[i] != 0 )
            printf("%lf\n", X.v[i]);
        else cont++;
    }
    if ( cont == X.qtd ) printf("N/A\n");
}

void imprimiruniao ( Tuniao X )
{
    int i, cont=0;
    for ( i = 0 ; i < X.qtd ; i++ )
    {
        if ( X.v[i] != 0 )
            printf("%lf\n", X.v[i]);
        else cont++;
    }
    if ( cont == X.qtd ) printf("N/A\n");
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
    int i, k;
    AUB.qtd = 0;
    for ( i = 0 ; i < A.qtd ; i++ )
    {
        AUB.v[i] = A.v[i]; AUB.qtd++;
    }
    for ( k = A.qtd, i = 0 ; i < B.qtd ; k++, i++ )
    {
        AUB.v[k] = B.v[i]; AUB.qtd++;
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
    int i, k, j;
    AdifB.qtd=0;
    AdifB = A;
    for ( i = 0 ; i < AdifB.qtd ; i++ )
        for ( k = 0 ; k < B.qtd ; k++ )
            if ( AdifB.v[i] == B.v[k] )
                AdifB.v[i] = 0;
    for ( i = 0 ; i < AdifB.qtd ; i++ )
        if ( AdifB.v[i] == 0 )
        {
            AdifB.v[i] = AdifB.v[AdifB.qtd-1];
            AdifB.qtd--;
        }
    if ( AdifB.qtd == 0 ) AdifB.v[0] = 0;
    imprimirconjunto(AdifB);
}

int main ()
{
    Tconjunto A, B;
    int i;
    inicializarconjunto(&A); inicializarconjunto(&B); 
    printf("\tConjunto A\n"); lerconjunto(&A);
    printf("\n\tConjunto B\n"); lerconjunto(&B);
    printf("\n\tAUB\n"); uniao(A, B);
    printf("\n\tAeB\n"); intersecao(A, B);
    printf("\n\tA-B\n"); diferenca(A, B);
    return 0;
}