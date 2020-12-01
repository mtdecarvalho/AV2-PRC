#include "util.h"

#include <stdlib.h>
#include <stdio.h>

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
