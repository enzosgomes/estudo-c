#include "funQ3AQ10.h"

void main()
{
    char opcao = '0';
    FILE *pArquivo;
    inicializa(pArquivo);
    while (opcao != '3')
    {
        sleep(1);
        system("cls");
        printf("|MENU|\n1) Cadastra aluno.\n2) Calcular media dos alunos.\n3) sair do programa.\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        system("cls");
        if (opcao == '1')
        {
            cadastroAluno(pArquivo);
        }
        else if (opcao == '2')
        {
            //calculaMediaAlunos(ponteiroAluno);
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