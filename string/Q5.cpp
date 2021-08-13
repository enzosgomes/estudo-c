/*Elabore um programa em C para criptografar uma frase dada pelo usuário (a criptografia troca as
vogais da frase por asterisco).*/
#include <stdio.h>

int main () {
	char txt[100]; 
	int i;
	printf("Digite um texto: ");
	gets(txt);
	
	for (i=0; txt[i] != '\0'; i=i+1) {
		if ( txt[i] == 'a' || txt[i] == 'e' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'u' || txt[i] == 'A' || txt[i] == 'E' || txt[i] == 'I' || txt[i] == 'O' || txt[i] == 'U') {
			txt[i] = '*';
		}
	}
	printf("\n\nTexto (criptografado): \n%s", txt);
	return 0;
}
