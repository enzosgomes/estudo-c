//importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>

//funcoes
float media_aritmetica(float num1 , float num2, float num3){
	float media;
	
	//processamento
	media = (num1 + num2 + num3) / 3;
	
	return media;
}

int main() {
	float num1, num2, num3, mediaFinal;
	
	//entrada
	printf("Digite o primeiro numero: ");
	scanf("%f", &num1);
	printf("Digite o segundo numero: ");
	scanf("%f", &num2);
	printf("Digite o terceiro numero: ");
	scanf("%f", &num3);
	
	//(logica):fazer uma funcao que tem como retorno uma media aritmetica.
	
	//usando funcao
	mediaFinal = media_aritmetica(num1,num2,num3);
	
	//saida
	printf("A media aritmetica he: %.2f", mediaFinal);
	
	return 0;
}
