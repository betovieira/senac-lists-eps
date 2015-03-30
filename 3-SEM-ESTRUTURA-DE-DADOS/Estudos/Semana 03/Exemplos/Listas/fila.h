#ifndef FILA_H
#define FILA_H


typedef struct _elemento {
  int valor;
  struct _elemento *proximo;
} elemento;

typedef struct {
  elemento *comeco, *fim;
} fila;


fila *fila_aloca();
void fila_libera(fila *);

void fila_insere(fila *, int);
int fila_retira(fila *);

void fila_imprime(fila *);


#endif
