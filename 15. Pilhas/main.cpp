#include <stdio.h>
#include "pilhas.h"

int main() {
    Pilha* p = cria_pilha();
    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 3);
    pilha_push(p, 4);
    imprime_pilha(p);
    pilha_pop(p);
    printf("\n");
    imprime_pilha(p);
    printf("%s", pilha_vazia(p) ? "true" : "false");
    pilha_libera(&p);
    imprime_pilha(p);
}