#include <stdio.h>
#include <stdlib.h>
#include "Q1fun.h"

int main()
{
    cadastraHabitante();
    printf("Media salarial habitantes: %.2f", mediaSalario());
    printf("\nMedia idade habitantes: %.2f", mediaIdade());
    printf("\nMaior salario de um abitante: %.2f", maiorSalario());
    percentualFMil();
    system("pause");
return 0;
}