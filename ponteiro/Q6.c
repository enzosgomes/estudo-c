#include <stdio.h>
#include <stdlib.h>
#define LINHA_MATRIZ 100
#define COLUNA_MATRIZ 100
#define QUANT_BYTES COLUNA_MATRIZ * COLUNA_MATRIZ

void inicializa(int *ponteiro)
{
    int i;
    for( i = 0; i < QUANT_BYTES; i++ )
    {
        *ponteiro = 0;
        ponteiro++;
    }
}

void prenche(int *ponteiro)
{
    int i, numeros = 1;
    for( i = 0; i < QUANT_BYTES; i++ )
    {
        *ponteiro = numeros;
        ponteiro++;
        numeros++;
    }
}

int main()
{
    int matriz[LINHA_MATRIZ][COLUNA_MATRIZ];
    int i, *ponteiro, verificaColuna = 0;
    ponteiro = matriz[0];
    inicializa(ponteiro);
    prenche(ponteiro);

    printf("Matriz: %dX%d\n", LINHA_MATRIZ, COLUNA_MATRIZ);
    for( i = 0; i < QUANT_BYTES; i++ )
    {
        printf("\n%d", *ponteiro);
        ponteiro++;
        verificaColuna++;
    }
return 0;
}