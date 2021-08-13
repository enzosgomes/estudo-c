/*12. Escreva uma função que leia um número não determinado de valores positivos e retorne a
média aritmética dos mesmos. A função main() deverá mostrar no vídeo uma mensagem com o
a média aritmética.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float retornaMedia ( float somaNumeros, int divisor) {
    float media;
    media = somaNumeros / divisor;
return media;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    float numero, recebeNumeros;
    int cont = 0, paraLaco;
    
    do {
        printf("Digite o %d° numero: ", cont);
        scanf("%f", &numero);
        recebeNumeros = recebeNumeros + numero;
        cont ++;
        printf("Digite 1 para continuar e 0 para sair\n");
        scanf("%d", &paraLaco);
        system("cls");
    } while( paraLaco == 1 );
    printf("A media entre os numeros é: %.2f", retornaMedia( recebeNumeros, cont ) );
getchar();
return 0;
}