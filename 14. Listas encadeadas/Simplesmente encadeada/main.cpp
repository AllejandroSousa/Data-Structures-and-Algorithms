#include <stdio.h>
#include "lista_s_e.h"

int main() {
    No* no1;
    no1 = cria_no(5);
    Lista* l1 = cria_lista();
    insere_inicio(l1, 1);
    insere_inicio(l1, 2);
    insere_inicio(l1, 3);
    insere_meio(l1, 3, 4);
    insere_meio(l1, 2, 3);
    insere_meio(l1, 10, 7);
    insere_fim(l1, 10);
    imprime_lista(l1);
    printf("\n");
    remove_info(l1, 1);
    remove_info_all(l1, 3);
    imprime_lista(l1);
    printf("\n");
    remove_meio(l1, 2);
    remove_fim(l1);
    remove_inicio(l1);
    imprime_lista(l1);
    printf("\n");
    libera_lista(&l1);
    imprime_lista(l1);
    return 0;
}
