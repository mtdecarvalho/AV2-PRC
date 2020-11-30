#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMEMAIL 50
#define TAMTEL 10
#define TAMNOME 30
#define MAX 100

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

typedef struct 
{
    char nome[TAMNOME], email[TAMEMAIL], telefone[TAMTEL];
} Tcontato;

typedef struct 
{
    Tcontato v[MAX];
    int qtd;
} Tcontatos;

char *lerAte(FILE *arq, char sep, char strdest[], int max)
{
    int i=0;
    int letra;
    while ( (letra = fgetc(arq)) > 0 && letra!=sep && i<max-1)
    {
        strdest[i] = letra;
        i++;
    }
    strdest[i] = '\0'; //terminador da string
    return strdest;
}


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

void lerint ( int * a )
{
    while ( scanf(" %d", &(*a) ) != 1 )
    {
        printf("Valor invalido. Tente novamente: ");
        limpa();
    }
}

void lerstring ( char a[], int tam )
{
    fgets(a, tam, stdin); 
    if (a[strlen(a)-1] == '\n') a[strlen(a)-1] = '\0';
}

void lercontato (Tcontato * a)
{
    printf("Insira o nome do contato: "); lerstring( (*a).nome, TAMNOME );
    printf("Insira o email do contato: "); lerstring( (*a).email, TAMEMAIL );
    printf("Insira o numero de telefone do contato: "); lerstring( (*a).telefone, TAMTEL );
    printf("Contato lido com sucesso!\n"); pausartela();
}

void inserircontato (Tcontato a, Tcontatos * b)
{
    (*b).v[(*b).qtd] = a;
    (*b).qtd++;
}

void leragenda (char nomearq[], Tcontatos * a)
{
    FILE *arq;
    arq = fopen(nomearq, "rt");
    if (arq!=NULL)
    {
        (*a).qtd = 0;
        Tcontato b;
        while ( !feof(arq) )
        {
            lerAte(arq, ',' , b.nome, TAMNOME );
            lerAte(arq, ',', b.email, TAMEMAIL);
            lerAte(arq, '\n', b.telefone, TAMTEL);
            inserircontato(b, &*a);
        }
    }
}

void gravaragenda (char nomearq[], Tcontatos a)
{
    FILE *arq; 
    arq = fopen(nomearq, "wt");
    if ( arq!= NULL )
    {
        int i; 
        for ( i = 0 ; i < a.qtd ; i++ )
        {
            Tcontato b = a.v[i];
            fprintf(arq, "%s,%s,%s\n", b.nome, b.email, b.telefone);
        }
        fclose(arq);
    }
}

void listarcontato (Tcontatos a)
{
    int op, i, tel;
    char dado[TAMEMAIL];
    char * pont;
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
                    "Nome: %s\n"
                    "Email: %s\n"
                    "Telefone: %s\n"
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
                    "Nome: %s\n"
                    "Email: %s\n"
                    "Telefone: %s\n"
                    , a.v[i].nome, a.v[i].email, a.v[i].telefone);
            }
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

int menu()
{
    int op;
    limpartela();

        printf("\tAGENDA ELETRONICA\n"
            "\t1. Inserir contato\n"
            "\t2. Inserir contato via arquivo\n"
            "\t3. Remover contato\n"
            "\t4. Listar todos os contatos\n"
            "\t5. Filtrar contatos\n"
            "\t6. Gravar agenda em arquivo\n"
            "\t0. Sair\n");
        lerint(&op);
        return op;
}

int main ()
{
    Tcontato contato;
    Tcontatos contatos;
    char nomearq[100];
    int fim = 0;
    inicializarcontatos(&contatos);

    do
    {
        switch ( menu() )
        {
            case 1: limpa(); lercontato(&contato); inserircontato(contato, &contatos); break;
            case 2: limpa(); printf("Insira o nome do arquivo a ser lido: "); lerstring(nomearq, 100 );
            if (nomearq[strlen(nomearq)-1] == '\n') nomearq[strlen(nomearq)-1] = '\0';
            leragenda(nomearq, &contatos); break;
            case 3: limpa(); removercontato (&contatos); break;
            case 4: limpa(); listarcontatos(contatos); pausartela();  break;
            case 5: limpa(); listarcontato(contatos); pausartela(); break;
            case 6: limpa(); printf("Insira um nome para o arquivo: "); lerstring( nomearq, 100 );
            if (nomearq[strlen(nomearq)-1] == '\n') nomearq[strlen(nomearq)-1] = '\0';
            gravaragenda(nomearq, contatos); break;
            case 0: printf("Encerrando...\n"); fim=1; break;
        }
    }
    while (fim != 1);

    return 0;
}