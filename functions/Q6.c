/*6. Escreva uma função que receba por parâmetro um número inteiro verifique se ele é perfeito
ou não. Um número é perfeito quando ele é igual à soma dos seus divisores positivos,
excluindo le próprio. Exemplo: 6 é perfeito, pois 6 = 1 + 2 + 3, que são seus divisores. A função
deverá retornar a letra P se o número for perfeito e a letra I, caso não seja perfeito. A função
main() deverá mostrar no vídeo uma mensagem informando a condição do número (perfeito ou
não perfeito).*/
char verificaNumero( int num ) {
    int i , buffer = 0;
    char verifica;
    
    for ( i = 1; i < num; i++) {
        if ( num % i == 0) {
            buffer = buffer + i;
        }
    }
    if ( num == buffer ) {
            verifica = 'P';
    } else {
        verifica = 'I';
    }
return verifica;
}

int main() {
    int numero;
    char armazena;
    printf( "Escreva um numero inteiro : " );
    scanf("%d", &numero);
 
    if ( verificaNumero(numero) == 'P') {
        printf( "O %d numero he perfeito!", numero );
    } else if( verificaNumero(numero) == 'I' ) {
         printf(  "O %d nao he perfeito!", numero );
    }
return 0;
}