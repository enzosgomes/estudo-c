#include <stdio.h>
#include <stdlib.h>
#define MAX_VET 20

typedef struct familia
{
    int idadePai;
    int idadeMae;
    float rendafamiliar;
    int numFilhos;
} FAMILIA;
FAMILIA fam[MAX_VET];

void cadastraFamilia()
{
  int i;
    for (i = 0; i < MAX_VET;  i++)
    {
      printf("\n----Familia:%d----\n", i + 1);
      printf("Digite a idade do pai: ");
      scanf("%d", &fam[i].idadePai);
      printf("Digite a idade da mae: ");
      scanf("%d", &fam[i].idadeMae);
      printf("Digite quantidade de filhos: ");
      scanf("%d", &fam[i].numFilhos);
      printf("Digite renda familiar: ");
      scanf("%f", &fam[i].rendafamiliar);
      system("cls");
    }
}

float menorRendarFamiliar()
{
  float menorRenda = 0.0, buffer = 0.0;
  int i;
  for (i = 0; i < MAX_VET; i++)
  {
    buffer = fam[i].rendafamiliar;
    if (i == 0)
    {
     menorRenda = buffer;
    }
    if (buffer <= menorRenda)
    {
    menorRenda = buffer;
    }
  } 
return menorRenda;
}

int doisFilhosRenda600()
{
  int i, cont = 0;
  for (i = 0; i < MAX_VET; i++)
  {    
    if (fam[i].numFilhos > 2 && fam[i].rendafamiliar < 600.00)
    {
      cont += 1;
    }
  }
return cont;
}