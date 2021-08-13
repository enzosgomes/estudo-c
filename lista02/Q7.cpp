#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//constantes
#define SALARIO 1058.76
#define ACRESCIMO 0.055
#define BONUS 25

int main(){
	char vendedor[50];
	int quantosObjetos;
	
	printf("Digete o nome do vendedor: ");
	scanf(" %s", vendedor);
	printf("Digete quantos objetos vai cadastar(no minimo tres): ");
	scanf("%d", &quantosObjetos);
	
	int bonus, maisVendido, maisVendidoPosicao, quantia[10], somaQuantia = 0, testeBonus;
	float  comissao, totalVendas, valorObjetos[10],  somaValor = 0, recebe;
	if(quantosObjetos >= 3){
		for(int i = 0; i < quantosObjetos; i++){
			printf("Digite o valor do  %d objetos R$", i+1);
			scanf("%f", &valorObjetos[i]);
			printf("Digite a quantia vendida do %d objeto: ", i+1);
			scanf("%d", &quantia[i]);
			totalVendas = valorObjetos[i] * quantia[i];
			somaValor += totalVendas;
			somaQuantia += quantia[i];
		}
	
		testeBonus = floor(somaValor/1000);
		comissao = ACRESCIMO * somaValor;
	
		printf("\n RELATORIO \nVendedor: %s - Total de objetos vendidos: %d\n", vendedor, somaQuantia);
	
		for(int i = 0; i < quantosObjetos; i++){
			printf("\nObjeto %d: ", i+1);
			printf(" Valor unitario: %.2f - Quantia vendida: %d - valor total: %.2f\n", valorObjetos[i], quantia[i], (valorObjetos[i]*quantia[i]));	
		}
	
		maisVendido = quantia[0];
		for(int i = 0; i < quantosObjetos; i++){
			if(quantia[i] > maisVendido){
				maisVendido = quantia[i];
				maisVendidoPosicao = i;
			}
		}
	
		printf("\nValor objeto mais vendido: R$%.2f - posicao objeto mais vendido no vetor: %d\n", valorObjetos[maisVendidoPosicao], maisVendidoPosicao);
		printf("\nValor geral das vendas: R$%.2f", somaValor);
	
		if(somaValor >= 1000){
			bonus = testeBonus * BONUS;
			recebe = SALARIO + bonus + comissao;
			printf("\nBonus recebido: R$%d - comissao: R$%.2f - Valor total a receber: R$%.2f", bonus, comissao, recebe);
		}else{
			recebe = SALARIO + comissao;
			printf("\nBonus recebido: R$0 - comissao: R$%.2f - Valor total a receber: R$%.2f", comissao, recebe);
	}
	}else{
		printf("Erro! no minimo tres produtos");
	}
	return 0;	
}

