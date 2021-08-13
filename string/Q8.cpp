/*8. Elabore um programa em C que receba um verbo regular terminado em AR e mostre sua conjugação
no presente do indicativo. Exemplo: verbo andar.Eu ando Tu andas Ele anda Ela Anda
Nós andamos Vós andais Eles andam */
#include <stdio.h>
#include <string.h>
const int QUANTIDADE_CONJUGACOES = 7;
int main(){
	char str[15], str2[15];
	int j=0, i;
	printf("Digite um verbo regular terminado em ar: ");
	gets(str);
	size_t size = strlen(str);
	for (i=1; i <= QUANTIDADE_CONJUGACOES; i++) {
			switch(i) {
				case 1:
					str[size - 1] = ' ';
					str[size - 2] = 'o';
					strcpy (str2, "Eu "); 
					strcat (str2, str);
					printf("\n%s", str2);
   				break;
   				case 2:
					str[size - 1] = 's';
					str[size - 2] = 'a';
					strcpy (str2, "Tu "); 
					strcat (str2, str);
					printf("\t%s\n", str2);
   				break;
   				case 3:
					str[size - 1] = ' ';
					str[size - 2] = 'a';
					strcpy (str2, "Ele "); 
					strcat (str2, str);
					printf("\n%s", str2);
   				break;
   				case 4:
					strcpy (str2, "Ela "); 
					strcat (str2, str);
					printf("\t%s", str2);
   				break;
   				case 5:
   					str[size - 1] = 'm';
   					strcat(str, "os");
					strcpy (str2, "Nos "); 
					strcat (str2, str);
					printf("\t%s\n", str2);
   				break;
   				case 6:
   					str[size + 1 ] = ' ';
					str[size] = 's';
					str[size - 1] = 'i';
					str[size - 2] = 'a';
					strcpy (str2, "Vos "); 
					strcat (str2, str);
					printf("\n%s", str2);
   				break;
   				case 7:
   					str[size] = ' ';
   					str[size - 1] = 'm';
					strcpy (str2, "Eles "); 
					strcat (str2, str);
					printf("\t%s", str2);
   				break;
			}
		}
	return 0;
}
