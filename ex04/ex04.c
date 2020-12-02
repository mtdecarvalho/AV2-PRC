#include "util.h"
#include "conjuntos.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    Tconjunto A, B;
    int i;
    inicializarconjunto(&A); inicializarconjunto(&B); 
    printf("\tConjunto A\n"); lerconjunto(&A);
    printf("\n\tConjunto B\n"); lerconjunto(&B);
    printf("\n\tAUB\n\n"); uniao(A, B);
    printf("\n\tAeB\n\n"); intersecao(A, B);
    printf("\n\tA-B\n\n"); diferenca(A, B);
    return 0;
}