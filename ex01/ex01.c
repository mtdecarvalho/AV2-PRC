#include "util.h"

#include <stdio.h>
#include <string.h>

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

void obterindiceparte (char dado[], int op, Tcontatos a)
{
    int i, achou=0;
    for (i = 0 ; i < a.qtd ; i++)
    {
        switch (op)
        {
        case 1:
            if ( strncmp(a.v[i].nome, dado, strlen(dado) ) == 0 )
            {
                printf(
                    "\tCONTATO %d\n"
                    "Nome: %s\n"
                    "Email: %s\n"
                    "Telefone: %s\n", i+1, a.v[i].nome, a.v[i].email, a.v[i].telefone);
                achou=1;
            }
            break;
        case 2:
            if ( strncmp(a.v[i].email, dado, strlen(dado) ) == 0 )
            {
                printf(
                    "\tCONTATO %d\n"
                    "Nome: %s\n"
                    "Email: %s\n"
                    "Telefone: %s\n", i+1, a.v[i].nome, a.v[i].email, a.v[i].telefone);
                achou=1;
            }
                break;
        case 3: 
            if ( strncmp(a.v[i].telefone, dado, strlen(dado) ) == 0 )
            {
                printf(
                    "\tCONTATO %d\n"
                    "Nome: %s\n"
                    "Email: %s\n"
                    "Telefone: %s\n", i+1, a.v[i].nome, a.v[i].email, a.v[i].telefone);
                achou=1;
            }
            break;
        }
    }
    if ( achou == 0 ) printf("Nenhum contato foi encontrado com o dado inserido.\n");
}

void lercontato (Tcontato * a)
{
    printf("Insira o nome do contato: "); fgets( (*a).nome, TAMNOME, stdin ); if ((*a).nome[strlen((*a).nome)-1] == '\n') (*a).nome[strlen((*a).nome)-1] = '\0';
    printf("Insira o email do contato: "); fgets( (*a).email, TAMEMAIL , stdin ); if ((*a).email[strlen((*a).email)-1] == '\n') (*a).email[strlen((*a).email)-1] = '\0';
    printf("Insira o numero de telefone do contato: "); fgets( (*a).telefone, TAMTEL, stdin ); if ((*a).telefone[strlen((*a).telefone)-1] == '\n') (*a).telefone[strlen((*a).telefone)-1] = '\0';
    printf("Contato lido com sucesso!\n"); pausartela();
}

void inserircontato (Tcontato a, Tcontatos * b)
{
    (*b).v[(*b).qtd] = a;
    (*b).qtd++;
}

void listarcontato (Tcontatos a)
{
    int op;
    char dado[TAMEMAIL];
    int tel;
    printf(
    "Deseja buscar o contato usando parte de que dado?\n"
    "1. Nome\n"
    "2. Email\n"
    "3. Telefone\n");
    scanf(" %d", &op); limpa();
    switch (op)
    {
        case 1:
            printf("Insira parte do nome: "); fgets(dado, TAMEMAIL, stdin);
            if ( dado[strlen(dado)-1] == '\n') dado[strlen(dado)-1] = '\0';
            obterindiceparte(dado, op, a); 
            break;
        case 2:
            printf("Insira parte do email: "); fgets(dado, TAMEMAIL, stdin);
            if ( dado[strlen(dado)-1] == '\n') dado[strlen(dado)-1] = '\0';
            obterindiceparte(dado, op, a);
            break;
        case 3:
            printf("Insira parte do telefone: "); fgets(dado, TAMEMAIL, stdin);
            if ( dado[strlen(dado)-1] == '\n') dado[strlen(dado)-1] = '\0';
            obterindiceparte(dado, op, a); 
            break;
    }
}

void listarcontatos (Tcontatos a)
{
    int i; 
    if (a.qtd == 0) printf("Nao ha nenhum contato registrado.\n");
    else 
        for (i = 0; i < a.qtd ; i++)
            printf(
                "\tCONTATO %d\n"
                "Nome: %s\n"
                "Email: %s\n"
                "Telefone: %s\n"
                , i+1, a.v[i].nome, a.v[i].email, a.v[i].telefone);
}

void removercontato (Tcontatos * a)
{
    int pos;
    char email[TAMEMAIL];
    printf("Insira o email do contato a ser removido: ");
    fgets(email, TAMEMAIL, stdin); if ( email[strlen(email)-1] == '\n') email[strlen(email)-1] = '\0';
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

int main ()
{
    Tcontato contato;
    Tcontatos contatos;
    int op;
    inicializarcontatos(&contatos);

    do
    {
        limpartela();

        printf("\tAGENDA ELETRONICA\n"
            "\t1. Inserir contato\n"
            "\t2. Remover contato\n"
            "\t3. Listar todos os contatos\n"
            "\t4. Listar contato\n"
            "\t0. Sair\n");
        scanf(" %d", &op);
        switch (op)
        {
            case 1: limpa(); lercontato(&contato); inserircontato(contato, &contatos); break;
            case 2: limpa(); removercontato (&contatos); break;
            case 3: limpa(); listarcontatos(contatos); pausartela();  break;
            case 4: limpa(); listarcontato(contatos); pausartela(); break;
            case 0: printf("Encerrando...\n"); break;
        }
    }
    while (op != 0);

    return 0;
}