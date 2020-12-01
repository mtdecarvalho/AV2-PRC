#ifndef _CONJUNTOS_H_
#define _CONJUNTOS_H_

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

void imprimirconjunto ( Tconjunto X );
void imprimiruniao ( Tuniao X );
void inicializarconjunto ( Tconjunto * X );
int validarconjunto ( Tconjunto X, double valor );
void lerconjunto ( Tconjunto * X );
void uniao ( Tconjunto A, Tconjunto B );
void intersecao ( Tconjunto A, Tconjunto B );
void diferenca ( Tconjunto A, Tconjunto B );

#endif