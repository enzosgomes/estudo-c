#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //lib para português

int main(){
	int i, j , eco, naoEco;
	char carros[10][10];
	float consumo[10], litros[10], preco, custo[10], diferenca, maior, menor;
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	
	printf("Digite o preço de 1L de gasolina: R$");
	scanf("%f", &preco);
	printf("\nDigite o nome de dez modelos de carros\n");
	
	for(i = 0; i < 10; i++){
		j = i;
		printf("\nModelo do carro %d: ", j+1);
		scanf(" %s", &carros[i]);
		printf("\nDigite quantos KM o %s faz com 1L de combustível ", carros[i]);
		scanf("%f", &consumo[i]);
	}
	maior = consumo[0];
	menor = consumo[0];
	//processo consumo analisar dos carros
	for(i = 0; i < 10; i++){
		if(consumo[i] > maior){
			maior = consumo[i];
			eco = i;
		}
		if(consumo[i] < menor){
			menor = consumo[i];
			naoEco = i;
		}
	}
	for(i = 0; i < 10; i++){
		litros[i] = 1500/consumo[i];
		custo[i] = litros[i] * preco;
	}
	
	diferenca = ((1500/consumo[naoEco]) - (1500/consumo[eco])) * preco;//o valor da economia
	
	printf("\nO carro mais econômico: %s\nVocê economizaria R$%.2f escolhendo o %s.\n", carros[eco], diferenca, carros[eco]);
	printf("\nOs dados foram baseados em uma viajem de 1.500km\n");
	//  listar todos os carros e seus dados
	for(i = 0; i < 10; i++){
		printf("Modelo: %s - Consumo: %.2fL - Custo total: R$%.2f\n", carros[i], litros[i],custo[i]);
	}
	
	return 0;	
	}
