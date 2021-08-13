#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#define MAX_CONTATOS 20
#define VET_NOME_OR_ULTNOME 30
#define VET_NUMEROS 40

struct contato
{
    int id;
    char nome[VET_NOME_OR_ULTNOME];
    char ultimoNome[VET_NOME_OR_ULTNOME];
    char fixo[VET_NUMEROS];
    char celular[VET_NUMEROS];
};

void inicializar(struct contato *pcont)
{
    int i;
    for (i = 0; i < MAX_CONTATOS; i++)
    {
        pcont[i].id = -1;
        strcpy(pcont[i].nome, "NULL");
        strcpy(pcont[i].ultimoNome, "NULL");
        strcpy(pcont[i].fixo, "NULL");
        strcpy(pcont[i].celular, "NULL");
    }
}

void inserirContato(struct contato *pcont)
{
    int i, posLivre = -1;
    for (i = 0; i < MAX_CONTATOS; i++)
    {
        if ((pcont[i].id == -1)
        {
            posLivre = i;
            break;
        }
    }
    if (posLivre >= 0)
    {
        pcont[posLivre].id = posLivre;
        printf("\n----- inserir contato -----\n");
        fflush(stdin);
        printf("Digite oprimeiro nome: ");
        fgets(pcont[posLivre].nome, sizeof(pcont[posLivre].nome), stdin);
        printf("\nDigite o ultimo nome: ");
        fgets(pcont[posLivre].ultimoNome, sizeof(pcont[posLivre].ultimoNome), stdin);
        printf("\nDigite o telefone fixo: ");
        fgets(pcont[posLivre].fixo, sizeof(pcont[posLivre].fixo), stdin);
        printf("\nDigite o telefone celular: ");
        fgets(pcont[posLivre].celular, sizeof(pcont[posLivre].celular), stdin);
    }
    else
    {
        printf("Quantidadade maxima Inserida: %d contatos\n", MAX_CONTATOS);
    }
}

removerContato(char numero[], struct contato *pcont)
{
    int i, verifica = 0;
    for (i = 0; i < MAX_CONTATOS; i++)
    {
        if (strcmp(pcont[i].celular, numero) == 0 || strcmp(pcont[i].fixo, numero) == 0)
        {
            pcont[i].id = -1;
            strcpy(pcont[i].nome, "NULL");
            strcpy(pcont[i].ultimoNome, "NULL");
            strcpy(pcont[i].fixo, "NULL");
            strcpy(pcont[i].celular, "NULL");
            verifica = 1;
        }
    }
    if (verifica = 0)
    {
        printf("Erro! Nao existe contatos com esse numero. ");
    }
    else if (verifica = 1)
    {
        printf("Contato removido com sucesso! ");
    }
}

buscaContato(char nome[], struct contato *pcont)
{
    int i, verifica = 0;
    for (i = 0; i < MAX_CONTATOS; i++)
    {
        if (strcmp(pcont[i].nome, nome) == 0 || strcmp(pcont[i].ultimoNome, nome) == 0)
        {
            printf("\n-----------------------------------");
            printf("\nPrimeiro nome: %s", pcont[i].nome);
            printf("\nUltimo nome: %s", pcont[i].ultimoNome);
            printf("\nTelefone fixo: %s", pcont[i].fixo);
            printf("\nTelefone celular: %s", pcont[i].celular);
            printf("-----------------------------------\n");
            verifica = 1;
        }
    }
    if (verifica = 0)
    {
        printf("\nErro! Nao existe contatos com esse nome. ");
    }
    else if (verifica = 1)
    {
        printf("\nBusca concluida com sucesso! ");
    }
}

void menuContato()
{
    char opcao = '0', numeroRemocao[VET_NUMEROS], nomeBusca[VET_NOME_OR_ULTNOME];
    struct contato vetContatos[MAX_CONTATOS];
    struct contato *ponteiroContato;
    ponteiroContato = (struct contato *)malloc(MAX_CONTATOS * sizeof(struct contato));
    if (ponteiroContato == NULL)
    {
        printf("Erro!(Memoria Insuficiente).");
        sleep(2);
    }
    else
    {
        ponteiroContato = vetContatos;
        inicializar(ponteiroContato);
        while (opcao != '4')
        {
            system("pause");
            system("cls");
            printf("|MENU|\n1) Inserir contato.\n2) Remover contato.");
            printf("\n3) Pesquisar contato.\n4) Sair da lista telefonica.\n");
            printf("Opcao: ");
            scanf(" %c", &opcao);
            system("cls");
            if (opcao == '1')
            {
                inserirContato(ponteiroContato);
            }
            else if (opcao == '2')
            {
                fflush(stdin);
                printf("Digite o numero para remover o contato: ");
                fgets(numeroRemocao, sizeof(numeroRemocao), stdin);
                removerContato(numeroRemocao, ponteiroContato);
            }
            else if (opcao == '3')
            {
                fflush(stdin);
                printf("Digite o primeiro nome ou o ultimo nome: ");
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                buscaContato(nomeBusca, ponteiroContato);
            }
            else if (opcao == '4')
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
}