#include <stdio.h>
#include <stdlib.h>
int main(){
	char nome[20];
	int aluno, contador = 0 ;
	float soma = 0, media, nota[aluno];
	
	printf("Digite a turma: ");
	scanf("%s", &nome);
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &aluno);
	
	//Guarda as notas dos alunos 
	for(int i = 0; i < aluno; i++){
		printf("Digite as notas do %d aluno: ", i+1);
		scanf("%f", &nota[i]);
	}
	//somar as notas
	for(int i = 0; i < aluno; i++){
		soma += nota[i];
	}
	//fazer a media
	media = soma / aluno;
	//quantos acimada da media
	for(int i = 0; i < aluno; i++){
		if(nota[i] > media){
			contador ++;
		}
	}
	//saida
	printf("\nNome da turma: %s", nome);
	printf("\nMedia da turma: %.2F", media);
	printf("\nAlunos acima da media: %d", contador);
	
	return 0;
}
