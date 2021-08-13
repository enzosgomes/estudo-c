/*11. Escreva uma função que receba por parâmetro a altura expressa em metros e o sexo de
uma pessoa e retorne o seu peso ideal. Para os homens, calcular o peso ideal usando a
fórmula peso ideal = 72.7 x altura - 58 e, para mulheres, peso ideal = 62.1 x altura - 44.7. A
função main() deverá mostrar no vídeo uma mensagem com o peso ideal da pessoa.*/

#include <stdio.h>

float calculaPesoIdeal( int altura, char sexo) {
float pesoIdeal;
    if( sexo == 'm' || sexo == 'M' ) {
        pesoIdeal =  72.7 * altura  - 58;
    } else if( sexo == 'f' || sexo == 'F' ) {
        pesoIdeal =  62.1 * altura  - 44.7;
    }
return pesoIdeal;
}

int main() {
    float altura, armazenaPesoIdeal;
    char sexo;
    printf("| M para masculino | F para feminino | Digite seu sexo: ");
    fflush(stdin);
    scanf("%c", &sexo);
    printf("\nDigite sua altura: ");
    scanf("%f", &altura);

    armazenaPesoIdeal = calculaPesoIdeal( altura, sexo );
    printf("\nSeu peso ideal he: %.2f", armazenaPesoIdeal);
return 0;
}