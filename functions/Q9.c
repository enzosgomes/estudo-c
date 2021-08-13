/*9. Escreva uma função que receba por parâmetro um número inteiro e verifique se ele é par ou
ímpar. A função deverá retornar a letra P caso o valor seja par e I, caso seja ímpar. A função
main() deverá mostrar no vídeo uma mensagem com a letra retornada*/
#include <stdio.h>

char verificaNumero( int numero ) {
    char parOuImpar;
    if ( numero % 2 == 0) {
        parOuImpar = 'P';
    } else parOuImpar = 'I';
return parOuImpar;
}
int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("\n| P para par | I para impar |\nLetra retornada: %c",verificaNumero(numero));
return 0;
}