#include <stdio.h>
#include <stdlib.h>
#define QUANT_INT 10

void main()
{
    int *pi, i, cont = 0;
    pi = (int *) malloc(QUANT_INT*sizeof(int));
    if (pi==NULL)
    {
        printf ("Erro!(Memoria Insuficiente).");
        exit;
    } 
    for(i = 0; i < QUANT_INT; i++)
    {
        printf("Digite um numero:");
        scanf("%d", &pi[i]);
    }
    for(i = 0; i < QUANT_INT; i++)
    {
        if(pi[i] % 2 == 0)
        {
            cont++;
        }
    }
    if (cont == 0)
    {
         printf("\nnao existe numeros pares!");
    }
    else
    {
        printf("\nQuantidade de numeros pares: %d", cont);
    }
}