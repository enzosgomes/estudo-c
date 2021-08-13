/*3. Escreva uma função que receba por parâmetro um número inteiro e positivo e retorne 1 caso
o número seja primo e 0, caso contrário. A função main() deverá mostrar no vídeo uma
mensagem informando se o número é primo ou não.*/
#include <stdio.h>

int verificaPrimos(int numTeste) {
    int i , contDivisao = 0 , retonoDiv;
    
    for( i = 2; i <= numTeste / 2; i++ ) {
        if( numTeste % i == 0 ) {
            contDivisao++;
            break;
        }
    }
    if (contDivisao == 0) {
        retonoDiv = 1;
    } else {
        retonoDiv = 0;
    }
return retonoDiv;
}
int main() {
    int numero, armazenaResult;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    armazenaResult = verificaPrimos(numero);
    if( armazenaResult == 1) {
        printf( "\nO numero %d he primo!", numero );
    } else if ( armazenaResult == 0) {
        printf( "\nO numero %d nao he primo!", numero );
    }
return 0;
}