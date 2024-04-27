#ifndef ABB_H
#define ABB_H

typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv* cria_abb();
void libera_arv(Arv* a);
void imprime_abb(Arv* a);
ArvNo* busca_abb(Arv* a, int v);
int altura_abb(Arv* a);
void insere_abb(Arv* a, int v);
void retira_abb(Arv* a, int v);

#endif