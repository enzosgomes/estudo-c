#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_VET 50

typedef struct livro
{
    char titulo[15];
    char autor[20];
    char estilo[10];
    int id;
    float preco;
} LIVRO;
LIVRO vetlivro[MAX_VET];

void inicializar()
{
    int i;
    for (i = 0; i < MAX_VET; i++)
    {
        strcpy(vetlivro[i].titulo, "NULL");
        strcpy(vetlivro[i].autor, "NULL");
        strcpy(vetlivro[i].estilo, "NULL");
        vetlivro[i].id = -1;
        vetlivro[i].preco = -1.0;
    }
}

void cadastraLivro()
{
  int i, posLivre = -1;
        for (i = 0; i < MAX_VET; i++)
        { 
            if (vetlivro[i].id == -1)
            {
                posLivre = i;
                break;
            }
        }
        if (posLivre >= 0)
        {
            vetlivro[posLivre].id = posLivre;
            printf("\n----- Codigo livro: %d -----\n", vetlivro[posLivre].id);
            fflush(stdin);
            printf("Digite o titulo: ");
            fgets(vetlivro[posLivre].titulo, sizeof(vetlivro[posLivre].titulo), stdin);
            printf("\nDigite o autor: ");
            fgets(vetlivro[posLivre].autor, sizeof(vetlivro[posLivre].autor), stdin);
            printf("\nDigite o estilo: ");
            fgets(vetlivro[posLivre].estilo, sizeof(vetlivro[posLivre].estilo), stdin);
            printf("\nDigite o preco: ");
            scanf("%f", &vetlivro[posLivre].preco);
        }
        else
        {
            printf("Quantidadade maxima cadastrada: %d livros\n", MAX_VET);
        }
}

void listaNomeAllLivro()
{
    int i;
    printf("Lista todos livros: \n");
    for (i = 0; i < MAX_VET; i++)
    {
        printf("\nLivro(codigo|%d|) Nome: %s\n", vetlivro[i].id, vetlivro[i].titulo);
    }
}

void listaLivroPorAutor(char str[])
{  
    int i;
    printf("Lista de livros do autor %s", str);
    for (i = 0; i < MAX_VET; i++)
    {
        if (strcmp(vetlivro[i].autor , str) == 0)
        {
            printf("\n-----------------------------");
            printf("\nCodigo: %d", vetlivro[i].id);
            printf("\nTitulo: %s", vetlivro[i].titulo);
            printf("Autor: %s", vetlivro[i].autor);
            printf("Estilo: %s", vetlivro[i].estilo);
            printf("Preco: %.2f\n", vetlivro[i].preco);
            printf("-----------------------------\n");
        }
    }
}

void listaLivroPorTitulo(char str[])
{  
    int i;
    printf("Lista de livros do titulo %s", str);
    for (i = 0; i < MAX_VET; i++)
    {
        if (strcmp(vetlivro[i].titulo , str) == 0)
        {
            printf("\n-----------------------------");
            printf("\nCodigo: %d", vetlivro[i].id);
            printf("\nTitulo: %s", vetlivro[i].titulo);
            printf("Autor: %s", vetlivro[i].autor);
            printf("Estilo: %s", vetlivro[i].estilo);
            printf("Preco: %.2f\n", vetlivro[i].preco);
            printf("-----------------------------\n");
        }
    }
}

void listaLivroPorEstilo(char str[])
{
    int i;
    printf("Lista de livros do estilo %s", str);
    for (i = 0; i < MAX_VET; i++)
    {
        if (strcmp(vetlivro[i].estilo , str) == 0)
        {
            printf("\n-----------------------------");
            printf("\nCodigo: %d", vetlivro[i].id);
            printf("\nTitulo: %s", vetlivro[i].titulo);
            printf("Autor: %s", vetlivro[i].autor);
            printf("Estilo: %s", vetlivro[i].estilo);
            printf("Preco: %.2f\n", vetlivro[i].preco);
            printf("-----------------------------\n");
        }
    }
}

float calculaMediaPrecoAllLivro()
{
    float media = 0.0, bufferPreco = 0.0; int i;
    for (i = 0; i < MAX_VET; i++)
    {
        bufferPreco = vetlivro[i].preco;
        media = media + bufferPreco;
    }
    media = media / MAX_VET;
return media;
}

void mostraMediaPrecoAllLivro()
{
    printf("Media preco de todos os livros: %.2f\n", calculaMediaPrecoAllLivro());
}

void menu()
{
    char opcao = '0', autor[20], titulo[15], estilo[10];
    while (opcao != 'S')
    {
        system("pause");
        system("cls");
        printf("|MENU|\nDigite I para incluir um livro.\n");
        printf("Digite L para listar o nome de todos os livros.\n");
        printf("Digite A para procurar livro por autor.\n");
        printf("Digite T para procurar livro por titulo.\n");
        printf("Digite E para procurar livro por estilo.\n");
        printf("Digite M para calcular a media de preco de todos os livros.\n");
        printf("Digite S para sair.\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        system("cls");      
        if (opcao == 'I' || opcao == 'i')
        {
            cadastraLivro();
        }
        else if (opcao == 'L' || opcao == 'l')
        {
            listaNomeAllLivro();
        }
        else if (opcao == 'A' || opcao == 'a')
        {
            fflush(stdin);
            printf("Digite o autor: ");
            fgets(autor, sizeof(autor), stdin);
            system("cls");
            listaLivroPorAutor(autor);
        }
        else if (opcao == 'T' || opcao == 't')
        {
            fflush(stdin);
            printf("Digite o titulo: ");
            fgets(titulo, sizeof(titulo), stdin);
            system("cls");
            listaLivroPorTitulo(titulo);
        }
        else if (opcao == 'E' || opcao == 'e')
        {
            fflush(stdin);
            printf("Digite o estilo: ");
            fgets(estilo, sizeof(estilo), stdin);
            system("cls");
            listaLivroPorEstilo(estilo);
        }
        else if (opcao == 'M' || opcao == 'm')
        {
            mostraMediaPrecoAllLivro();
        }
        else if (opcao == 'S' || opcao == 's')
        {
            opcao = 'S';
            printf("Saindo... Tecle algo para sair. ");
            getch();
        }
        else
        {
            printf("Opcao invalida! ");
        }
    }
}