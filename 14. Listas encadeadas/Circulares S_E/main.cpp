#include <stdio.h>
#include "circular_s_e.h"

int main() {
    No* no = cria_no(8);
    Listac* l = cria_listac();
    insere_listac(l, 1);
    remove_listac(l, 1);
    insere_listac(l, 2);
    insere_listac(l, 3);
    remove_listac(l, 3);
    insere_listac(l, 4);
    insere_listac(l, 5);
    imprime_listac(l);
    printf("\n");
    remove_listac(l, 3);
    modifica_listac(l, 2, 6);
    imprime_listac(l);
    printf("\n");
    insere_listac(l, 0);
    insere_listac(l, 8);
    imprime_listac(l);
    libera_listac(&l);
    imprime_listac(l);
}