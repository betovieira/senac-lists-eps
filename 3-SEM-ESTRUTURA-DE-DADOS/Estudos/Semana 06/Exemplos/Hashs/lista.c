#include "lista.h"

#include <stdio.h>
#include <stdlib.h>


lista *lista_aloca() {
  lista *l = malloc(sizeof(lista));

  l->comeco = NULL;

  return l;
}


void lista_libera(lista *l) {
  elemento *e, *temp;

  e = l->comeco;

  while(e != NULL) {
    temp = e->proximo;

    free(e);

    e = temp;
  }

  free(l);
}


void lista_insere(lista *l, int valor) {
  elemento *e = malloc(sizeof(elemento));

  e->valor = valor;

  e->proximo = l->comeco;

  l->comeco = e;
}


void lista_retira(lista *l, int valor) {
  elemento *ant, *e;

  ant = NULL;

  e = l->comeco;

  while(e != NULL && e->valor != valor) {
    ant = e;

    e = e->proximo;
  }

  if(e == NULL)
    return;

  if(ant == NULL)
    l->comeco = e->proximo;
  else
    ant->proximo = e->proximo;

  free(e);
}


void lista_imprime(lista *l) {
  elemento *e;

  for(e = l->comeco; e != NULL; e = e->proximo)
    printf(" %d", e->valor);

  printf("\n");
}
