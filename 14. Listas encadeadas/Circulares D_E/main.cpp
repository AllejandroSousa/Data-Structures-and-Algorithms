#include <stdio.h>
#include "circular_d_e.h"

int main() {
    No* no = cria_no(8);
    Listacd* l = cria_listacd();
    insere_listacd(l, 1);
    insere_listacd(l, 2);
    insere_listacd(l, 3);
    imprime_listacd(l);
    printf("\n");
    remove_listacd(l, 3);
    modifica_listacd(l, 2, 6);
    imprime_listacd(l);
    printf("\n");
    insere_listacd(l, 0);
    insere_listacd(l, 8);
    imprime_listacd(l);
    libera_listacd(&l);
    imprime_listacd(l);
}