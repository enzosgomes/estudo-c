/*10. Escreva uma função que receba a média final de um aluno por parâmetro e retorne o seu
conceito, conforme a tabela abaixo. A função main() deverá mostrar no vídeo uma mensagem
com a letra retornada.*/
#include <stdio.h>

char retornaConceito( float media ) {
    char conceito;
    if( media >= 0.0 && media <= 10.0) {
        if( media >= 0.0 && media < 5.0 ) {
            conceito = 'D';
        } else if( media >= 5.0 && media < 7.0 ) {
            conceito = 'C';
        } else if( media >= 7.0 && media < 9.0 ) {
            conceito = 'B';
        } else if( media >= 9.0 && media <= 10.0 ) {
            conceito = 'A';
        }
    } else {
        conceito = 'F';
    }
return conceito;
}
int main() {
    float media;
    char armazenaConceito;
    printf("Digite a media: ");
    scanf("%f", &media);
    armazenaConceito = retornaConceito( media );
    if(armazenaConceito == 'F'){
        printf("Erro!dados invalidos.");
    }else printf("A media: %.2f tem o conceito %c", media, armazenaConceito);
return 0;
}