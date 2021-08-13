//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declarando constantes
#define PRECO_BASE_MACA 4.57
#define PRECO_ULTRAPACA_LIMITE 5.7

int main() {
	int quantidadeMaca;
	float precoFinalMaca;
	
	//entrada
	printf("Digite a quantidade de maca: ");
	scanf("%d", &quantidadeMaca);
	
	/*(logica):Se a quantidade de maca for maior que doze entra na condicao e multiplica quantidadeMaca pelo preco com acrescimo
	caso nao multiplica quantidadeMaca pelo preco base.*/
	
	if(quantidadeMaca > 12) {
		//processamento
		precoFinalMaca = quantidadeMaca * PRECO_ULTRAPACA_LIMITE;
		//saida com acrescimo
		printf("Custo da maca: %.2f", PRECO_ULTRAPACA_LIMITE);
		printf("\nQuantidae de Macas compradas: %d", quantidadeMaca);
		printf("\nPreco final da compra: %.2f", precoFinalMaca);
	}else {
		//processamento
		precoFinalMaca = quantidadeMaca * PRECO_BASE_MACA;
		//saida preco base
		printf("Custo da maca: %.2f", PRECO_BASE_MACA);
		printf("\nQuantidae de Macas compradas: %d", quantidadeMaca);
		printf("\nPreco final da compra: %.2f", precoFinalMaca);
	}
	
	return 0;
}
