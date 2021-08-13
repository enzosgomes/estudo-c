#include <stdio.h>
#include <stdlib.h>
int main(){
	int num[10], par[10], impar[10], x=0, y=0;
	
	printf("Digite 9 numeros interiros:\n");
	
	for(int i = 0; i<9; i++){
		scanf("%d", &num[i]);
	}
	
	for(int i = 0; i<9; i++){
		
		if(num[i]%2==0){ //pegar so os pares
			par[x] = num[i]; //guadar pares
			x++; //incrementa par
		}else{ //oque sobra é impar
			impar[y] = num[i]; //guarda impar
			y++; //incrementa impar
		}
	}
	//saida dos vetores par e impar
	
	printf("\nNumeros pares\n");
	for(int i = 0; i<x; i++){
		printf("%d\n", par[i]);
	}
	printf("\nNumeros impares\n");
		for(int i = 0; i<y; i++){
		printf("%d\n", impar[i]);
	}
	
	return 0;
}
