#include "contatos.h"

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMEMAIL 50
#define TAMTEL 10
#define TAMNOME 30
#define MAX 100

void inicializarcontatos (Tcontatos * a)
{
    (*a).qtd = 0;
}

int obterindiceemail (Tcontatos a, char dado[])
{
    int i = 0;
    int achou = 0;
    while (achou == 0 && i<a.qtd)
    {
        if ( strcmp(a.v[i].email, dado) == 0 )
            achou = 1;
        else
            i++;
    }
    return achou==1 ? i : -1;
}

int validartelefone ( char a[] )
{
    int i;
    for ( i = 0 ; i < strlen(a) ; i++ )
        if ( !isdigit(a[i]) )
            return 0;
    return 1;
}

int validaremail ( char a[], Tcontatos b )
{
    if ( b.qtd == 0 ) return 1;
    else 
    {
        if ( obterindiceemail( b, a ) != -1 ) return 0;
        else return 1;
    }
}

void lercontato (Tcontato * a, Tcontatos * agenda )
{
    limpartela();
    printf("Insira o nome do contato: "); lerstring( (*a).nome, TAMNOME );

    do {
        printf("Insira o email do contato: "); lerstring( (*a).email, TAMEMAIL );
        if ( validaremail( (*a).email, (*agenda) ) != 1 ) printf("O email ja existe na agenda.\n");
    } while ( validaremail ( (*a).email, (*agenda) ) != 1 );

    do {
        printf("Insira o numero de telefone do contato: "); lerstring( (*a).telefone, TAMTEL );
        if ( validartelefone( (*a).telefone ) != 1 ) printf("O conteudo inserido nao eh um numero.\n");
    } while ( validartelefone( (*a).telefone ) != 1 );

    printf("Contato lido com sucesso!\n"); pausartela();
}

void inserircontato (Tcontato a, Tcontatos * b)
{
    (*b).v[(*b).qtd] = a;
    (*b).qtd++;
}

void filtrarcontato (Tcontatos a)
{
    int op, i, tel;
    char dado[TAMEMAIL];
    char * pont;
    if ( a.qtd > 0 )
    {
        limpartela();
        printf(
        "Deseja buscar o contato usando parte de que dado?\n"
        "1. Nome\n"
        "2. Email\n"
        "3. Telefone\n");
        lerint(&op); limpa();
        switch (op)
        {
            case 1:
                printf("Insira parte do nome: "); lerstring( dado, TAMNOME );
                for ( i = 0 ; i < a.qtd ; i++ ) 
                {
                    pont = strstr( a.v[i].nome, dado ); 
                    if ( pont != NULL )
                        printf(
                        "Nome: %s\n"
                        "Email: %s\n"
                        "Telefone: %s\n"
                        , a.v[i].nome, a.v[i].email, a.v[i].telefone);
                }
                break;
            case 2:
                printf("Insira parte do email: "); lerstring( dado, TAMEMAIL );
                for ( i = 0 ; i < a.qtd ; i++ ) 
                {
                    pont = strstr( a.v[i].email, dado ); 
                    if ( pont != NULL )
                        printf(
                        "\tNome: %s\n"
                        "\tEmail: %s\n"
                        "\tTelefone: %s\n\n"
                        , a.v[i].nome, a.v[i].email, a.v[i].telefone);
                }
                break;
            case 3:
                printf("Insira parte do telefone: "); lerstring( dado, TAMEMAIL );
                for ( i = 0 ; i < a.qtd ; i++ ) 
                {
                    pont = strstr( a.v[i].telefone, dado ); 
                    if ( pont != NULL )
                        printf(
                        "\tNome: %s\n"
                        "\tEmail: %s\n"
                        "\tTelefone: %s\n\n"
                        , a.v[i].nome, a.v[i].email, a.v[i].telefone);
                }
                break;
        }
    } else printf("\nNao ha nenhum contato registrado.\n\n");
}

void listarcontatos (Tcontatos a)
{
    int i; 
    if (a.qtd == 0) printf("\nNao ha nenhum contato registrado.\n\n");
    else
    { 
        limpartela();
        for (i = 0; i < a.qtd ; i++)
            printf(
                "\tNome: %s\n"
                "\tEmail: %s\n"
                "\tTelefone: %s\n\n"
                , a.v[i].nome, a.v[i].email, a.v[i].telefone);
    }
}

void removercontato (Tcontatos * a)
{
    int pos;
    char email[TAMEMAIL];
    limpartela();
    printf("Insira o email do contato a ser removido: ");
    lerstring(email, TAMEMAIL );
    pos = obterindiceemail(*a, email);
    if ( pos > -1 )
    {
        (*a).v[pos] = (*a).v[ (*a).qtd-1 ];
        (*a).qtd--;
        printf("Contato removido com sucesso.\n");
        pausartela();
    }
    else 
    {
        printf("O email informado nao foi encontrado.\n");
        pausartela();
    }
}