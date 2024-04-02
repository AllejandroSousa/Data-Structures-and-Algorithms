#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{
    Calc *calc = calc_cria("%.2f\n");
    while (true)
    {
        char c;
        scanf(" %c", &c);
        if (c == '+' || c == '-' || c == '*' || c == '/')
            calc_operador(calc, c);
        else if (c == 'q')
            break;
        else
        {
            float v;
            ungetc(c, stdin);
            if (scanf("%f", &v) == 1)
                calc_operando(calc, v);
            else
            {
                printf("Erro na leitura\n");
                exit(1);
            }
        }
    }
    calc_libera(&calc);
    return 0;
}