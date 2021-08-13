/*3. Elabore um programa em C que inverta uma string. Leia a string e armazene-a invertida em outra
string. Use o comando for para varrer a string até o seu final. Refaça o programa anterior usando o
comando while para criar o loop. */
#include <stdio.h>
#include <string.h>

int main() {
	char txt[100];
	printf("\n\nDigite um texto: ");
	gets(txt);
	size_t size = strlen(txt);
	for(int i = 0; i < size / 2; i++){
		char invert = txt[i];
		txt[i] = txt[ size - i - 1];
		txt[size - i -1] = invert;
	}
	printf("\ntexto invertido: \n%s", txt);
}
