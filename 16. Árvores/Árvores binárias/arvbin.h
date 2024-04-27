#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv* cria_arv(ArvNo* r);
ArvNo* criano_arv(char c, ArvNo* e, ArvNo* d);
void libera_arv(Arv* a);
void imprime_arv(Arv* a);
bool pertence_arv(Arv* a, char c);
ArvNo* busca_arv(Arv* a, char c);
int altura_arv(Arv* a);

#endif