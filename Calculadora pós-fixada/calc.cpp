#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "calc.h"
#include "../15. Pilhas/pilhas.h"

struct calc
{
    char f[21];
    Pilha *p;
};

Calc *calc_cria(char *formato)
{
    Calc *c = (Calc *)malloc(sizeof(Calc));
    if (!c)
        return NULL;
    strcpy(c->f, formato);
    c->p = cria_pilha();
    if (!c->p)
        return NULL;
    return c;
}

void calc_operando(Calc *c, float v)
{
    if (!c)
        return;
    pilha_push(c->p, v);
    printf(c->f, v);
}

void calc_operador(Calc *c, char op)
{
    if (!c)
        return;
    float v2 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
    float v1 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);

    float v;
    switch (op)
    {
    case '+':
        v = v1 + v2;
        break;
    case '-':
        v = v1 - v2;
        break;
    case '*':
        v = v1 * v2;
        break;
    case '/':
        v = v1 / v2;
        break;
    }
    pilha_push(c->p, v);
    printf(c->f, v);
}

void calc_libera(Calc **c) {
    if (!(*c)) return;
    pilha_libera(&(*c)->p);
    free(*c);
    *c = NULL;
}