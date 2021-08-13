#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	char gabaritoUsuario[10], gabarito[10] = {'E', 'E', 'B', 'A', 'D', 'B', 'D', 'A', 'C', 'D'};
	int hit = 0 , miss = 0, x;
	
	printf("Para verificar os acertos e erros digite suas respostas: ");
	//pegar e guarda as respostas do usuario
	for(int i = 0; i < 10; i++){
		x = i;
		printf("\nQuestao %d: ", x+1);
		scanf(" %c", &gabaritoUsuario[i]);
	}
	
	//processar o gabarito do usuario com o gabarito no "banco/memoria" e calcular se estao certas ou erradas
	for(int i = 0; i < 10; i++){
		x = i;
		gabaritoUsuario[i] = toupper(gabaritoUsuario[i]);
		if(gabaritoUsuario[i] == gabarito[i]){
			printf("\nQuestao %d - sua resposta: %c esta correta", x + 1, gabaritoUsuario[i]);
			hit++;
		}
		else{
			printf("\nQuestao %d - sua resposta: %c esta incorreta", x + 1, gabaritoUsuario[i]);
			miss++;
		}
		
	}
	printf("\nNumero de acertos: %d\nNumero de erros: %d", hit, miss);// mostra o numero de acertos e erros
	
	return 0;
}

