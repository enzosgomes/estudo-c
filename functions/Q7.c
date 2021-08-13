/*7. Escreva uma função que receba a idade de um nadador por parâmetro e retorne a categoria
desse nadador de acordo com o código da tabela abaixo. A função main() deverá mostrar no
vídeo uma mensagem com o código da categoria.*/
#include <stdio.h>

char categoriaNadador( int idade ) {
char categoria;
    if ( idade >= 5 && idade <= 7) {
        categoria = 'A';
    } else if ( idade >= 8 && idade <= 10 ) {
        categoria = 'B';
    } else if ( idade >= 11 && idade <= 13 ) {
        categoria = 'C';
    } else if ( idade >= 14 && idade <= 17 ) {
        categoria = 'D';
    } else if ( idade > 18 ) {
        categoria = 'E';
    } else {
        categoria = 'F';
    }
return categoria;
}
int main() {
    int idade;
    char armazenaCategoria;
    printf("Digite a idade do nadador: ");
    scanf("%d", &idade);

    armazenaCategoria = categoriaNadador( idade );
    if ( armazenaCategoria == 'A' ) {
        printf( "Codigo categoria: %c", armazenaCategoria );
    } else if (armazenaCategoria == 'B') {
        printf( "Codigo categoria: %c", armazenaCategoria );
    } else if ( armazenaCategoria == 'C' ) {
        printf( "Codigo categoria: %c", armazenaCategoria );
    } else if (armazenaCategoria == 'D') {
        printf( "Codigo categoria: %c", armazenaCategoria );
    } else if (armazenaCategoria == 'E') {
        printf( "Codigo categoria: %c", armazenaCategoria );
    } else if( armazenaCategoria == 'F') {
        printf( "Nao existe essa categoria!" );
    }
return 0;
}