/*4. Escreva uma função que receba por parâmetro os valores necessários para o cálculo da
fórmula de báskara (função matemática do 2º grau) e mostre no vídeo as raízes (x1 e x2), caso
seja possível calcular. */
#include <stdio.h>
#include <math.h>

void retonarRaizes( float a, float b, float c ) {
    float delta, x1, x2;
    delta = (b*b) - (4*a*c);
    if (a == 0) {
      printf("Nao e equacao do segundo grau!");
    } else if ( delta < 0 ) {
        printf("Nao apresenta raizes reais! ");
    } else if ( delta == 0 ) {
        x1 = ( -b + sqrt(delta) ) / ( 2 * a );
        printf("Somente uma raiz: %.2f", x1);
    } else if ( delta > 0 ) {
        x1 = ( -b + sqrt(delta) ) / ( 2 * a );
        x2 = ( -b - sqrt(delta) ) / ( 2 * a );
        printf("duas raizes reais distintas! \nx1: %.2f\nx2: %.2f", x1, x2);
    }
}
int main() {
    float a, b, c, resultEquacao;
    printf("digite o valor de a: ");
    scanf("%f", &a);
    printf("digite o valor de b: ");
    scanf("%f", &b);
    printf("digite o valor de c: ");
    scanf("%f", &c);
    
    retonarRaizes( a, b, c );
return 0;
}