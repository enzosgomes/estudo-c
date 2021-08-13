/*2. Escreva uma função que receba por parâmetro as 3 notas de um aluno e uma letra. Se a
letra for A, a função deverá calcular a média aritmética das notas do aluno, se for P, a média
ponderada (pesos: 1ª nota, peso 5, 2ª nota, peso 3 e 3ª nota, peso 2) e se for H, a função
deverá calcular a média harmônica. A função deverá retornar a média calculada. A função
main() deverá mostrar no vídeo uma mensagem com a média calculada.*/
#include <stdio.h>
#define PESO_NOTA1 5.0
#define PESO_NOTA2 3.0
#define PESO_NOTA3 2.0

float calculaMedia(char opcao, float nota1, float nota2, float nota3){
    float media;
    if ( opcao == 'A' || opcao == 'a') {
        media = (nota1 + nota2 + nota3) / 3;
    } else if (opcao == 'P' || opcao == 'p') {
           media = ( ( nota1 * PESO_NOTA1 ) + ( nota2 * PESO_NOTA2 ) + ( nota3 * PESO_NOTA3 ) ) / ( PESO_NOTA1 + PESO_NOTA2 + PESO_NOTA3 ); 
    } else if(opcao == 'H' || opcao == 'h') {
        media = 3 / ( ( 1/nota1 ) + ( 1/nota2 ) + ( 1/nota3 ));
    }
    return media;
}

int main() {
    float nota1, nota2, nota3, armazenaMedia;
    char opcaoMedia;
    
    printf("digite sua primeira nota: ");
    scanf("%f", &nota1);
    printf("\ndigite sua segunda nota: ");
    scanf("%f", &nota2);
    printf("\ndigite sua terceira nota: ");
    scanf("%f", &nota3);
    printf("\n--- Escolha qual o tipo de media ---\nDigite; A (para media aritmetica): \nDigite; P (para media ponderada): \nDigite; H (para media harmonica): \n");
    scanf(" %c", &opcaoMedia);
    
    armazenaMedia = calculaMedia(opcaoMedia, nota1, nota2, nota3);
        
    if ( opcaoMedia == 'A' || opcaoMedia == 'a') {
        printf("Media aritmetica: %.2f", armazenaMedia);
    } else if (opcaoMedia == 'P' || opcaoMedia == 'p') {
        printf("Media ponderada: %.2f", armazenaMedia); 
    } else if(opcaoMedia == 'H' || opcaoMedia == 'h') {
        printf("Media harmonica: %.2f", armazenaMedia);
    } else {
        printf("Erro! dados invalidos.");
    }
    return 0;
}