#include <stdio.h>
#include <cstdlib>
#include "arvbin.h"

using namespace std;

struct arvno {
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv {
    ArvNo* raiz;
};

ArvNo* criano_arv(char c, ArvNo* esq, ArvNo* dir) {
    ArvNo* p = (ArvNo*) malloc(sizeof(ArvNo));
    if (!p) return NULL;
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

Arv* cria_arv(ArvNo* r) {
    if (!r) return NULL;
    Arv* a = (Arv*) malloc(sizeof(Arv));
    if (!a) return NULL;
    a->raiz = r;
    return a;
}

static void imprime(ArvNo* r) {
    printf("<");
    if (r != NULL) {
        printf(" %c", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }
    printf(">");
}

void imprime_arv(Arv* a) {
    if (!a) return;
    imprime(a->raiz);
}

static void libera(ArvNo* r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void libera_arv(Arv *a) {
    if (!a) return;
    libera(a->raiz);
    free(a);
}

static bool pertence(ArvNo* r, char c) {
    if (!r) return false;
    else
        return c == r->info || pertence(r->esq, c) || pertence(r->dir, c);     
}

bool pertence_arv(Arv* a, char c) {
    if (!a) return;
    return pertence(a->raiz, c);
}

static ArvNo* busca(ArvNo* r, char c) {
    if (!r) return NULL;
    else if (c == r->info) return r;
    else {
        ArvNo* p = busca(r->esq, c);
        if (p != NULL) return p;
        else return busca(r->dir, c);
    }
}

ArvNo* busca_arv(Arv* a, char c) {
    if (!a) return;
    return busca(a->raiz, c);
}

static int max2(int a, int b) {
    return (a > b) ? a : b;
}

static int altura(ArvNo* r) {
    if (!r) return -1;
    else return 1 + max2(altura(r->esq), altura(r->dir));
}

int altura_arv(Arv* a) {
    if (!a) return;
    return altura(a->raiz);
}