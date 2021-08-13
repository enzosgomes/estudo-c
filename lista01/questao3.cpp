//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main() {
	int numCDU, numUDC, centena, dezena, unidade;
	
	//entrada
	printf("Digite um numero no formato centena, dezena, unidade(CDU): ");
	scanf("%d", &numCDU);
	
	/*(logica):separar as partes do numero em 
	centena(Divido o numero por 100 para pular 2 casas ficando com "C");
	dezena(pego o resto do numero dividido por 100 ficando com "DU" divide por 10 para pular 1 ficando com "D");
	unidade(numero ja esta "DU" pego o resto da divisao por 10 para pegar "U";
	concatenar esses valores em uma variavel.*/
	
	//processamento
	centena = numCDU / 100;
	numCDU %= 100;
	dezena = numCDU / 10;
	unidade = numCDU % 10;
	numUDC = ((unidade%100)*100)+((dezena%10)*10)+(centena % 100 );//gambiarra da concatenacao
	
	//saida
	printf("Centena: %d", centena);
	printf("\nDezena: %d", dezena);
	printf("\nUnidade: %d", unidade);
	printf("\nO numero no formato invertido(UDC) he: %d", numUDC);
	
	return 0;
}
