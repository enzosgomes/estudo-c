//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main() {
    int horaInicio, horaFinal, horaDuracaoJogo;
	
	//entrada
    printf("horas do inicio do jogo: ");
    scanf("%d", &horaInicio);
    printf("horas do final do jogo: ");
    scanf("%d", &horaFinal);

    /*(logica) se a hora do inicio do jogo for em um dia e terminar no outro subtrai 24h da hora inicial e soma com a hora do fim;
    se terminar no mesmo dia subtrai hora do inicio do jogo pela hora do fim;
    se a hora do inicio do jogo for mesma do fim o tempo de 24h foi ultrapassado;
	caso nao entre nessas condicoes erro.*/
    
	//processamento 
	horaDuracaoJogo = horaFinal - horaInicio;
    if(horaFinal < horaInicio){
    	//processamento
        horaDuracaoJogo = (24 - horaInicio) + horaFinal;
    }
	else if(horaFinal > horaInicio){
		//processamento
		horaDuracaoJogo = horaFinal - horaInicio;
    }
    else if(horaFinal == horaInicio){
    	//processamento
    	horaDuracaoJogo = 24;
    	
    	//saida 
    printf ("Tempo maximo!\n");
    } else {
    	printf("erro!\n");
	}
   
   //saida  
    printf("o total de horas do jogo de poquer foram: %d.", horaDuracaoJogo);
    
	return 0;
}
