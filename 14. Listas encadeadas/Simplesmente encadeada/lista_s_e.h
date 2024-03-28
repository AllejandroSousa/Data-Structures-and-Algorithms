// TAD: Lista simplesmente encadeada de inteiros

#ifndef LISTA_S_E_H
#define LISTA_S_E_H

struct no {
    int info;
    struct no* prox;
};

struct lista {
    struct no* inicio;
};

typedef struct no No;
typedef struct lista Lista;

No* cria_no(int info);
Lista* cria_lista();
void libera_lista(Lista** l);
bool insere_inicio(Lista* l, int info);
bool insere_meio(Lista* l, int pos, int info);
bool insere_fim(Lista* l, int info);
bool remove_inicio(Lista* l);
bool remove_meio(Lista* l, int pos);
bool remove_fim(Lista* l);
bool remove_info(Lista* l, int info);
bool remove_info_all(Lista* l, int info);
bool modifica_info(Lista* l, int info, int nova_info);
No* busca_no(Lista* l, int info);
void imprime_lista(Lista* l);

#endif