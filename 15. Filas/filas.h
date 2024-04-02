// TAD Fila

#ifndef FILAS_H
#define FILAS_H

typedef struct no No;
typedef struct fila Fila;

Fila *fila_cria();
void fila_insere(Fila *f, float v);
float fila_retira(Fila *f);
bool fila_vazia(Fila *f);
void fila_libera(Fila **f);
void fila_imprime(Fila *f);

#endif