#include <stdio.h>
#include "lista_d_e.h"

int main() {
    Nod* nod = cria_nod(5);
    Listad* l1 = cria_listad();
    insere_inicio(l1, 1);
    insere_inicio(l1, 2);
    insere_inicio(l1, 3);
    insere_meio(l1, 3, 4);
    insere_meio(l1, 2, 3);
    insere_meio(l1, 10, 7);
    insere_fim(l1, 10);
    imprime(l1);
    printf("\n");
    remove_info(l1, 1);
    remove_info_all(l1, 3);
    imprime(l1);
    printf("\n");
    remove_inicio(l1);
    imprime(l1);
    printf("\n");
    modifica_info(l1, 2, 8);
    imprime(l1);
    printf("\n");
    libera_listad(&l1);
    imprime(l1);
    return 0;
}