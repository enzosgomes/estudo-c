/*4. Elabore um programa em C para incluir alunos no arquivo criado no Exercício 3, lembrando
que não podem existir alunos com o mesmo número.
5. Elabore um programa em C para consultar o número, nome e a média de todos os alunos
cadastrados no arquivo criado no Exercício 3.
6. Elabore um programa em C para consultar os dados de um aluno do arquivo criado no
Exercício 3.
7. Elabore um programa em C para alterar as notas dos alunos do arquivo criado no Exercício
3.
8. Elabore um programa em C para alterar o curso dos alunos do arquivo criado no Exercício 3.
9. Elabore um programa em C para excluir fisicamente alunos do arquivo criado no Exercício 3.
10. Elabore um programa em C para excluir logicamente alunos do arquivo criado no Exercício
3. Sugestão: utilize um campo para informar se o registro está ativo ou não.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h> //sleep
#define MAX_ALUNO 4
#define MAX_VET_NOME 40
#define MAX_VET_CURSO 30

typedef struct aluno
{
    int numero; // numero: 0 defalt(livre)
    char nome[MAX_VET_NOME];
    char curso[MAX_VET_CURSO];
    int nota1;
    int nota2;
} ALUNO;

void inicializa(FILE *pArq)
{
    //Questao 3
    int i;
    ALUNO pALuno = {0, "NULL", "NULL", 0, 0};
    pArq = fopen("Alunos.dat", "wb");
    if (pArq == NULL)
    {
        printf("Erro na abertura do arquivo(inicializa)\n");
        sleep(2);
        exit(1);
    }
    for (i = 0; i < MAX_ALUNO; i++)
    {
        fwrite(&pALuno, sizeof(ALUNO), 1, pArq);
    }
    fclose(pArq);
}

cadastroAluno(FILE *pArq)
{
    ALUNO pALuno;
    pArq = fopen("Alunos.dat", "r+b");
    if (pArq == NULL)
    {
        printf("Erro na abertura do arquivo(cadastro)\n");
        sleep(2);
    }
    printf("Digite o numero do aluno (1 a 20): ");
    scanf("%d", &pALuno.numero);
    fflush(stdin);
    printf("Digite o curso: ");
    fgets(pALuno.curso, sizeof(pALuno.curso), stdin);
    //tirando o \n
    size_t vet = strlen(pALuno.curso) - 1;
    if (pALuno.curso[vet] == '\n')
    {
        pALuno.curso[vet] = '\0';
    }
    fflush(stdin);
    printf("Digite o nome: ");
    fgets(pALuno.nome, sizeof(pALuno.nome), stdin);
    //tirando o \n
    size_t vet1 = strlen(pALuno.nome) - 1;
    if (pALuno.nome[vet1] == '\n')
    {
        pALuno.nome[vet1] = '\0';
    }
    printf("Digite a nota 1: ");
    scanf("%d", &pALuno.nota1);
    printf("Digite a nota 2: ");
    scanf("%d", &pALuno.nota2);
    int ret_fseek = 0;
    ret_fseek = fseek(pArq, (pALuno.numero - 1) * sizeof(ALUNO), SEEK_SET);
    if (ret_fseek != 0)
    {
        printf("Erro durante a pesquisa no arquivo\n\n");
        sleep(2);
    }
    int ret_fwrite = 0;
    ret_fwrite = fwrite(&pALuno, sizeof(ALUNO), 1, pArq);
    if (ret_fwrite < 1)
    {
        printf("Erro durante a gravacao no arquivo\n\n");
        sleep(2);
    }
    printf("Registro gravado com sucesso!\n");
    printf("Tecle para terminar!\n");
    getch();
    fclose(pArq);
}