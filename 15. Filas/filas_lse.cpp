#include <stdio.h>
#include <cstdlib>
#include "filas.h"

struct no
{
    float info;
    struct no *prox;
};

struct fila
{
    struct no *ini;
    struct no *fim;
};

Fila *fila_cria()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (!f)
        return NULL;
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, float v)
{
    if (!f)
        return;
    No *no = (No *)malloc(sizeof(No));
    if (!no)
        return;
    no->info = v;
    no->prox = NULL;
    if (f->fim != NULL)
        f->fim->prox = no;
    else
        f->ini = no;
    f->fim = no;
}

float fila_retira(Fila *f)
{
    if (!f || fila_vazia(f))
        return NULL;
    No *aux = f->ini;
    float v = aux->info;
    f->ini = aux->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(aux);
    aux = NULL;
    return v;
}

bool fila_vazia(Fila *f)
{
    if (!f)
        return false;
    return f->ini == NULL;
}

void fila_libera(Fila **f)
{
    if (!(*f))
        return;
    No *aux = (*f)->ini;
    while (aux != NULL)
    {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*f);
    *f = NULL;
}

void fila_imprime(Fila *f)
{
    if (!f)
        return;
    for (No *i = f->ini; i != NULL; i = i->prox)
        printf("%.2f ", i->info);
}
