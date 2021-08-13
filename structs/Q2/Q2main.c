#include "Q2fun.h"

int main()
{
    cadastraFamilia();
    printf("Menor renda familiar: %.2f", menorRendarFamiliar());
    printf("\nFamilias com mais de 2 filhos com renda menor que 600 reais: %d", doisFilhosRenda600());
return 0;
}