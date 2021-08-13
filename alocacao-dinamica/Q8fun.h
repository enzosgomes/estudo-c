#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#define MAX_ALUNO 3 //20

struct aluno
{
    int id;
    float nota1;
    float nota2;
    float nota3;
    float media;
};

void inicializar(struct aluno *paluno)
{
    int i;
    for (i = 0; i < MAX_ALUNO; i++)
    {
        paluno[i].id = -1;
        paluno[i].nota1 = 0.0;
        paluno[i].nota2 = 0.0;
        paluno[i].nota3 = 0.0;
        paluno[i].media = 0.0;
    }
}

void cadastraNotas(struct aluno *paluno)
{
    int i, posLivre = -1;
    for (i = 0; i < MAX_ALUNO; i++)
    {
        if (paluno[i].id == -1)
        {
            posLivre = i;
            break;
        }
    }
    if (posLivre >= 0)
    {
        paluno[posLivre].id = posLivre;
        printf("\n----- cadastra notas aluno cod(%d) -----\n", paluno[posLivre].id);
        printf("Digite a primeira nota: ");
        scanf("%f", &paluno[posLivre].nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &paluno[posLivre].nota2);
        printf("Digite a terceira nota: ");
        scanf("%f", &paluno[posLivre].nota3);
    }
    else
    {
        printf("Quantidadade maxima Inserida: %d alunos\n", MAX_ALUNO);
    }
}

calculaMediaAlunos(struct aluno *paluno)
{
    int i, verifica = 0;
    for (i = 0; i < MAX_ALUNO; i++)
    {
        if (paluno[i].id != -1)
        {
        paluno[i].media = (paluno[i].nota1 + paluno[i].nota2 + paluno[i].nota3) / 3.0;
        printf("\nMedia aluno cod(%d): %.2f\n", paluno[i].id, paluno[i].media);
        verifica = 1;
        }
    }
    if (verifica = 0)
    {
        printf("\nNao existe alunos cadastrado! ");
    }
}

void menuAluno()
{
    char opcao = '0';
    struct aluno vetAluno[MAX_ALUNO];
    struct aluno *ponteiroAluno;
    ponteiroAluno = (struct aluno *)malloc(MAX_ALUNO * sizeof(struct aluno));
    if (ponteiroAluno == NULL)
    {
        printf("Erro!(Memoria Insuficiente).");
        sleep(2);
    }
    else
    {
        ponteiroAluno = vetAluno;
        inicializar(ponteiroAluno);
        while (opcao != '3')
        {
            system("pause");
            system("cls");
            printf("|MENU|\n1) Incluir notas de aluno.\n2) Calcular media dos alunos.\n3) sair do programa.\n");
            printf("Opcao: ");
            scanf(" %c", &opcao);
            system("cls");
            if (opcao == '1')
            {
                cadastraNotas(ponteiroAluno);
            }
            else if (opcao == '2')
            {
                calculaMediaAlunos(ponteiroAluno);
            }
            else if (opcao == '3')
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