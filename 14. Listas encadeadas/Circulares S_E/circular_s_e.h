// TAD Lista Circular Simplesmente Encadeada

#ifndef CIRCULAR_S_E_H
#define CIRCULAR_S_E_H

struct no {
    int info;
    struct no* prox;
};

struct listac {
    struct no* acesso;
};

typedef struct no No;
typedef struct listac Listac;

No* cria_no(int info);
Listac* cria_listac();
void libera_listac(Listac** l);
bool insere_listac(Listac* l, int info);
bool remove_listac(Listac* l, int info);
bool modifica_listac(Listac* l, int info, int nova_info);
void imprime_listac(Listac* l); 

#endif