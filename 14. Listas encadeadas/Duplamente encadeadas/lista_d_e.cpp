#include <stdio.h>
#include <cstdlib>
#include "lista_d_e.h"

using namespace std;

Nod *cria_nod(int info)
{
    Nod *nod = (Nod *)malloc(sizeof(Nod));
    if (!nod)
        return NULL;
    nod->info = info;
    nod->ante = NULL;
    nod->prox = NULL;
    return nod;
}

Listad *cria_listad()
{
    Listad *listad = (Listad *)malloc(sizeof(Listad));
    if (!listad)
        return NULL;
    listad->inicio = NULL;
    listad->fim = NULL;
    return listad;
}

void libera_listad(Listad **l)
{
    if (!(*l))
        return;
    while ((*l)->inicio != NULL)
        remove_inicio(*l);
    free(*l);
    *l = NULL;
}

bool insere_inicio(Listad *l, int info)
{
    if (!l)
        return false;
    Nod *nod = cria_nod(info);
    if (!nod)
        return false;
    if (!l->inicio)
    {
        l->inicio = nod;
        l->fim = nod;
        return true;
    }
    l->inicio->ante = nod;
    nod->prox = l->inicio;
    l->inicio = nod;
    return true;
}

bool insere_meio(Listad* l, int pos, int info) {
    if (!l) return false;
    if (!l->inicio || pos == 0) return insere_inicio(l, info);
    Nod* aux = l->inicio;
    int i = 0;
    while (i < pos-1) {
        if (aux->prox->prox) aux = aux->prox;
        else return insere_fim(l, info);
        i++;
    }
    Nod* nod = cria_nod(info);
    if (!nod) return false;
    nod->prox = aux->prox;
    nod->ante = aux->prox->ante;
    aux->prox->ante = nod;
    aux->prox = nod;
    return true;
}

bool insere_fim(Listad* l, int info) {
    if (!l) return false;
    if (!l->inicio) return insere_inicio(l, info);
    Nod* nod = cria_nod(info);
    if (!nod) return false;
    l->fim->prox = nod;
    nod->ante = l->fim;
    l->fim = nod;
    return true;
}

bool remove_inicio(Listad* l) {
    if (!l || !l->inicio) return false;
    if (!l->inicio->prox) {
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
        return true;
    }
    l->inicio->prox->ante = NULL;
    Nod* aux = l->inicio->prox;
    free(l->inicio);
    l->inicio = aux;
    return true;
}

Nod* busca_nod(Listad* l, int info) {
    if (!l || !l->inicio) return NULL;
    Nod* aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == info) return aux;
        aux = aux->prox;
    }
    return NULL;
}

bool remove_info(Listad* l, int info) {
    if (!l || !l->inicio) return false;
    return modifica_info(l, info, NULL);
}

bool remove_info_all(Listad* l, int info) {
    if (!l || !l->inicio) return false;
    Nod* aux = l->inicio;
    while (aux != NULL) {
        if (aux->info == info) aux->info = NULL;
        aux = aux->prox;
    }
    return true;
}

bool modifica_info(Listad* l, int info, int nova_info) {
    if (!l || !l->inicio) return false;
    Nod* aux = busca_nod(l, info);
    if (!aux) return false;
    aux->info = nova_info;
    return true;
}

void imprime(Listad* l) {
    if (!l || !l->inicio) return;
    Nod* aux = l->inicio;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
