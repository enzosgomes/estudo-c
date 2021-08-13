/*8. Escreva uma função que receba um valor real e verifique se ele é positivo ou negativo. A
função deverá retornar a letra P caso o valor seja positivo e N, caso seja negativo. A função
main() deverá mostrar no vídeo uma mensagem com a letra retornada*/
#include <stdio.h>

char verificaNumero( float numero ) {
    char retSinal;
    if ( numero > 0.0) {
        retSinal = 'P';
    } else if ( numero < 0.0) {
        retSinal = 'N';
    } else retSinal = '0';
return retSinal;
}

int main() {
    float num;
    char armazenaSinal;
    printf("Escreva um valor real: ");
    scanf("%f", &num);
    
    armazenaSinal = verificaNumero( num );
    if( armazenaSinal == 'P' ) {
        printf("\nretorno: %c \tvalor positivo!", armazenaSinal);
    } else if( armazenaSinal == 'N') {
        printf("\nretorno: %c \tvalor negativo!", armazenaSinal);
    } else if( armazenaSinal == '0') {
        printf("\nO valor %c he neutro!", armazenaSinal);
return 0;
}