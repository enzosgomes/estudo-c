/*7. Elabore um programa C que receba uma frase com letras minúsculas e converta a primeira letra de
cada palavra da frase para maiúscula.*/
#include <ctype.h>
#include <stdio.h>

int main () {
	char txt[100]; 
	int i;
	printf("Digite uma frase: ");
	gets(txt);
	txt[0] = toupper(txt[0]);
	for (i=0; txt[i] != '\0'; i=i+1) {
		if (txt[i] == ' ') {
			txt[i + 1] = toupper(txt[i + 1]);
		}
	}
	printf("\nFrase editada: \n%s", txt);
	return 0;
}
