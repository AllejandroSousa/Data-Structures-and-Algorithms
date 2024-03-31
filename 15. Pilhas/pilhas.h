// TAD Pilhas

#ifndef PILHAS_H
#define PILHAS_H

typedef struct pilha Pilha;

Pilha *cria_pilha();
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
bool pilha_vazia(Pilha *p);
void pilha_libera(Pilha **p);
void imprime_pilha(Pilha *p);

#endif