#include <stdio.h>
#include <stdlib.h>

int StrLen(char *text)
{
    int cont = 0;
    while ( *text != '\0' )
    {
        cont++;
        text++;
    }
return cont;
}

void StrCat( char *destino, char *origem )
{
    while ( *destino != '\0')
    {
        destino++;
    }
    
    while ( *origem != '\0' )
    {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

int main()
{
    char text[20], text2[20];
    printf("Digite um texto: ");
    gets(text);
    printf("Digite outro texto: ");
    gets(text2);
    printf("(Funcao StrLen) Quantidade caracteres do primeiro texto: %d\n", StrLen(text));
    printf("(Funcao StrLen) Quantidade caracteres do segundo texto: %d\n", StrLen(text2));
    StrCat(text, text2);
    printf("(Funcao StrCat): %s", text);
}