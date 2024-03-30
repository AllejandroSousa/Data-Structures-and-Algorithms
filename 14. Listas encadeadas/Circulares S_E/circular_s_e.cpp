#include <stdio.h>
#include <cstdlib>
#include "circular_s_e.h"

using namespace std;

No* cria_no(int info) {
    No* no = (No*) malloc(sizeof(No));
    if (!no) return NULL;
    no->info = info;
    no->prox = NULL;
    return no;
}

Listac* cria_listac() {
    Listac* l = (Listac*) malloc(sizeof(Listac));
    if (!l) return NULL;
    l->acesso = NULL;
    return l;
}

void libera_listac(Listac** l) {
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

bool insere_listac(Listac* l, int info) {
    if (!l) return false;
    if (!l->acesso) {
        No* no = cria_no(info);
        if (!no) return false;
        l->acesso = no;
        no->prox = l->acesso;
        return true;
    }
    if (l->acesso->prox == l->acesso) {
        No* no = cria_no(info);
        if (!no) return false;
        no->prox = l->acesso;
        l->acesso->prox = no;
        return true;
    }
    No* no = cria_no(info);
    if (!no) return false;
    No* aux = l->acesso->prox;
    l->acesso->prox = no;
    no->prox = aux;
    return true;
}

bool remove_listac(Listac* l, int info) {
    if (!l || !l->acesso) return false;
    if (l->acesso->prox == l->acesso) {
        free(l->acesso);
        l->acesso = NULL;
        return true;
    }
    if (l->acesso->prox->info == info) {
        No* aux = l->acesso->prox->prox;
        free(l->acesso->prox);
        l->acesso->prox = aux;
        return true;
    }
    No* aux = l->acesso->prox;
    while (aux != l->acesso) {
        if (aux->prox->info == info) {
            No* aux2 = aux->prox->prox;
            free(aux->prox);
            aux->prox = aux2;
            return true;
        }
    }
    return false;
}

bool modifica_listac(Listac* l, int info, int nova_info) {
    if (!l || !l->acesso) return false;
    if (l->acesso->info == info) l->acesso->info = nova_info;
    No* aux = l->acesso->prox;
    while (l->acesso != aux) {
        if (aux->info == info) {
            aux->info = nova_info;
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void imprime_listac(Listac* l) {
    if (!l || !l->acesso) return;
    printf("%d ", l->acesso->info);
    No* aux = l->acesso->prox;
    while (aux != l->acesso) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}