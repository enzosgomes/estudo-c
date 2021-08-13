#include <stdio.h>
#include <stdlib.h>

int main() {
	char carro1[60], carro2[60];
	float tempoCarro1, tempoCarro2;
	
	//entrada
	printf("Digite o nome do carro1: ");
	scanf("%s", &carro1);
	printf("Digite o tempo de corrida do carro1: ");
	scanf("%f", &tempoCarro1);
	printf("Digite o nome do carro2: ");
	scanf("%s", &carro2);
	printf("Digite o tempo de corrida do carro2: ");
	scanf("%f", &tempoCarro2);
	
	/*(logica):se o carro1 tiver o tempo maior que o carro2 ele é campeao,se nao testa se o tempo do carro2 e maior se for ele é campeao,
	se nao testa se os tempos sao os mesmo e he empate, caso nao seja nenhuma he erro*/
	
	if (tempoCarro1 > tempoCarro2){
		//saida se o carro1 ganha
		printf("O carro: %s foi o campeao!", carro1);
	}else if(tempoCarro2 > tempoCarro1) {
		//saida se carro2 ganha
		printf("O carro: %s foi o campeao!", carro2);
	}else if(tempoCarro1 == tempoCarro2){
		//saida se for empate
		printf("Empate!");
	}else{
		//saida erro
		printf("erro!");
	}
	
	return 0;
}
