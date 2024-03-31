#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "pilhas.h"

using namespace std;

struct pilha
{
    int n;
    int dim;
    float *vet;
};

Pilha *cria_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (!p)
        return NULL;
    p->dim = 2;
    p->vet = (float *)malloc(p->dim * sizeof(float));
    p->n = 0;
}

void pilha_push(Pilha *p, float v)
{
    if (!p)
        return;
    if (p->n == p->dim)
    {
        p->dim *= 2;
        p->vet = (float *)realloc(p->vet, p->dim * sizeof(float));
    }
    p->vet[p->n++] = v;
}

float pilha_pop(Pilha *p)
{
    if (!p || p->n == 0)
        return NULL;
    float v = p->vet[--p->n];
    return v;
}

bool pilha_vazia(Pilha *p)
{
    if (!p)
        return false;
    return (p->n == 0);
}

void pilha_libera(Pilha **p)
{
    if (!(*p))
        return;
    free((*p)->vet);
    (*p)->vet = NULL;
    free(*p);
    *p = NULL;
}

void imprime_pilha(Pilha *p)
{
    if (!p || p->n == 0)
        return;
    for (int i = 0; i < p->n; i++)
        printf("%.2f ", p->vet[i]);
}