/*. Elabore um programa em C que receba uma frase, calcule e mostre a quantidade de palavras da frase
digitada. Considere que cada espaço em branco indica o final de uma palavra.*/
#include <stdio.h>

int main () {
	char txt[100]; 
	int i, cont = 1;
	printf("\nDigite uma frase: ");
	gets(txt);
	
	for (i=0; txt[i] != '\0'; i=i+1) {
		if (txt[i] == ' ') {
			cont += 1;
		}
	}
	printf("Quantidade de palavras: %d", cont);
	return 0;
}
