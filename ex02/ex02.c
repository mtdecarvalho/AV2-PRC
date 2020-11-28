#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCATEGORIA 20
#define TAMNOME 30

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
    int codigo, qtd;
    char categoria[TAMCATEGORIA], nome[TAMNOME];
    double preco;
} Tbrinquedo;

typedef struct
{
    Tbrinquedo v[100];
    int qtd;
} Testoque;

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
    printf("Insira o codigo do brinquedo: "); scanf(" %d", &(*a).codigo);
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
        printf("Insira a categoria do brinquedo: "); limpa(); fgets((*a).categoria, TAMCATEGORIA, stdin);
        if ( (*a).categoria[strlen((*a).categoria)-1] == '\n' ) { (*a).categoria[strlen((*a).categoria)-1] = '\0'; }
        printf("Insira o nome do brinquedo: "); fgets((*a).nome, TAMNOME, stdin);
        if ( (*a).nome[strlen((*a).nome)-1] == '\n' ) { (*a).nome[strlen((*a).nome)-1] = '\0'; }
        printf("Insira o preco do brinquedo: "); scanf(" %lf", &(*a).preco);
        printf("Insira a quantidade: "); scanf(" %d", &(*a).qtd);
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
    printf("Insira o codigo do brinquedo e a quantidade a ser removida [0 = Remover registro]: "); scanf(" %d %d", &codigo, &qtd);
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
    printf("Insira o codigo do brinquedo a ser atualizado: "); scanf(" %d", &cod);
    posicao = obterindiceestoque(*a, cod);
    if ( posicao > -1 )
    {
        printf("Que dado deseja alterar no brinquedo %s?\n", (*a).v[posicao].nome);
        printf(
            "1. Categoria\n"
            "2. Nome\n");
        scanf(" %d", &op); limpa();
        switch (op)
        {
            case 1: printf("Insira a nova categoria para o brinquedo: "); fgets( (*a).v[posicao].categoria, TAMCATEGORIA, stdin );
                    if ( (*a).v[posicao].categoria[strlen((*a).v[posicao].categoria)-1] == '\n' ) { (*a).v[posicao].categoria[strlen( (*a).v[posicao].categoria)-1] = '\0'; }
                    printf("Categoria atualizada com sucesso!\n"); break;
            case 2: printf("Insira o novo nome para o brinquedo: "); fgets( (*a).v[posicao].nome, TAMNOME, stdin );
                    if ( (*a).v[posicao].nome[strlen((*a).v[posicao].nome)-1] == '\n' ) { (*a).v[posicao].nome[strlen( (*a).v[posicao].nome)-1] = '\0'; }
                    printf("Nome atualizado com sucesso!\n"); break;
            // quais dados alterar mais?
        }
    }
    else
    {
        printf("Nenhum brinquedo foi encontrado com o codigo inserido.\n");
    }
    pausartela();
}

void listarestoque (Testoque a)
{
    int i;
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
    limpa();
    printf("Insira a categoria a ser listada: "); 
    fgets( categoria, TAMCATEGORIA, stdin ); if ( categoria[strlen(categoria)-1] == '\n' ) categoria[strlen(categoria)-1] = '\0';
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
    printf("Deseja filtrar usando:\n"
        "1. Nome\n"
        "2. Categoria\n\n");
    scanf(" %d", &op); limpa();
    switch (op) 
    {
        case 1: 
            printf("Insira o nome a ser buscado: "); fgets(dado, TAMCATEGORIA, stdin); if ( dado[strlen(dado)-1] == '\n' ) dado[strlen(dado)-1] = '\0';
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
            printf("Insira a categoria a ser buscada: "); fgets(dado, TAMCATEGORIA, stdin); if ( dado[strlen(dado)-1] == '\n' ) dado[strlen(dado)-1] = '\0';
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

int menu ()
{
    int op;
    printf("Bem vindo ao controle de estoque.\n\nO que deseja fazer?\n");
    printf("1. Inserir brinquedo no estoque\n"
           "2. Remover brinquedo(s)\n"
           "3. Atualizar dados de um brinquedo\n"
           "4. Listar todos os brinquedos\n"
           "5. Listar todos de uma categoria\n"
           "6. Listar filtrando por parte do nome ou categoria\n"
           "0. Sair\n");
    scanf(" %d", &op);
    return op;
}

int main ()
{
    Tbrinquedo brinquedo;
    Testoque estoque;
    int op;
    inicializarestoque(&estoque);
    do 
    {
        limpartela();
        op = menu();
        switch (op)
        {
            case 1: lerbrinquedo(&brinquedo, &estoque); inserirbrinquedo(brinquedo, &estoque); break;
            case 2: removerbrinquedo(&estoque); break;
            case 3: atualizarbrinquedo(&estoque); break;
            case 4: listarestoque(estoque); break;
            case 5: listarcategoria(estoque); break;
            case 6: listarfiltro(estoque); break;
        }
    } while (op != 0);
    return 0;
}