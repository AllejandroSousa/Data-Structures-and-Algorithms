// TAD Lista Circular Duplamente Encadeada

#ifndef CIRCULAR_D_E_H
#define CIRCULAR_D_E_H

typedef struct no No;
typedef struct listacd Listacd;

No* cria_no(int info);
Listacd* cria_listacd();
void libera_listacd(Listacd** l);
bool insere_listacd(Listacd* l, int info);
bool remove_listacd(Listacd* l, int info);
bool modifica_listacd(Listacd* l, int info, int nova_info);
void imprime_listacd(Listacd* l);

#endif