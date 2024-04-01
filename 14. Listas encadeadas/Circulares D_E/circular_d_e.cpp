#include <stdio.h>
#include <cstdlib>
#include "circular_d_e.h"

struct no {
    int info;
    struct no* prox;
    struct no* ante;
};

struct listacd {
    struct no* acesso;
};

No* cria_no(int info) {
    No* no = (No*) malloc(sizeof(No));
    if (!no) return NULL;
    no->info = info;
    no->prox = NULL;
    no->ante = NULL;
    return no;
}

Listacd* cria_listacd() {
    Listacd* l = (Listacd*) malloc(sizeof(Listacd));
    if (!l) return NULL;
    l->acesso = NULL;
    return l;
}

void libera_listacd(Listacd** l) {
    if (!(*l)) return;
    if (!(*l)->acesso) {
        free(*l);
        *l = NULL;
        return;
    }
    while ((*l)->acesso != (*l)->acesso->prox->prox) {
        No* aux = (*l)->acesso->prox->prox;
        free((*l)->acesso->prox);
        (*l)->acesso->prox = aux;
    }
    free((*l)->acesso->prox);
    free((*l)->acesso);
    free(*l);
    *l = NULL;
}

bool insere_listacd(Listacd* l, int info) {
    if (!l) return false;
    No* no = cria_no(info);
    if (!no) return false;
    no->info = info;
    if (!l->acesso) {
        l->acesso = no;
        no->prox = l->acesso;
        no->ante = l->acesso;
        return true;
    }
    if (!l->acesso->prox) {
        l->acesso->prox = no;
        l->acesso->ante = no;
        no->prox = l->acesso;
        no->ante = l->acesso;
        return true;
    }
    no->prox = l->acesso->prox;
    no->ante = l->acesso;
    l->acesso->prox->ante = no;
    l->acesso->prox = no;
    return true;
}

bool remove_listacd(Listacd* l, int info) {
    if (!l || !l->acesso) return false;
    if (l->acesso->info == info) {
        l->acesso->ante->prox = l->acesso->prox;
        l->acesso->prox->ante = l->acesso->ante;
        free(l->acesso);
        l->acesso = NULL;
        return true;
    }
    No* aux = l->acesso->prox;
    while (aux != l->acesso) {
        if (aux->info == info) {
            aux->prox->ante = aux->ante;
            aux->ante->prox = aux->prox;
            free(aux);
            aux = NULL;
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

bool modifica_listacd(Listacd* l, int info, int nova_info) {
    if (!l || !l->acesso) return false;
    if (l->acesso->info == info) {
        l->acesso->info = nova_info;
        return true;
    }
    No* aux = l->acesso->prox;
    while (aux != l->acesso) {
        if (aux->info == info) {
            aux->info = nova_info;
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void imprime_listacd(Listacd* l) {
    if (!l || !l->acesso) return;
    printf("%d ", l->acesso->info);
    No* aux = l->acesso->prox;
    while (aux != l->acesso) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
