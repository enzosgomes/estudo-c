#include <stdio.h>
#include <stdlib.h>
int main(){
	int num[5], order;
	
	printf("Digite 5 numeros interiros:\n");
	
	for(int i = 0; i < 5; i++){
		scanf("%d", &num[i]);
	}
	//processamento
	for(int i = 1; i < 5; i++){
		for(int y = 0; y<i; y++){
			if(num[i] > num[y]){
				order = num[i];
				num[i] = num[y];
				num[y] = order;
			}
		}
	}
	//saida
	printf("\nOrdem decrescente dos vetores: ");
	for(int i = 0; i < 5; i++){
		printf("\n%d", num[i]);
	}
	
	return 0;
}
