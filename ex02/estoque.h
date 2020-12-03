#ifndef _ESTOQUE_H_
#define _ESTOQUE_H_

#include "util.h"

#define TAMCATEGORIA 20
#define TAMNOME 30

typedef struct 
{
    int codigo, qtd;
    char categoria[TAMCATEGORIA], nome[TAMNOME];
    double preco;
} Tbrinquedo;

typedef struct
{
    Tbrinquedo v[100];
    int qtd;
} Testoque;

void inicializarestoque ( Testoque * a );
int obterindiceestoque ( Testoque a, int codigo );
int lerbrinquedo ( Tbrinquedo * a, Testoque * b );
void inserirbrinquedo ( Tbrinquedo a, Testoque * b );
void removerbrinquedo ( Testoque * a );
void atualizarbrinquedo ( Testoque * a );
void listarestoque (Testoque a);
void listarcategoria ( Testoque a );
void listarfiltro ( Testoque a );

#endif