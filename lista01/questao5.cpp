//importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	float valorNotaAutomovel, taxaJuros, IEsima;
	int totalPrestacao, numeroPrestacao;
	
	//entrada
	printf("Digite o valor de nota fiscal do automovel: ");
	scanf("%f", &valorNotaAutomovel);
	printf("Digite o total de prestacoes do consorcio: ");
	scanf("%d", &totalPrestacao);
	printf("Digite a taxa de juros mensal pre-fixada(em porcento%%): ");
	scanf("%f", &taxaJuros);
	printf("Digite o numero da prestacao a ser calculada: ");
	scanf("%d", &numeroPrestacao);
	
	//(logica):transformei a porcentagem para usar na formulaa e so substitui as variaveis na formula.
	
	//procesamento
	taxaJuros /= 100;
	IEsima = valorNotaAutomovel / totalPrestacao*(pow((1+taxaJuros), numeroPrestacao)); //funcao potencia
	
	//saida
	printf("O valor da I-esima he: %.2f", IEsima);
	
	return 0;
}
