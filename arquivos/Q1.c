#include <stdio.h>
#include <stdlib.h>
void criarAquivo(FILE *pArquivo)
{
    char str[] = {'1', '2', '3', '4', '\0'}, bufferSTR;
    int i;
    pArquivo = fopen("arqQ1.txt", "w");
    if (pArquivo == NULL)
    {
        printf("Erro na abertura do arquivo(gravacao).");
        exit(1);
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        fputc(str[i], pArquivo);
    }
    fclose(pArquivo);
}

void contCaracteres(FILE *pArquivo)
{
    int cont = 0;
    char buffer;
    pArquivo = fopen("arqQ1.txt", "r");
    if (pArquivo == NULL)
    {
        printf("Erro na abertura do arquivo(leitura).");
        exit(2);
    }
    buffer = fgetc(pArquivo);
    while (buffer != EOF)
    {
        printf("\n caracter: %c \n", buffer);
        buffer = fgetc(pArquivo);
        cont++;
    }
    printf("\n Numero de caracteres do arquivo: %d \n", cont);
    fclose(pArquivo);
}

void main()
{
    FILE *arq;
    criarAquivo(arq);
    contCaracteres(arq);
}