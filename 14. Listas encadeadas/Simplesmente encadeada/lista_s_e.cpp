#include <stdio.h>
#include <cstdlib>
#include "lista_s_e.h"

using namespace std;

struct no {
    int info;
    struct no* prox;
};

struct lista {
    struct no* inicio;
};


No* cria_no(int info) {
    No *no = (No *)malloc(sizeof(No));
    if (!no) return NULL;
    no->info = info;
    no->prox = NULL;
    return no;
}

Lista* cria_lista() {
    Lista* l = (Lista*) malloc (sizeof(Lista));
    if (!l) return NULL;
    l->inicio = NULL;
    return l;
}

void libera_lista(Lista** l) {
    if (!(*l)) return;
    while ((*l)->inicio != NULL) remove_inicio(*l);
    free(*l);
    *l = NULL;
}

bool insere_inicio(Lista* l, int info) {
    if (!l) return false;
    No* no = cria_no(info);
    if (!no) return false;
    no->prox = l->inicio;
    l->inicio = no;
    return true;
}

bool insere_meio(Lista*l, int pos, int info) {
    if (!l) return false;
    if (!l->inicio || pos == 0) return insere_inicio(l, info);    
    No* aux = l->inicio;
    int i = 0;
    while (i < pos-1) {
        if (aux->prox) aux = aux->prox;
        else return insere_fim(l, info);
        i++;
    }
    No* no = cria_no(info);
    if (!no) return false;
    no->prox = aux->prox;
    aux->prox = no;
    return no;
}

bool insere_fim(Lista* l, int info) {
    if (!l) return false;
    if (!l->inicio) return insere_inicio(l, info);
    No* aux = l->inicio;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = cria_no(info);
    return aux->prox != NULL;
}

bool remove_inicio(Lista* l) {
    if (!l || !l->inicio) return false;
    No* aux = l->inicio->prox;
    free(l->inicio);
    l->inicio = aux;
    return true;
}

bool remove_meio(Lista* l, int pos) {
    if (!l || !l->inicio) return false;
    if (!l->inicio->prox) return remove_inicio(l);
    No* aux = l->inicio;
    int i = 0;
    while (i < pos-1) {
        if (!aux->prox) return remove_fim(l);
        aux = aux->prox;
        i++;
    }
    No* aux2 = aux->prox->prox;
    free(aux->prox);
    aux->prox = aux2;
    return true;
}

bool remove_fim(Lista* l) {
    if (!l || !l->inicio) return false;
    if (!l->inicio->prox) return remove_inicio(l);
    No* aux = l->inicio;
    while (aux->prox->prox != NULL) aux = aux->prox;
    free(aux->prox);
    aux->prox = NULL;
    return true;
}

bool remove_info(Lista* l, int info) {
    if (!l || !l->inicio) return false;
    return modifica_info(l, info, NULL);
}

bool remove_info_all(Lista* l, int info) {
    if (!l || !l->inicio) return false;
    No* aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == info) aux->info = NULL;
        aux = aux->prox;
    }
    return true;
}

bool modifica_info(Lista* l, int info, int nova_info) {
    No* aux = busca_no(l, info);
    if (!aux) return false;
    aux->info = nova_info;
    return true;
}

No* busca_no(Lista* l, int info) {
    if (!l || !l->inicio) return NULL;
    No* aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == info) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void imprime_lista(Lista* l) {
    if (!l || !l->inicio) return;
    No* aux = l->inicio;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}