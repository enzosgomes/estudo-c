#include <stdio.h>
#include <stdlib.h>
int main(){
	int numeros, armazena, x;
	
	printf("Escolha quantidade de numeros (no minimo dois): ");
	scanf("%d", &numeros);
	
	if(numeros >= 2){
		float vetor[numeros], maior, menor, soma = 0, media;
		
		for(int i =0; i < numeros; i++){
			printf("Digite o %d numero da lista: ", i+1);
			scanf("%f", &vetor[i]);
			soma += vetor[i];
		}
	
		maior = vetor[0];
		menor = vetor[0];
		media = soma / numeros;
		//processo para ver qual e maior e menor
		for(int i = 0; i < numeros; i++){
			if(vetor[i] > maior){
				maior = vetor[i];
			}
			if(vetor[i] < menor){
				menor = vetor[i];
			}
		}
		
		printf("\nMENU\n ESCOLHA UMA OPCAO:\n 1 - Mostrar o maior elemento;\n 2 - Mostrar o menor elemento;\n 3 - Mostrar a media entre os elementos;\n 4 - Mostrar os numeros em ordem crescente;\n 0 - Encerrar\n");
		printf("Digite sua escolha: ");
		scanf("%d", &armazena);
		
		//condicionais para a escolha do menu
		if(armazena == 0){
			printf("\nPrograma encerrado!\n");
			exit(0);
		}
		if(armazena == 1){
			printf("\nO maior elemento eh: %.2f", maior);
		}
		if(armazena == 2){
			printf("\nO menor elemento eh: %.2f", menor);
		}
		if(armazena == 3){
			printf("\nA media entre os elementos eh: %.2f", media);
		}
		if(armazena == 4){
			//processo para ordenar 
			float order;
			for(int i = 0; i < numeros; i++){
				for(int x = 0; x < numeros; x++){
					if(vetor[i] < vetor[x]){
						order = vetor[i];
						vetor[i] = vetor[x];
						vetor[x] = order;	
					}
				}
			}
			//mostra em ordem
			printf("Numeros enseridos em ordem: ");
			for(int i = 0; i < numeros; i++){
				printf("%.2f ", vetor[i]);
			}
		}
	}else{
		printf("Erro! numeros invalidos.");//se nao digitar no minimo de 2 numeros
	}
	return 0;
}
