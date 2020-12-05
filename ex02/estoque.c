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

int lerbrinquedo ( Tbrinquedo * a, Testoque * b )
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
            return 0;
        }
    } 
        printf("Insira a categoria do brinquedo: "); limpa(); lerstring( (*a).categoria, TAMCATEGORIA );
        printf("Insira o nome do brinquedo: "); lerstring( (*a).nome, TAMNOME );
        printf("Insira o preco do brinquedo: "); lerdouble( &(*a).preco );
        printf("Insira a quantidade: "); lerint( &(*a).qtd );
        printf("Brinquedo lido com sucesso.\n"); pausartela();
        return 1;
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
    if ( (*a).qtd > 0 )
    {
        limpartela();
        printf("Insira o codigo do brinquedo e a quantidade a ser removida [0 = Remover registro]: "); lerint(&codigo); lerint(&qtd);
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
    }
    else printf("\tNao ha nenhum brinquedo no estoque.\n\n");
    pausartela();
}

void atualizarbrinquedo ( Testoque * a )
{
    int cod, posicao, op, fim=0;
    if ( (*a).qtd > 0 )
    {
        limpartela();
        printf("Insira o codigo do brinquedo a ser atualizado: "); scanf(" %d", &cod);
        posicao = obterindiceestoque(*a, cod);
        if ( posicao > -1 )
        {
            printf("\nQue dado deseja alterar no brinquedo %s?\n\n", (*a).v[posicao].nome);
            printf(
                "\t1. Codigo\n"
                "\t2. Categoria\n"
                "\t3. Nome\n"
                "\t4. Preco\n"
                "\t5. Quantidade\n");
            scanf(" %d", &op); limpa();
            switch (op)
            {
                case 1: 
                        do {
                            printf("\nInsira o novo codigo para o brinquedo: "); scanf(" %d", &cod);
                            if ( obterindiceestoque(*a, cod) == -1 )
                            {
                                (*a).v[posicao].codigo = cod;
                                printf("\nCodigo atualizado com sucesso!\n");
                                fim = 1;
                            }
                            else printf("O codigo inserido ja existe no estoque.\n");
                        } while ( fim != 1 );
                        break;
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
    }
    else printf("\tNao ha nenhum brinquedo no estoque.\n\n");
    pausartela();
}

void listarestoque (Testoque a)
{
    int i;
    if ( a.qtd > 0 )
    {
        limpartela();
        for ( i = 0 ; i < a.qtd ; i++ )
            printf(
                "\tCODIGO: %d\tNOME: %s\n"
                "\tCATEGORIA: %s\n"
                "\tPRECO: %.2lf\tQTD: %d\n\n"
                , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
    }
    else printf("\tNao ha nenhum brinquedo no estoque.\n\n");
    pausartela();
}

void listarcategoria ( Testoque a )
{
    char categoria[TAMCATEGORIA];
    int i, cont=0;
    if ( a.qtd > 0 )
    {
        limpa(); limpartela();
        printf("Insira a categoria a ser listada: "); 
        lerstring( categoria, TAMCATEGORIA );
        printf("\n");
        for ( i = 0 ; i < a.qtd ; i++ )
            if ( strcmp(categoria, a.v[i].categoria) == 0 )
            {
                printf(
                "\tCODIGO: %d\tNOME: %s\n"
                "\tCATEGORIA: %s\n"
                "\tPRECO: %.2lf\tQTD: %d\n\n"
                , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
                cont++;
            }
        if ( cont == 0 ) printf("\tNenhum brinquedo encontrado.\n\n");
    }
    else printf("\tNao ha nenhum brinquedo no estoque.\n\n");
    pausartela();

}

void listarfiltro ( Testoque a )
{
    int op, i, cont=0;
    char dado[TAMCATEGORIA];
    char * pont;
    if ( a.qtd > 0 )
    {
        limpartela();
        printf(
            "\t\tDeseja filtrar usando:\n"
            "\t1. Nome\n"
            "\t2. Categoria\n\n");
        lerint( &op ); limpa();
        switch (op) 
        {
            case 1: 
                printf("Insira o nome a ser buscado: "); lerstring( dado, TAMCATEGORIA );
                printf("\n");
                for ( i = 0 ; i < a.qtd ; i++ )
                {
                    pont = strstr( a.v[i].nome, dado ); 
                    if ( pont != NULL )
                    {
                        printf(
                        "\tCODIGO: %d\tNOME: %s\n"
                        "\tCATEGORIA: %s\n"
                        "\tPRECO: %.2lf\tQTD: %d\n\n"
                        , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
                        cont++;
                    }
                }
                if ( cont == 0 ) printf("\tNenhum brinquedo encontrado.\n\n");
                pausartela();
                break;
            case 2: 
                printf("Insira a categoria a ser buscada: "); lerstring(dado, TAMCATEGORIA );
                printf("\n");
                for ( i = 0 ; i < a.qtd ; i++ )
                {
                    pont = strstr( a.v[i].categoria, dado ); 
                    if ( pont != NULL )
                    {
                        printf(
                        "\tCODIGO: %d\tNOME: %s\n"
                        "\tCATEGORIA: %s\n"
                        "\tPRECO: %.2lf\tQTD: %d\n\n"
                        , a.v[i].codigo, a.v[i].nome, a.v[i].categoria, a.v[i].preco, a.v[i].qtd);
                        cont++;
                    }
                }
                if ( cont == 0 ) printf("\tNenhum brinquedo encontrado.\n\n");
                pausartela();
                break;
        }
    }
    else { printf("\tNao ha nenhum brinquedo no estoque.\n\n"); pausartela(); }
}