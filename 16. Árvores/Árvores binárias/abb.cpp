#include <stdio.h>
#include <cstdlib>
#include "abb.h"

using namespace std;

struct arvno {
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv {
    ArvNo* raiz;
};

Arv* cria_abb() {
    Arv* a = (Arv*) malloc(sizeof(Arv));
    if (!a) return NULL;
    a->raiz = NULL;
    return a;
}

static void imprime(ArvNo* r) {
    if (r != NULL) {
        imprime(r->esq);
        printf("%d\n", r->info);
        imprime(r->dir);
    }
}

void imprime_abb(Arv* a) {
    if (!a) return;
    return imprime(a->raiz);
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

static ArvNo* busca (ArvNo* r, int v) {
    if (!r) return NULL;
    else if (r->info > v) return busca(r->esq, v);
    else if (r->info < v) return busca(r->dir, v);
    else return r;
}

ArvNo* busca_abb(Arv* a, int v) {
    if (!a) return;
    return busca(a->raiz, v);
}

static ArvNo* insere(ArvNo* r, int v) {
    if (!r) {
        r = (ArvNo*) malloc(sizeof(ArvNo));
        if (!r) return NULL;
        r->info = v;
        r->esq = r->dir = NULL;
    } else if (v < r->info) r->esq = insere(r->esq, v);
    else r->dir = insere(r->dir, v);
    return r;
}

void insere_abb(Arv* a, int v) {
    if (!a) return;
    a->raiz = insere(a->raiz, v);
}

static ArvNo* retira(ArvNo* r, int v) {
    if (!r) return NULL;
    else if (r->info > v) r->esq = retira(r->esq, v);
    else if (r->info < v) r->dir = retira(r->dir, v);
    else {
        if (r->esq == NULL && r->dir == NULL) {
            free (r);
            r = NULL;
        } else if (r->esq == NULL) {
            ArvNo* t = r;
            r = r->dir;
            free(t);
        } else if (r->dir == NULL) {
            ArvNo* t = r;
            r = r->esq;
            free(t);
        } else {
            ArvNo* f = r->esq; // creio q deveria ser f = r->dir;
            while (f->dir != NULL) f = f->dir;
            r->info = f->info;
            f->info = v;
            r->esq = retira(r->esq, v);
        }
    }
    return r;
}

void retira_abb (Arv* a, int v) {
    if (!a) return;
    a->raiz = retira(a->raiz, v);
}

static int max2(int a, int b) {
    return (a > b) ? a : b;
}

static int altura(ArvNo* r) {
    if (!r) return -1;
    else return 1 + max2(altura(r->esq), altura(r->dir));
}

int altura_abb(Arv* a) {
    if (!a) return;
    return altura(a->raiz);
}