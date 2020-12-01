#ifndef _CONTATOS_H_
#define _CONTATOS_H_

#include "util.h"

#define TAMEMAIL 50
#define TAMTEL 10
#define TAMNOME 30
#define MAX 100

typedef struct 
{
    char nome[TAMNOME], email[TAMEMAIL], telefone[TAMTEL];
} Tcontato;

typedef struct 
{
    Tcontato v[MAX];
    int qtd;
} Tcontatos;

void inicializarcontatos (Tcontatos * a);
int obterindiceemail (Tcontatos a, char dado[]);
int validartelefone ( char a[] );
void lercontato (Tcontato * a);
void inserircontato (Tcontato a, Tcontatos * b);
void filtrarcontato (Tcontatos a);
void listarcontatos (Tcontatos a);
void removercontato (Tcontatos * a);

#endif