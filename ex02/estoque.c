#include "estoque.h"

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCATEGORIA 20
#define TAMNOME 30

void inicializarestoque ( Testoque * a )
{  
    (*a).qtd = 0;
}

int obterindiceestoque ( Testoque a, int codigo )
{
    int achou=0, i=0;
    while (achou == 0 && i < a.qtd)
    {
        if ( codigo == a.v[i].codigo )
            achou = 1;
        else
            i++;
    }
    return achou == 1 ? i : -1;
}

void lerbrinquedo ( Tbrinquedo * a, Testoque * b )
{
    int posicao = (*b).qtd, i, fim=0;
    limpartela();
    printf("Insira o codigo do brinquedo: "); lerint( &(*a).codigo );
    for (i = 0 ; i < posicao ; i++ )
    {
        if ( (*b).v[i].codigo == (*a).codigo ) // ja existe no estoque
        {
            printf("O codigo informado ja existe no estoque. Insira a quantidade a ser adicionada ao brinquedo: ");
            scanf(" %d", &(*a).qtd );
                (*b).v[i].qtd += (*a).qtd;
            printf("Quantidade adicionada ao estoque com sucesso.\n"); pausartela();
            fim = 1;
        }
    } 
    if ( fim == 0 )
    {
        printf("Insira a categoria do brinquedo: "); limpa(); lerstring( (*a).categoria, TAMCATEGORIA );
        printf("Insira o nome do brinquedo: "); lerstring( (*a).nome, TAMNOME );
        printf("Insira o preco do brinquedo: "); lerdouble( &(*a).preco );
        printf("Insira a quantidade: "); lerint( &(*a).qtd );
        printf("Brinquedo lido com sucesso.\n"); pausartela();
    }
}

void inserirbrinquedo ( Tbrinquedo a, Testoque * b )
{
    int posicao = (*b).qtd, i;
    (*b).v[posicao] = a;
    (*b).qtd++;
}

void removerbrinquedo ( Testoque * a )
{
    int codigo, posicao, qtd;
    limpartela();
    printf("Insira o codigo do brinquedo e a quantidade a ser removida [0 = Remover registro]: "); lerint(&codigo); lerint(&qtd);
    //scanf(" %d %d", &codigo, &qtd);
    posicao = obterindiceestoque(*a, codigo);
    if ( posicao > -1 )
    {
        if ( qtd == 0 )
        {
            (*a).v[ posicao ] = (*a).v[ (*a).qtd-1 ];
            (*a).qtd--;
            printf("Brinquedo removido do estoque com sucesso.\n");
        }
        else if ( qtd > 0 )
        {
            if ( qtd <= (*a).v[posicao].qtd )
            {
                (*a).v[posicao].qtd-=qtd;
                printf("Quantidade removida com sucesso.\n");
            }
            else 
                printf("A quantidade inserida eh invalida.\n");
        }
    }
    else 
    {
        printf("Nenhum brinquedo foi encontrado com o codigo inserido.\n");
    }
    pausartela();
}

void atualizarbrinquedo ( Testoque * a )
{
    int cod, posicao, op;
    limpartela();
    printf("Insira o codigo do brinquedo a ser atualizado: "); scanf(" %d", &cod);
    posicao = obterindiceestoque(*a, cod);
    if ( posicao > -1 )
    {
        printf("\nQue dado deseja alterar no brinquedo %s?\n\n", (*a).v[posicao].nome);
        printf(
            "1. Codigo\n"
            "2. Categoria\n"
            "3. Nome\n"
            "4. Preco\n"
            "5. Quantidade\n");
        scanf(" %d", &op); limpa();
        switch (op)
        {
            case 1: printf("\nInsira o novo codigo para o brinquedo: "); lerint( &(*a).v[posicao].codigo ); 
                    printf("\nCodigo atualizado com sucesso!\n"); break;
            case 2: printf("\nInsira a nova categoria para o brinquedo: "); lerstring( (*a).v[posicao].categoria, TAMCATEGORIA );
                    printf("\nCategoria atualizada com sucesso!\n"); break;
            case 3: printf("\nInsira o novo nome para o brinquedo: "); lerstring( (*a).v[posicao].nome, TAMNOME );
                    printf("\nNome atualizado com sucesso!\n"); break;
            case 4: printf("\nInsira o novo preco para o brinquedo: "); lerdouble( &(*a).v[posicao].preco );
                    printf("\nPreco atualizado com sucesso!\n"); break;
            case 5: printf("\nInsira a nova quantidade para o brinquedo: "); lerint( &(*a).v[posicao].qtd );
                    printf("\nQuantidade atualizada com sucesso!\n"); break;
        }
    }
    else
    {
        printf("\nNenhum brinquedo foi encontrado com o codigo inserido.\n");
    }
    pausartela();
}

void listarestoque (Testoque a)
{
    int i;
    limpartela();
    for ( i = 0 ; i < a.qtd ; i++ )
        printf(
            "CODIGO: %d\tNOME: %s\n"
            "CATEGORIA: %s\n"
            "PRECO: %.2lf\tQTD: %d\n\n"
            , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
    pausartela();
}

void listarcategoria ( Testoque a )
{
    char categoria[TAMCATEGORIA];
    int i;
    limpa(); limpartela();
    printf("Insira a categoria a ser listada: "); 
    lerstring( categoria, TAMCATEGORIA );
    for ( i = 0 ; i < a.qtd ; i++ )
        if ( strcmp(categoria, a.v[i].categoria) == 0 )
            printf(
            "CODIGO: %d\tNOME: %s\n"
            "CATEGORIA: %s\n"
            "PRECO: %.2lf\tQTD: %d\n\n"
            , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
    pausartela();
}

void listarfiltro ( Testoque a )
{
    int op, i;
    char dado[TAMCATEGORIA];
    char * pont;
    limpartela();
    printf("Deseja filtrar usando:\n"
        "1. Nome\n"
        "2. Categoria\n\n");
    lerint( &op ); limpa();
    switch (op) 
    {
        case 1: 
            printf("Insira o nome a ser buscado: "); lerstring( dado, TAMCATEGORIA );
            for ( i = 0 ; i < a.qtd ; i++ )
            {
                pont = strstr( a.v[i].nome, dado ); 
                if ( pont != NULL )
                    printf(
                    "CODIGO: %d\tNOME: %s\n"
                    "CATEGORIA: %s\n"
                    "PRECO: %.2lf\tQTD: %d\n\n"
                    , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
            }
            pausartela();
            break;
        case 2: 
            printf("Insira a categoria a ser buscada: "); lerstring(dado, TAMCATEGORIA );
            for ( i = 0 ; i < a.qtd ; i++ )
            {
                pont = strstr( a.v[i].categoria, dado ); 
                if ( pont != NULL )
                    printf(
                    "CODIGO: %d\tNOME: %s\n"
                    "CATEGORIA: %s\n"
                    "PRECO: %.2lf\tQTD: %d\n\n"
                    , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
            }
            pausartela();
            break;
    }
}