#include <stdio.h>
#include <cstdlib>
#include "pilhas.h"

typedef struct no
{
    float info;
    struct no *prox;
} No;

struct pilha
{
    struct no *prim;
};

Pilha *cria_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (!p)
        return NULL;
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha *p, float info)
{
    if (!p)
        return;
    No *no = (No *)malloc(sizeof(No));
    if (!no)
        return;
    no->info = info;
    no->prox = p->prim;
    p->prim = no;
}

float pilha_pop(Pilha *p)
{
    if (!p || !p->prim)
        return NULL;
    No *aux = p->prim;
    float v = aux->info;
    p->prim = aux->prox;
    free(aux);
    aux = NULL;
    return v;
}

bool pilha_vazia(Pilha *p)
{
    if (!p)
        return false;
    return (!p->prim);
}

void pilha_libera(Pilha **p)
{
    if (!(*p))
        return;
    while ((*p)->prim != NULL)
    {
        No* aux = (*p)->prim->prox;
        free((*p)->prim);
        (*p)->prim = aux;
    }
    free(*p);
    *p = NULL;
}

void imprime_pilha(Pilha *p) {
    if (!p || !p->prim) return;
        No* aux = p->prim;
        while (aux != NULL) {
            printf("%.2f ", aux->info);
            aux = aux->prox;
        }
}