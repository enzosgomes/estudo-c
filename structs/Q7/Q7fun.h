#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#define LINHA_DIA_MES 3 //0
#define COLUNA_MAX_VET 3
#define MAX_VET_TIPO 4

typedef struct servicoRealizado
{
    int codRealizado, codCliente, codTipo;
    float valor;
} SERVICO_REALIZADO;

typedef struct tipoServico
{
    int codTipo;
    char descricao[20];
} TIPO_SERVICO;

SERVICO_REALIZADO vetSRealizado[LINHA_DIA_MES][COLUNA_MAX_VET];
TIPO_SERVICO vetSTipo[MAX_VET_TIPO];

void inicializar()
{
    int i, j, z;
    for (z = 0; z <= LINHA_DIA_MES; z++)
    {
        for (i = 0; i <= COLUNA_MAX_VET; i++)
        {
            vetSRealizado[z][i].codRealizado = -1;
            vetSRealizado[z][i].codCliente = -1;
            vetSRealizado[z][i].codTipo = -1;
            vetSRealizado[z][i].valor = -1.0;
        }
    }
    for (j = 0; j <= MAX_VET_TIPO; j++)
    {
        vetSTipo[j].codTipo = -1;
        strcpy(vetSTipo[j].descricao, "NULL");
    }
}

void cadastraTipoServico()
{
    int i, posLivre = -1;
    for (i = 0; i < MAX_VET_TIPO; i++)
    {
        if (vetSTipo[i].codTipo == -1)
        {
            posLivre = i;
            break;
        }
    }
    if (posLivre >= 0)
    {
        vetSTipo[posLivre].codTipo = posLivre + 1;
        printf("\n----- Código tipo serviço: %d -----\n", vetSTipo[posLivre].codTipo);
        fflush(stdin);
        printf("Digite a descrição: ");
        fgets(vetSTipo[posLivre].descricao, sizeof(vetSTipo[posLivre].descricao), stdin);
        size_t vet = strlen(vetSTipo[posLivre].descricao) - 1;
        if (vetSTipo[posLivre].descricao[vet] == '\n')
        {
            vetSTipo[posLivre].descricao[vet] = '\0';
        }
    }
    else
    {
        printf("Quantidadade maxima cadastrada: %d tipos serviços\n", MAX_VET_TIPO);
        system("pause");
    }
}

void cadastraServicoRealizado(int dia)
{
    int i, j = 0, bufferTipo = 0, posLivre = -1;
    char verifica = 'x';
    dia = dia - 1;
    for (i = 0; i < COLUNA_MAX_VET; i++)
    {
        if (vetSRealizado[dia][i].codRealizado == -1)
        {
            posLivre = i;
            break;
        }
    }
    if (posLivre >= 0)
    {
        printf("|CADASTRO|\nDigite número do serviço realizado: ");
        scanf("%d", &vetSRealizado[dia][posLivre].codRealizado);
        printf("Digite o código do cliente: ");
        scanf("%d", &vetSRealizado[dia][posLivre].codCliente);
        printf("Digite o valor: ");
        scanf("%f", &vetSRealizado[dia][posLivre].valor);
        printf("Digite o código do tipo de serviço: ");
        scanf("%d", &bufferTipo);
        system("cls");
        while (verifica != '1')
        {
            for (i = 0; i < MAX_VET_TIPO; i++)
            {
                //printf("\n |BT: %d| \n |vetT: %d| \n |I: %d| \n", bufferTipo, vetSTipo[i].codTipo, i); // testando os valores
                if (bufferTipo == vetSTipo[i].codTipo)
                {
                    vetSRealizado[dia][posLivre].codTipo = bufferTipo;
                    verifica = '1';
                    j = 1;
                }
            }
            if (j == 0)
            {
                printf("\nERRO! tipo não exite.\nDigite novamente um código do tipo de serviço existente: ");
                scanf("%d", &bufferTipo);
                system("cls");
            }
        }
    }
    else
    {
        printf("ERRO! Capasidade exedida: %d serviços realizados no dia.\n", COLUNA_MAX_VET);
        system("pause");
    }
}

void mostraServicoDia(int dia)
{
    int i, j, z = 0;
    char bufferDescricao[20];
    printf("\nDIA  %d\n", dia);
    dia = dia - 1;
    printf("N° do serviço          Valor do serviço          Código do serviço          Descrição          Código do cliente");
    for (i = 0; i < COLUNA_MAX_VET; i++)
    {
        for (j = 0; j < MAX_VET_TIPO; j++)
        {
            if (vetSRealizado[dia][i].codRealizado != -1)
            {
                if (vetSRealizado[dia][i].codTipo == vetSTipo[j].codTipo)
                {
                    strcpy(bufferDescricao, vetSTipo[j].descricao);
                    z = 0;
                }
                while (z != 1)
                {
                    printf("\n     %d                     R$%.2f                        %d                        %s                        %d    ", vetSRealizado[dia][i].codRealizado, vetSRealizado[dia][i].valor, vetSRealizado[dia][i].codTipo, bufferDescricao, vetSRealizado[dia][i].codCliente);
                    z++;
                }
            }
        }
    }
    printf("\n");
    system("pause");
}

