#ifndef LISTA_H
#define LISTA_H


typedef struct _elemento {
  int valor;
  struct _elemento *proximo;
} elemento;

typedef struct {
  elemento *comeco;
} lista;


lista *lista_aloca();
void lista_libera(lista *);

void lista_insere(lista *, int);
void lista_retira(lista *, int);

void lista_imprime(lista *);


#endif
