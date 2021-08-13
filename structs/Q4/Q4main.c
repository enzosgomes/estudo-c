#include "Q4fun.h"

int main()
{   
    char opcao = '0';
    inicializar();
    while (opcao !=  '3')
    {
        system("cls");
        printf("|Menu|\n1) Menu cadastro.\n2) Menu opcoes.\n3) Sair programa.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        system("cls");      
        if (opcao == '1')
        {
            menuCadastro();
        }
        else if (opcao == '2')
        {
            menuOpcao();
        }
        else if (opcao == '3')
        {
            printf("Saindo... Tecle algo para sair. ");
            getch();
        }
        else
        {
            printf("Opcao invalida! ");
            system("pause");
        }
    }
return 0;
}