void mostraServicoIntervaloValor(float valorMin, float valorMax)
{
    int i, j;
    printf("Serviços entre: R$%.2f e R$%.2f\n", valorMin, valorMax);
    for (i = 0; i < LINHA_DIA_MES; i++)
    {
        for (j = 0; j < COLUNA_MAX_VET; j++)
        {
            if (vetSRealizado[i][j].valor >= valorMin && vetSRealizado[i][j].valor <= valorMax)
            {
                printf("\nNúmero do servico: %d\tValor do serviço: R$%.2f\n", vetSRealizado[i][j].codRealizado, vetSRealizado[i][j].valor);
            }
        }
    }
    system("pause");
}

void relatorioGeral()
{
    int i, j, x, z = 0;
    char bufferDescricao[20];
    for (i = 0; i < LINHA_DIA_MES; i++)
    {
        printf("\nDIA 0%d\n", i + 1);
        while (z != 1)
        {
            printf("N° do serviço          Valor do serviço          Código do serviço          Descrição          Código do cliente");
            z++;
        }
        for (j = 0; j < COLUNA_MAX_VET; j++)
        {
            if (vetSRealizado[i][j].codRealizado != -1)
            {
                for (x = 0; x < MAX_VET_TIPO; x++)
                {
                    if (vetSRealizado[i][j].codTipo == vetSTipo[x].codTipo)
                    {
                        strcpy(bufferDescricao, vetSTipo[x].descricao);
                    }
                }
                printf("\n     %d                     R$%.2f                        %d                        %s                        %d    ", vetSRealizado[i][j].codRealizado, vetSRealizado[i][j].valor, vetSRealizado[i][j].codTipo, bufferDescricao, vetSRealizado[i][j].codCliente);
            }
        }
    }
    printf("\n");
    system("pause");
}

void menu()
{
    int diaSRealizado = 0;
    float valorMin = 0.0, valorMax = 0.0;
    char opcao = '0';
    do
    {
        sleep(1);
        //system("pause");
        system("cls");
        printf("|MENU|\n 1. Cadastrar os tipos de serviços.");
        printf("\n 2. Cadastrar os serviços prestados.");
        printf("\n 3. Mostrar os serviços prestados em determinado dia.");
        printf("\n 4. Mostrar os serviços prestados dentro de um intervalo de valor.");
        printf("\n 5. Mostrar um relatório geral (separado por dia), que exiba, inclusive, a descrição do tipo do serviço.");
        printf("\n 6. Finalizar.");
        printf("\n\n Digite a opção desejada: ");
        scanf(" %c", &opcao);
        system("cls");
        switch (opcao)
        {
        case '1':
            cadastraTipoServico();
            break;
        case '2':
            printf("Digite o dia que o serviço foi prestado: ");
            scanf("%d", &diaSRealizado);
            system("cls");
            if (diaSRealizado > 0 && diaSRealizado <= LINHA_DIA_MES)
            {
                cadastraServicoRealizado(diaSRealizado);
            }
            else
            {
                printf("ERRO! Dia invalido. ");
                system("pause");
            }
            break;
        case '3':
            printf("|BUSCA|\nDigite o dia: ");
            scanf("%d", &diaSRealizado);
            system("cls");
            if (diaSRealizado > 0 && diaSRealizado <= LINHA_DIA_MES)
            {
                mostraServicoDia(diaSRealizado);
            }
            else
            {
                printf("ERRO! Dia invalido. ");
                system("pause");
            }
            break;
        case '4':
            printf("|BUSCA|\nDigite o valor mínimo: ");
            scanf("%f", &valorMin);
            printf("\nDigite o valor máximo: ");
            scanf("%f", &valorMax);
            system("cls");
            if (valorMin >= 0)
            {
                mostraServicoIntervaloValor(valorMin, valorMax);
            }
            else
            {
                printf("ERRO! valor invalido. ");
                system("pause");
            }
            break;
        case '5':
            relatorioGeral();
            break;
        case '6':
            printf("Saindo...");
            sleep(1);
            break;
        default:
            printf(" \n Opção não existente. ");
            break;
        }
    } while (opcao != '6');
}