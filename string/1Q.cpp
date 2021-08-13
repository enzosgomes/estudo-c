/*1. Elabore um programa em C, utilizando os comandos for e switch, que leia uma string (use gets) e
substitua todos os espaços e tabulações ('\t') por caracteres de nova linha ('\n'). O for deve ser
encerrado quando o caractere de final da string ('\0') for encontrado.*/
#include <stdio.h>

int main () {
	char txt[100]; 
	int i;
	printf("Digite um texto: ");
	gets(txt);
	
	for (i=0; txt[i] != '\0'; i=i+1)
	{
		switch(txt[i])
		{
			case ' ':
				txt[i] = '\n';
   				break;
   			case '	':
				txt[i] = '\n';
   				break;
		}
	}
	printf("\n\nTexto (editado): \n%s", txt);
	return 0;
}
