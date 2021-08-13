/*1. Faça uma função que receba por parâmetro o raio de 
uma esfera e calcule e mostre o seu
volume (v = 4/3xPIxR
3). Considere PI = 3.14.*/
#include <stdio.h>

void calculaVolumeEsfera(float raio) {
    float volume;
    volume = 4.0 * 3.14 * ( ( raio * raio ) * raio ) / 3.0 ; //nao utilizei a funcao pow
    printf("\nVolume esfera: %f", volume);
}

int main(){
    float raioEsfera;
    printf("Difite o raio da esfera: ");
    scanf("%f", &raioEsfera);
    calculaVolumeEsfera(raioEsfera);
    
    return 0;
}