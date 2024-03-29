// TAD Lista Duplamente Encadeada

#ifndef LISTA_D_E_H
#define LISTA_D_E_H

struct nod
{
    int info;
    struct nod *ante;
    struct nod *prox;
};

struct listad
{
    struct nod *inicio;
    struct nod *fim;
};

typedef struct nod Nod;
typedef struct listad Listad;

Nod* cria_nod(int info);
Listad* cria_listad();
void libera_listad(Listad** l);
bool insere_inicio(Listad* l, int info);
bool insere_meio(Listad* l, int pos, int info);
bool insere_fim(Listad* l, int info);
bool remove_inicio(Listad* l);
Nod* busca_nod(Listad* l, int info);
bool remove_info(Listad* l, int info);
bool remove_info_all(Listad* l, int info);
bool modifica_info(Listad* l, int info, int nova_info);
void imprime(Listad* l);

#endif