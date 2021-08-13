#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_VET 15

typedef struct conta
{
    int idConta;
    char nome[50];
    float saldo;
} CONTA;
CONTA cont[MAX_VET];

void inicializar()
{
    int i;
    for (i = 0; i < MAX_VET; i++)
    {
        cont[i].idConta = -1;
        strcpy(cont[i].nome, "NULL");
        cont[i].saldo = -1.0;
    }
}

void cadastraConta()
{
    int i, posicaoLivre = -1;
    
    for (i = 0; i < MAX_VET;  i++)
    {  
        if (cont[i].idConta == -1) 
        {
            posicaoLivre = i;
            break;
        }
    }
    if (posicaoLivre >= 0)
    {
        cont[posicaoLivre].idConta = posicaoLivre;
        printf("\n----- Numero da conta: %d -----\n", cont[posicaoLivre].idConta);
        fflush(stdin);
        printf("Digite seu nome: ");
        fgets(cont[posicaoLivre].nome, sizeof(cont[posicaoLivre].nome), stdin);
        printf("\nDigite o saldo: ");
        scanf("%f", &cont[posicaoLivre].saldo);
    }
    else
    {
        printf("Sem contas livres no nomento!\n");
    }
}

void visualizaContas(char str[]) 
{
    int i;
    printf("Visualizar contas cliente: %s\n", str);
    for (i = 0; i < MAX_VET;  i++)
    {
        if (strcmp(cont[i].nome, str) == 0)
        {   
            printf("\n---------------------------------\n");
            printf("Numero conta: %d", cont[i].idConta);
            printf("\nNome conta: %s", cont[i].nome);
            printf("Saldo conta: %.2f", cont[i].saldo);
            printf("\n---------------------------------\n");
        }
    }
}

void excluiMenorSaldo()
{
    float menorsaldo = 0.0, buffer = 0.0;
    int i;
    for (i = 0; i < MAX_VET; i++)
    {
        if (cont[i].idConta != -1)
        {
            buffer = cont[i].saldo;
            if (i == 0)
            {
            menorsaldo = buffer;
            }
            if (buffer <= menorsaldo)
            {
            menorsaldo = buffer;
            }
        }
    }
    for (i = 0; i < MAX_VET; i++)
    {   
        if (menorsaldo == cont[i].saldo)
        {
            printf("Numero da conta excluida: %d\n", cont[i].idConta);
            cont[i].idConta = -1;
            strcpy(cont[i].nome, "NULL");
            cont[i].saldo = -1.0;
        }
    }
}

void menu() 
{
    char opcao = '0';
    while (opcao != '4')
    {
        system("pause");
        system("cls");
        printf("1. Cadastrar contas\n2. Visualizar todas as contas de determinado cliente\n3. Excluir a conta com menor saldo (supondo a nao existencia de saldos iguais).\n4. Sair.\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);  
        system("cls");
        if (opcao == '1')
        {
            cadastraConta();
        } 
        else if (opcao == '2')
        {
            char nomeCliente[50];
            printf("Digite o nome do cliente: ");
            fflush(stdin);
            fgets(nomeCliente , sizeof(nomeCliente), stdin);
            system("cls"); 
            visualizaContas(nomeCliente);
        } 
        else if (opcao == '3')
        {
            excluiMenorSaldo();
        }
        else if (opcao == '4')
        {
            printf("Saindo... Tecle algo para sair. ");
            getch();
        }
        else
        {
            printf("Opcao invalida! ");
        }
    }
}