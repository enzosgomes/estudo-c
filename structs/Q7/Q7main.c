#include <locale.h>
#include "Q7fun.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    inicializar();
    menu();
return 0;
}