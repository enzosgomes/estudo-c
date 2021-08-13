#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAX_VET 2000
#define IDADE_ABATE 5.0
#define LEITE_ABATE 40.0
#define MIM_LEITE_ABATE 50.0
#define MAX_LEITE_ABATE 70.0
#define COMP_ALIM_ABATE 50.0
#define DIAS_SEMANA 7.0

typedef struct gado
{
    int cod;
    float leite;
    float alim;
    int anoNasc;
    int mesNasc;
    char abate;
} GADO;
GADO gad[MAX_VET];

void inicializar()
{
    int i;
    for (i = 0; i < MAX_VET; i++)
    {
        gad[i].cod = -1;
        gad[i].leite = 0.0;
        gad[i].alim = 0.0;
        gad[i].anoNasc = -1;
        gad[i].mesNasc = -1;
        gad[i].abate = '0';
    }
}

int anoSistema()
{
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
return (tm.tm_year + 1900); //retorna hora do sistema
}

void cadAbate(float idade, int i)
{
    if (idade > IDADE_ABATE)
    {
        gad[i].abate = 'S';
    }
    else if (gad[i].leite < LEITE_ABATE)
    {
        gad[i].abate = 'S';
    }
    else if (gad[i].leite >= MIM_LEITE_ABATE && gad[i].leite <= MAX_LEITE_ABATE && (gad[i].alim / DIAS_SEMANA) > COMP_ALIM_ABATE)
    {
        gad[i].abate = 'S';
    }
    else
    {
        gad[i].abate = 'N';
    }
}

void cadastraGado()
{
    int i, posLivre = -1;
    float bufferIdade = 0.0;
    for (i = 0; i < MAX_VET;  i++)
    {
        if (gad[i].cod == -1)
        {
            posLivre = i;
            break;
        }
    }
    if (posLivre >= 0)
    {
        gad[posLivre].cod = posLivre;
        printf("\n----- Codigo Gado: %d -----\n", gad[posLivre].cod);
        printf("\nQuantidade de leite(litros) produzido(semana): ");
        scanf("%f", &gad[posLivre].leite);
        printf("\nQuantidade de alimento(quilos) consumindo(semana): ");
        scanf("%f", &gad[posLivre].alim);
        printf("\nAno de nascimento(quatro digitos): ");
        scanf("%d", &gad[posLivre].anoNasc);
        printf("\nMes de nacimento: ");
        scanf("%d", &gad[posLivre].mesNasc);
        if (gad[posLivre].mesNasc > 0)
        {
            bufferIdade = (anoSistema() - gad[posLivre].anoNasc) + (gad[posLivre].mesNasc / 12.00);
        }
        else
        {
            bufferIdade = (anoSistema() - gad[posLivre].anoNasc);
        }
        //printf("\nbufferIdade: %f||poslivre: %d\n", bufferIdade, posLivre); //testa os parametros da funcao
        cadAbate(bufferIdade, posLivre);
    }
    else
    {
        printf("Quantidadade maxima cadastrada: %d gados\n", MAX_VET);
    }
}

float totalLeiteSemana()
{
    int i;
    float totalLeite = 0.0;
    for (i = 0; i < MAX_VET; i++)
    {
        totalLeite = totalLeite + gad[i].leite;
    }
return totalLeite;
}

float totalAlimSemana()
{
    int i;
    float totalAlim = 0.0;
    for (i = 0; i < MAX_VET; i++)
    {
        totalAlim = totalAlim + gad[i].alim;
    }
return totalAlim;
}

float totalLeiteAbate()
{
    int  i;
    float leitePerdido = 0.0, totalLeitePosAbate = 0.0;
    for (i = 0; i < MAX_VET; i++)
    {
        if (gad[i].abate == 'S')
        {
            leitePerdido = leitePerdido + gad[i].leite;
        }
    }
    totalLeitePosAbate = totalLeiteSemana() - leitePerdido;
return totalLeitePosAbate;
}

float totalAlimAbate()
{
    int  i;
    float  alimEconomizado = 0.0, totalAlimPosAbate = 0.0;
    for (i = 0; i < MAX_VET; i++)
    {
        if (gad[i].abate == 'S')
        {
            alimEconomizado = alimEconomizado + gad[i].alim;
        }
    }
    totalAlimPosAbate = totalAlimSemana() - alimEconomizado;
return totalAlimPosAbate;
}

int quantGadoAbatido()
{
    int  i, contGadoAbate = 0;
    for (i = 0; i < MAX_VET; i++)
    {
        if (gad[i].abate == 'S')
        {
            contGadoAbate++;
        }
    }
return contGadoAbate;
}

int excluiGadosAbateS()
{
    int i, cont = 0;
    for (i = 0; i < MAX_VET; i++)
    {
        if (gad[i].abate == 'S')
        {
            gad[i].cod = -1;
            gad[i].leite = 0.0;
            gad[i].alim = 0.0;
            gad[i].anoNasc = -1;
            gad[i].mesNasc = -1;
            gad[i].abate = '0';
            cont++;
        }
    }
return cont;
}

void menuCadastro()
{
    char opcao = 'x';
    int bufferExcluir = 0;
    while (opcao != '3')
    {
        system("pause");
        system("cls");
        printf("|Menu cadastro|\n1) Cadastrar.\n2) Excluir Abatidos.\n3) Sair cadastro.\nOpcao: ");
        scanf(" %c", &opcao);
        system("cls");
        if (opcao == '1')
        {
            cadastraGado();
        }
        else if (opcao == '2')
        {
            bufferExcluir = excluiGadosAbateS();
            if (bufferExcluir ==  0)
            {
                printf("Nao ha gados para excluir!\n");
            }
            else if (bufferExcluir > 0)
            {
                printf("Gados para o abate excluidos!\n");
            }    
        }
        else if (opcao == '3')
        {
            printf("Saindo menu cadastro... ");
        }
        else
        {
            printf("Opcao invalida! ");
        }
    }
}

void menuOpcao()
{
    char opcao = 'z'; 
    while (opcao != 'h')
    {
        system("pause");
        system("cls");
        printf("|Menu opcoes|\nc) Quantidade total de leite produzida por semana.");
        printf("\nd) Quantidade total de alimento consumido por semana.");
        printf("\ne) Quantidade total de leite que vai ser produzido por semana, apos o abate.");
        printf("\nf) Quantidade total de alimento que vai ser consumido por semana, apos o abate.");
        printf("\ng) Informar numero de cabecas de gado que irao para o abate.\nh) Sair menu opcoes.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        system("cls");      
        if (opcao == 'c' || opcao == 'C')
        {
            printf("Total de leite produzido na semana: %.2f litros\n", totalLeiteSemana());
        }
        else if (opcao == 'd' || opcao == 'D')
        {
            printf("Total de alimento consumido na semana: %.2f quilos\n", totalAlimSemana());  
        }
        else if (opcao == 'e' || opcao == 'E')
        {
            printf("Total leite produzido apos abate: %.2f litros\n", totalLeiteAbate());
        }
        else if (opcao == 'f' || opcao == 'F')
        {
            printf("Total alimento consumido apos abate: %.2f quilos\n", totalAlimAbate());
        }
        else if (opcao == 'g' || opcao == 'G')
        {
            printf("Quantidade de gados que irao para o abate: %d\n", quantGadoAbatido());
        }
        else if (opcao == 'h' || opcao == 'H')
        {
            opcao = 'h';
            printf("Saindo... Tecle algo para sair. ");
            getch();
        }
        else
        {
            printf("Opcao invalida! ");
        }
    }
}