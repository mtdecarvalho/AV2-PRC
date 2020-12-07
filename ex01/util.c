#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void lerint ( int * a )
{
    while ( scanf(" %d", &(*a) ) != 1 )
    {
        printf("Valor invalido. Tente novamente: ");
        limpa();
    }
}

void lerstring ( char a[], int tam )
{
    fgets(a, tam, stdin); 
    if (a[strlen(a)-1] == '\n') a[strlen(a)-1] = '\0';
    if ( strlen(a) == tam-1 ) limpa();
}

int ehvazio ( char a[] )
{
    int i, cont=0;
    for ( i = 0 ; i < strlen(a) ; i++ )
        if ( isspace(a[i]) ) cont++;
    if ( cont == strlen(a) ) return 0;
    else return 1;
}
