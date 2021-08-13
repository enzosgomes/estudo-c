//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declarando constantes
#define DESCONTO_INSS 0.11

//funcoes
float calcula_salario(float salario, float bonus){
	float salarioFinal, descontoINSS,valorBonus;
	
	//processamento
	descontoINSS = (DESCONTO_INSS * salario);
	bonus /= 100;
	valorBonus = bonus * salario;
	salarioFinal = (salario - descontoINSS) + valorBonus;
	 
	return salarioFinal;
}

int main() {
	float salarioBruto, bonusPorcento, valorFinal, taxaINSS, valorBonusRS;
	
	//entrada
	printf("Digite seu salario bruto: ");
	scanf("%f", &salarioBruto);
	printf("Digite o valor do bonus(em porcentagem %%): ");
	scanf("%f", &bonusPorcento);
	/*(logica): fazer uma fucao q retona o salario final; processar fora da funcao o desconto do inss e o valor do bunos
	OBS: tentei fazer com as constantes para usar na funcao e motra na principal mas deu erro em cima de erro e fiz assim :( */
	
	//procesamento
	taxaINSS = (DESCONTO_INSS * salarioBruto);
	valorBonusRS = (bonusPorcento / 100) * salarioBruto;
	//usando a funcao
	valorFinal = calcula_salario(salarioBruto,bonusPorcento);
	
	//saida
	printf("Valor do bonus he RS: %.2f\n", valorBonusRS);
	printf("Taxa do INSS he RS: %.2f\n", taxaINSS);
	printf("Salario final he RS: %.2f\n", valorFinal);
	
	return 0;
}
