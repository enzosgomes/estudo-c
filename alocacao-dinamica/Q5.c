#include <stdio.h>
#include <stdlib.h>
#define QUANT_INT 20

void main()
{
    float *pi, buffer = 0.0;
    int i, cont = 0;
    pi = (float *) malloc(QUANT_INT*sizeof(float));
    if (pi==NULL)
    {
        printf ("Erro!(Memoria Insuficiente).");
        exit;
    } 
    for(i = 0; i < QUANT_INT; i++)
    {
        printf("Digite um numero:");
        scanf("%f", (pi + i));
    }
    buffer = *(pi + 0);
    for(i = 0; i < QUANT_INT; i++)
    {
        if(*(pi + i) > buffer)
        {
            buffer = *(pi + i);
        }
    }
    printf("\nMaior valor do vetor: %.2f", buffer);
}