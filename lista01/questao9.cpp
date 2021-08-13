//importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//declarando constantes
#define CDI_CONVERTIDO_REAL 0.019
#define SELIC_CONVERTIDO_REAL 0.02
#define RENDIMENTO_CDB 1.35
#define IMPOSTO_ATE_DOIS_ANOS 0.22
#define IMPOSTO_MAIOR_DOIS_ANOS 0.15
#define RENDIMENTO_LCI 0.9

//funcoes
/*(Logica CDB): condicional para escolher imposto de renda de acordo 
com os anos do invertimento
*/
float calcula_cdb( float valor , int anos ){
	float valorCDI, valorCDB;
	
	if( anos > 0 &&  anos <= 2 ){
		//processamento
		valorCDB = CDI_CONVERTIDO_REAL * valor;//valor do cdi
		valorCDB *= RENDIMENTO_CDB;//valor do CDB sem descontar o imposto
		valorCDB = ( valorCDB - ( valorCDB * IMPOSTO_ATE_DOIS_ANOS ) ) * anos;//descontando imposto e mult os anos para ter o valor final
		
	}else if ( anos > 2 ){
		//processamento
		valorCDB = CDI_CONVERTIDO_REAL * valor;//valor do cdi
		valorCDB *= RENDIMENTO_CDB;//valor do CDB sem descontar o imposto
		valorCDB = ( valorCDB - ( valorCDB * IMPOSTO_MAIOR_DOIS_ANOS ) ) * anos;//descontando imposto reduzido e mult os anos para ter o valor final
	}
	
	return valorCDB;
}
//(Logica LCI): calcular 90% da selic e depois mult pelo valor depois por snod psrs o vslor final
float calcula_lci( float valor, int anos ){
	float valorLCI;
	
	//processamento
	valorLCI = ( valor * (SELIC_CONVERTIDO_REAL * RENDIMENTO_LCI) ) * anos;
	
	return valorLCI;
}

int main() {
	float valorIvestimento, finalCDB, FinalLCI;
	int anosInvestimento;
	
	//entrada
	printf("Digite o valor que deseja invertir: ");
	scanf("%f", &valorIvestimento);
	printf("Digite o tempo que deseja invertir: ");
	scanf("%d", &anosInvestimento);
	
	//(logica):usar as variaveis nos parametros das fucoes
	finalCDB = calcula_cdb(valorIvestimento, anosInvestimento);
	FinalLCI = calcula_lci(valorIvestimento, anosInvestimento);
	
	//saida
	printf("Rendimento CDB RS: %.3f", finalCDB);
	printf("\nRendimento LCI RS: %.3f", FinalLCI);
	
	return 0;
}
