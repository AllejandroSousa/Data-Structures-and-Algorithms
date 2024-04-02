#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "filas.h"

struct fila
{
    int n;
    int ini;
    int dim;
    float *vet;
};

Fila *fila_cria()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (!f)
        return NULL;
    f->dim = 4;
    f->vet = (float *)malloc(f->dim * sizeof(float));
    if (!f->vet)
        return NULL;
    f->n = 0;
    f->ini = 0;
    return f;
}

void fila_insere(Fila *f, float v)
{
    if (!f)
        return;
    int fim;
    if (f->n == f->dim)
    {
        f->dim *= 2;
        f->vet = (float *)realloc(f->vet, f->dim * sizeof(float));
        if (f->ini != 0)
            memmove(&f->vet[f->dim - f->ini], &f->vet[f->ini],
                    (f->n - f->ini) * sizeof(float));
    }

    fim = (f->ini + f->n) % f->dim;
    f->vet[fim] = v;
    f->n++;
}

float fila_retira(Fila *f)
{
    if (!f || fila_vazia(f))
        return NULL;
    float v;
    v = f->vet[f->ini];
    f->ini = (f->ini + 1) % f->dim;
    f->n--;
    return v;
}

bool fila_vazia(Fila *f)
{
    if (!f)
        return false;
    return f->n == 0;
}

void fila_libera(Fila **f)
{
    free((*f)->vet);
    (*f)->vet = NULL;
    free(*f);
    *f = NULL;
}

void fila_imprime(Fila *f)
{
    if (!f) return;
    for (int i = 0; i < f->n; i++)
        printf("%.2f ", f->vet[(f->ini + i) % f->dim]);
}
