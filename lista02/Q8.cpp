#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32 //verifica o SO e limpa o cmd.
	#define CLEAR() system("cls")
#else
	#define CLEAR() system("clear")
#endif

enum status { //deixa o codigo mais semantico.
	ERRO = 0,
	SUCESSO
};

void systemPause() { //faz o mesmo que system("pause"), porém funciona tanto no windows ou linux.
	printf("Pressione qualquer tecla para continuar...\n");
	fflush(stdin); //limpa o buffer.
	char c = getchar();
	CLEAR();
}

int returnIDProduto(int *IDproduto, int ID) { //funcao que retornar indice do codigo do produto.
	for(int i = 0; i < 10; i++) {
		if(IDproduto[i] == ID) {
			return i;
		}
	}

	return -1; //permitir o retorno da função, o if sempre será executado.
}


int compra(int *estoque, int indice, int quantidade) { //funcao compra do produto.
	if(estoque[indice] >= quantidade) { //SUCESSO caso  estoque seja suficiente.
		estoque[indice] -= quantidade;
		return SUCESSO;
	} 
	else {	// se a quantidade de produtos no estoque for insuficiente, retorna ERRO.
		return ERRO;
	}
}

void exibeEstoque(int *estoque, int *IDproduto) {
	for(int i = 0; i < 10; i++) {
		printf("Cod[%d] - Quantidade em Estoque: %d\n", IDproduto[i], estoque[i]);
	}
}

int main() {

	int IDproduto[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //vetor dos codigos dos produtos.
	int estoque[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; //vetor do estoque dos produtos.
	int ID;
	int quantidade;
	int terminou = 0;

	CLEAR();

	while(!terminou) {
		printf("CODIGOS DOS PRODUTOS EXISTENTES: 1,2,3,4,5,6,7,8,9\n\n");
		printf("codigo do produto: ");
		scanf("%d", &ID); //lendo o char como inteiro para poder fazer a comparação na tabela ASCII.

		if(ID == 0) {//se o usuario digitar 0, o programa exibe o estoque atualizado e encerra o laço.
			CLEAR();
			exibeEstoque(estoque, IDproduto);
			terminou = 1;
		}
		else {
			if(ID >= 1 && ID <= 9) { //condicional para tratar erros.
				printf("Digite a quantidade: ");
				scanf("%d", &quantidade);

				int indice = returnIDProduto(IDproduto, ID);
				int statusDaOperacao = compra(estoque, indice, quantidade);

				if(statusDaOperacao == SUCESSO) {
					printf("\nPedido realizado com sucesso. Obrigado volte sempre!\n");
					systemPause(); //usuario escolhe a opcao e retorna ao inicio do laço.
				}
				else if(statusDaOperacao == ERRO) {
					printf("\nestoque insuficiente.\n");
					systemPause(); //usuario escolhe a opcao e retorna ao inicio do laço
				}
			} 
			else {
				printf("\nErro! Codigo invalido. Tente novamente\n");
				systemPause(); //usuario escolhe a opcao e retorna ao inicio do laço
			}
		}
	}
}
