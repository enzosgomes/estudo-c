#include <stdio.h>
#include <stdlib.h>
#define MAX_VET 20

typedef struct habitante
{
    float salario;
    float idade;
    char sexo;
} HABITANTE;
HABITANTE Hab[MAX_VET];

void cadastraHabitante()
{
  int i;
    for (i = 0; i < MAX_VET;  i++)
    {
      printf("\n----Habitante:%d----\n", i + 1);
      printf("Digite o sexo|M para masculino|F para feminino|: ");
      scanf(" %c", &Hab[i].sexo);
      printf("Digite o salario: ");
      scanf("%f", &Hab[i].salario);
      printf("Digite a idade: ");
      scanf("%f", &Hab[i].idade);
      system("cls");
    }
}

float mediaSalario() 
{
    int i;
    float salarioTotal = 0.0, buffer = 0.0;
    for (i = 0; i < MAX_VET;  i++)
    {
      buffer = Hab[i].salario;
      salarioTotal = salarioTotal + buffer;
    }
    salarioTotal = salarioTotal / i;
return salarioTotal;
}

float mediaIdade() 
{
    int i;
    float idadeTotal = 0.0, buffer = 0.0;
    for (i = 0; i < MAX_VET;  i++) 
    {
      buffer = Hab[i].idade;
      idadeTotal = idadeTotal + buffer;
    }
    idadeTotal = idadeTotal / i;
return idadeTotal;
}

float maiorSalario()
{
float maiorHabSalario = 0.0 ;
int i;
  for (i = 0; i < MAX_VET; i++)
  {
    if (Hab[i].salario > maiorHabSalario)
    {
      maiorHabSalario = Hab[i].salario; 
    }
  } 
return maiorHabSalario;
}

void percentualFMil()
{
  int i;
  float totalM = 0.00, totalMmil = 0.0, percentual = 0.0;
  for (i = 0; i < MAX_VET; i++)
  {
    if (Hab[i].sexo == 'f' || Hab[i].sexo == 'F')
    {
      totalM++;
      if (Hab[i].salario > 1000.0)
      {
        totalMmil++;
      }
    }
  }
  percentual = (totalMmil / totalM) * 100;
  if (totalM > 0)
  {
    printf("\nPercentual de mulheres com salario maior que mil reais: %.2f%%\n", percentual);
  }
  else
  {
    printf("\na|PERCENTUAL|Nao ha mulheres registradas!\n");
  }
}