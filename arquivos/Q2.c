#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void transfereDados(char strOrigem[], char strDestino[])
{
    FILE *pArqOrigem;
    FILE *pArqDestino;
    size_t buffer0 = 0;
    size_t buffer1 = 0;
    unsigned char buf[1024 * 8];
    //origem
    pArqOrigem = fopen(strOrigem, "rb");
    if (pArqOrigem == NULL)
    {
        printf("Erro ao abrir arquivo de origem!");
        exit(1);
    }
    //destino
    pArqDestino = fopen(strDestino, "wb");
    if (pArqDestino == NULL)
    {
        printf("Erro ao abrir arquivo de destino!");
        exit(2);
    }
    //copia dados
    do
    {
        buffer1 = 0;

        buffer0 = fread(buf, 1, sizeof(buf), pArqOrigem);

        if (buffer0 > 0)
            buffer1 = fwrite(buf, 1, buffer0, pArqDestino);
    } while ((buffer0 > 0) && (buffer0 == buffer1));
    fclose(pArqOrigem);
    fclose(pArqDestino);
}

void main()
{
    char arquivoOrigem[MAX], arquivoDestino[MAX];
    printf("\nDigite os arquivos com suas extencoes!\n");
    printf("Nome arquivo (origem): ");
    fgets(arquivoOrigem, sizeof(arquivoOrigem), stdin);
    //tirando o \n
    size_t vet = strlen(arquivoOrigem) - 1;
    if (arquivoOrigem[vet] == '\n')
    {
        arquivoOrigem[vet] = '\0';
    }
    printf("Nome da copia (destino): ");
    fgets(arquivoDestino, sizeof(arquivoDestino), stdin);
    //tirando o \n
    size_t vetor = strlen(arquivoDestino) - 1;
    if (arquivoDestino[vetor] == '\n')
    {
        arquivoDestino[vetor] = '\0';
    }
    transfereDados(arquivoOrigem, arquivoDestino);
}