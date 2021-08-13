/*4. Elabore um programa em C que receba uma frase, calcule e mostre a quantidade de vogais da frase
digitada. O programa deverá contar as vogais maiúsculas e minúsculas.*/
#include <stdio.h>

int main () {
	char txt[100]; 
	int i, contMinuscula = 0, contMaiuscula = 0, totalVogais = 0;
	printf("Digite uma frase: ");
	gets(txt);
	
	for (i=0; txt[i] != '\0'; i=i+1) {
		if (txt[i] == 'a' || txt[i] == 'e'|| txt[i] == 'i'|| txt[i] == 'o'|| txt[i] == 'u') {
			contMinuscula += 1;
		}
		if (txt[i] == 'A' || txt[i] == 'E'|| txt[i] == 'I'|| txt[i] == 'O'|| txt[i] == 'U') {
			contMaiuscula += 1;
		}
	}
	totalVogais = contMinuscula + contMaiuscula;
	printf("\n\nTotal de vogais: %d\nquantidade de vogais Minuscula : %d\nquantidade de vogais Maiuscula : %d", totalVogais, contMinuscula, contMaiuscula);
	return 0;
}
