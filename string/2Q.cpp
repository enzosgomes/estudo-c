/*2. Elabore um programa em C que leia uma string, conte quantos caracteres desta string são iguais a
letra a e os substitua pela letra b. O programa deve mostrar o número de caracteres modificados e a
string modificada.*/
#include <stdio.h>

int main () {
	char txt[100]; 
	int i, cont = 0;
	printf("\n\nDigite um texto: ");
	gets(txt);
	
	for (i=0; txt[i] != '\0'; i=i+1) {
		if (txt[i] == 'a') {
			txt[i] = 'b';
			cont += 1;
		}
	}
	printf("\n\nTexto (editado): \n%s \n\ncaracteres modificados: %d", txt, cont);
	return 0;
}
