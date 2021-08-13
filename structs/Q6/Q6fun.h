#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#define MAX_VET 20

typedef struct carro
{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
} CARRO;
CARRO vetcarros[MAX_VET];

void inicializar()
{
    int i;
    for (i = 0; i < MAX_VET; i++)
    {
        strcpy(vetcarros[i].marca, "NULL");
        vetcarros[i].ano = -1;
        strcpy(vetcarros[i].cor, "NULL");
        vetcarros[i].preco = -1.0;
    }
}

void cadastraCarro()
{
  int i, posLivre = -1;
        for (i = 0; i < MAX_VET; i++)
        { 
            if (vetcarros[i].preco == -1.0)
            {
                posLivre = i;
                break;
            }
        }
        if (posLivre >= 0)
        {
            printf("\n----- Cadastro carro -----\n");
            fflush(stdin);
            printf("Digite a marca: ");
            fgets(vetcarros[posLivre].marca, sizeof(vetcarros[posLivre].marca), stdin);
            printf("\nDigite a cor: ");
            fgets(vetcarros[posLivre].cor, sizeof(vetcarros[posLivre].cor), stdin);
            printf("\nDigite o ano: ");
            scanf("%d", &vetcarros[posLivre].ano);
            printf("\nDigite o preco: ");
            scanf("%f", &vetcarros[posLivre].preco);
        }
        else
        {
            printf("Quantidadade maxima cadastrada: %d carros\n", MAX_VET);
        }
}

void retornaCarroPorPreco(float preco)
{
    int i, cont = 0;
    printf("Carros com o preco igual ou menor que %.2f reais.", preco);
    for (i = 0; i < MAX_VET; i++)
    {
        if (vetcarros[i].preco <= preco)
        {
            printf("\n-----------------------------\n");
            printf("Marca: %s", vetcarros[i].marca);
            printf("Cor: %s", vetcarros[i].cor);
            printf("Ano: %d", vetcarros[i].ano);
            printf("\n-----------------------------\n");
        }
        else
        {
            cont++;
        }
    }
    if (cont > 0)
    {
       printf("\nNenhum carro encontrado! ");
    }
}

void retornaCarroPorMarca(char marca[])
{
    int i, cont = 0;
    printf("Carros com a marca %s", marca);
    for (i = 0; i < MAX_VET; i++)
    {
        if (strcmp(vetcarros[i].marca, marca) == 0)
        {
            printf("\n-----------------------------\n");
            printf("Preco: %.2f", vetcarros[i].preco);
            printf("\nAno: %d", vetcarros[i].ano);
            printf("\nCor: %s", vetcarros[i].cor);
            printf("-----------------------------\n");
        }
        else
        {
            cont ++;
        }
    }
    if (cont > 0)
    {
       printf("\nNenhum carro encontrado! ");
    }
}

void retornaCarroEspecifico(char marca[], int ano, char cor[])
{
    int i, cont = 0;
    printf("|Resultado da busca especifica|");
    for (i = 0; i < MAX_VET; i++)
    {
        if (strcmp(vetcarros[i].marca, marca) == 0 && strcmp(vetcarros[i].cor, cor) == 0 && vetcarros[i].ano == ano)
        {
            printf("\n-----------------------------\n");
            printf("Preco: %.2f", vetcarros[i].preco);
            printf("\n-----------------------------\n");
        }
        else
        {
            cont++;
        }
    }
    if (cont > 0)
    {
       printf("\nNenhum carro encontrado! ");
    }
}

void menu() 
{
    char opcao = '0', buscaMarca[15], buscaCor[10];
    float buscaPreco = 0.0;
    int BuscaAno = 0;
    while (opcao != '5')
    {
        system("pause");
        system("cls");
        printf("|MENU|\n1) Cadastrar carro.\n2) Buscar carros por preco.");
        printf("\n3) Buscar carros por marca.\n4) Busca especifica de carro.\n5) Sair.\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);  
        system("cls");
        if (opcao == '1')
        {
            cadastraCarro();
        } 
        else if (opcao == '2')
        {
            printf("|BUSCA|\nDigite o preco: ");
            scanf("%f", &buscaPreco);
            system("cls");
            if (buscaPreco > 0)
            {
                retornaCarroPorPreco(buscaPreco);
            }
            else
            {
                printf("Preco invalido! ");
            }
        }
        else if (opcao == '3')
        {
            fflush(stdin);
            printf("|BUSCA|\nDigite a marca: ");
            fgets(buscaMarca, sizeof(buscaMarca), stdin);
            system("cls");
            retornaCarroPorMarca(buscaMarca);
        }
        else if (opcao == '4')
        {
            fflush(stdin);
            printf("|BUSCA|\nDigite a marca: ");
            fgets(buscaMarca, sizeof(buscaMarca), stdin);
            printf("\nDigite a cor: ");
            fgets(buscaCor, sizeof(buscaCor), stdin);
            printf("\nDigite o ano: ");
            scanf("%d", &BuscaAno);
            system("cls");
            retornaCarroEspecifico(buscaMarca, BuscaAno, buscaCor);
        }
        else if (opcao == '5')
        {
            printf("Saindo...");
            sleep(2);
        }
        else
        {
            printf("Opcao invalida! ");
        }
    }
}