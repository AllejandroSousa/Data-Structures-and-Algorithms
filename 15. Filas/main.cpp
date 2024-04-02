#include <stdio.h>
#include "filas.h"

int main()
{
    Fila *f = fila_cria();
    fila_insere(f, 20);
    fila_insere(f, 20.8);
    fila_insere(f, 21.2);
    fila_insere(f, 24.3);
    printf("Primeiro elemento: %.2f\n", fila_retira(f));
    printf("Segundo elemento: %.2f\n", fila_retira(f));
    printf("Configuração da fila:\n");
    fila_imprime(f);
    fila_libera(&f);
    fila_imprime(f);
    return 0;
}