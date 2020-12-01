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

void lerint ( int * linha, int * col)
{
    while ( scanf(" %d %d",&*linha, &*col) != 2 )
    {
        printf("Valores invalidos.\n"); limpa();
    }
}
