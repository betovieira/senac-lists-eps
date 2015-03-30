#include "fila.h"

#include <stdio.h>
#include <stdlib.h>


fila *fila_aloca() {
  fila *f = malloc(sizeof(fila));

  f->comeco = NULL;

  f->fim = NULL;

  return f;
}


void fila_libera(fila *f) {
  elemento *e, *temp;

  e = f->comeco;

  while(e != NULL) {
    temp = e->proximo;

    free(e);

    e = temp;
  }

  free(f);
}


void fila_insere(fila *f, int valor) {
  elemento *e = malloc(sizeof(elemento));

  e->valor = valor;

  e->proximo = NULL;

  if(f->fim == NULL) {
    f->comeco = e;

    f->fim = e;
  }
  else {
    f->fim->proximo = e;

    f->fim = e;
  }
}


int fila_retira(fila *f) {
  int valor;

  elemento *e = f->comeco;

  if(e == NULL) {
    fprintf(stderr, "ERRO: tentou retirar de lista vazia\n");
    exit(EXIT_FAILURE);
  }

  f->comeco = e->proximo;

  if(f->comeco == NULL)
    f->fim = NULL;

  valor = e->valor;

  free(e);

  return valor;
}


void fila_imprime(fila *f) {
  elemento *e;

  printf("F:");

  for(e = f->comeco; e != NULL; e = e->proximo)
    printf(" %d", e->valor);

  printf("\n");
}
