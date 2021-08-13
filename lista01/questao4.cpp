//importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	float altura, peso, imc;
	
	//entrada
	printf("Digite sua altura Metos(M): ");
	scanf("%f", &altura);
	printf("Digite seu peso em kilo gramas(KG): ");
	scanf("%f", &peso);
	
	//(logica):so substitui as variaveis na formula.
	
	//procesamento
	imc = peso / (pow(altura, 2));//usando funcao de potencia
	
	//saida
	printf("O indice de massa corporea(IMC) he: %.2f", imc);
	
	return 0;
}
