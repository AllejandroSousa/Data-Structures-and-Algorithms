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

// Abaixo estão alguns exercícios feitos com funções que não são essenciais para esse TAD,
// por isso optei por deixá-las todas comentadas.


/* Ex.1: Implemente uma função que tenha como valor de retorno o
comprimento de uma lista encadeada, isto é, que calcule o número de
nós de uma lista. */
// int comprimento(Lista *l) {
//     if (!l) return NULL;
//     No *aux = l->inicio;
//     int i = 0;
//     while (aux != NULL) {
//         aux = aux->prox;
//         i++;
//     }
//     return i;
// }


/* Ex. 2: Considerando listas encadeadas de valores inteiros, 
implemente uma função que retorne o número de nós da lista que 
possuem o campo info com valores maiores do que x. */
// int maiores(Lista *l, int x) {
//     if (!l || !l->inicio) return NULL;
//     No *aux = l->inicio;
//     int i = 0;
//     while (aux != NULL) {
//         if (aux->info > x) i++;
//         aux = aux->prox;
//     }
//     return i;
// }

/* Ex. 3: Implemente uma função que retorne o último valor de uma lista encadeada de inteiros. */
// int ultimo(Lista *l) {
//     if (!l || !l->inicio) return NULL;
//     No *aux = l->inicio;
//     while (aux->prox != NULL) aux = aux->prox;
//     return aux->info;
// }

/* Ex. 4: Implemente uma função que receba duas listas encadeadas de valores reais e transfira para 
o final da primeira lista os elementos da segunda. No final, a primeira lista representará a 
concatenação das duas listas e a segunda lista estará vazia. */
// void concatena(Lista *l1, Lista *l2) {
//     if (!l1 || !l2 || !l2->inicio) return;
//     if (!l1->inicio) {
//         l1->inicio = l2->inicio;
//         l2->inicio = NULL;
//         return;
//     }
//     No *aux = l1->inicio;
//     while (aux->prox != NULL) aux = aux->prox;
//     aux->prox = l2->inicio;
//     l2->inicio = NULL;
// }

/* Ex. 5: Considerando listas de valores inteiros, implemente uma função que receba como parâmetros uma 
lista encadeada e um valor inteiro x, e retire da lista todas as ocorrências de x. */
// void retira_n(Lista *l, int x) {
//     if (!l || !l->inicio) return;
//     while (l->inicio->info == x) {
//         No *aux = l->inicio->prox;
//         free(l->inicio);
//         l->inicio = aux;
//     }
//     No *aux = l->inicio;
//     while (aux != NULL && aux->prox != NULL) {
//         if (aux->prox->info == x) {
//             No *aux2 = aux->prox->prox;
//             free(aux->prox);
//             aux->prox = aux2;
//         }
//         aux = aux->prox;
//     }
// }

/* Ex. 6: Considerando listas de valores inteiros, implemente uma função que receba como parâmetro 
uma lista encadeada e um valor inteiro x e divida a lista em duas, de tal forma que a segunda lista, 
criada dentro da função, comece no primeiro nó logo após a primeira ocorrência de x na lista original. 
A função deve ter como valor de retorno a lista criada, mesmo que ela seja vazia */
// Lista* separa(Lista *l, int x) {
//     if (!l) return;
//     Lista *l2 = cria_lista();
//     if (!l2) return NULL;
//     if (!l->inicio) return l2;
//     No *aux = l->inicio;
//     while (aux->prox != NULL) {
//         if (aux->info == x) {
//             l2->inicio = aux->prox;
//             aux->prox = NULL;
//             return l2;
//         }
//         aux = aux->prox;
//     }
//     return l2;
// }

/* Ex. 7: Implemente uma função que construa uma nova lista, intercalando os nós de outras 
duas listas passadas como parâmetros. Essa função deve retornar a nova lista resultante, 
criada dentro da função. */
// Lista* merge(Lista *l1, Lista *l2) {
//     if (!l1 || !l2) return;
//     Lista *l3 = cria_lista();
//     if (!l3) return;
//     No *aux = l1->inicio;
//     No *aux2 = l2->inicio;
//     while (aux != NULL || aux2 != NULL) {
//         if (aux != NULL) {
//             insere_fim(l3, aux->info);
//             No *aux3 = aux->prox;
//             free(aux);
//             aux = aux3;
//         }
//         if (aux2 != NULL) {
//             insere_fim(l3, aux2->info);
//             No *aux3 = aux2->prox;
//             free(aux2);
//             aux2 = aux3;
//         }
//     }
//     free(l1);
//     l1 = NULL;
//     free(l2);
//     l2 = NULL;
// }

/* Ex. 8: Implemente uma função que receba como parâmetro uma lista encadeada e 
inverta o encadeamento de seus nós. Após a execução dessa função, cada nó da lista 
vai estar apontando para o nó que originalmente era seu antecessor, e o último nó da 
lista passará a ser o primeiro nó da lista invertida */
// void inverte(Lista *l) {
//     if (!l || !l->inicio) return;
//     No *aux = l->inicio;
//     No *ant = NULL;
//     No *aux2;
//     while (aux != NULL) {
//         aux2 = aux->prox;
//         aux->prox = ant;
//         ant = aux;
//         aux = aux2;
//     }
//     l->inicio = ant;
// }

/* Ex. 10: Implemente uma função que transforma uma lista simplesmente encadeada numa lista circular*/
// void para_circular(Lista *l) {
//     if (!l || !l->inicio) return;
//     if (!l->inicio->prox) {
//         l->inicio->prox = l->inicio;
//         return;
//     }
//     No *aux = l->inicio;
//     while (aux->prox != NULL) aux = aux->prox;
//     aux->prox = l->inicio;
// }

/* Ex. 11: Implemente as funções para retirar elementos do início e do final de uma lista duplamente encadeada. 
Resposta no arquivo lista_d_e.cpp na pasta Duplamente encadeadas*/
