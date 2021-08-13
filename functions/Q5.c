/*5. Escreva uma função que receba por parâmetro a idade de uma pessoa expressa em anos,
meses e dias, calcule e retorne essa idade expressa em dias. A função main() deverá mostrar
no vídeo uma mensagem com a idade calculada.*/
#include <stdio.h>

int calculaIdadeEmDias( int ano, int mes, int dia ) {
    int totalDias;
    ano = ano * 360;
    mes = mes * 31;
    totalDias = ano + mes + dia;
    return totalDias;
}
int main() {
    int anos, meses , dias, armazenaTotalDias;
    printf("Digite sua idade dividida em anos, meses e dias!\n");
    printf("Anos: ");
    scanf("%d", &anos);
    printf("Meses: ");
    scanf("%d", &meses);
    printf("Dias: ");
    scanf("%d", &dias);
    
    armazenaTotalDias = calculaIdadeEmDias( anos, meses, dias);
    printf("Total da idade em dias: %d", armazenaTotalDias);
}