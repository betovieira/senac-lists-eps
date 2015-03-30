#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>


pilha *pilha_aloca() {
  pilha *p = malloc(sizeof(pilha));

  p->comeco = NULL;

  return p;
}


void pilha_libera(pilha *p) {
  elemento *e, *temp;

  e = p->comeco;

  while(e != NULL) {
    temp = e->proximo;

    free(e);

    e = temp;
  }

  free(p);
}


int pilha_vazia(pilha *p) {
  if(p->comeco == NULL)
    return 1;

  return 0;
}


void pilha_insere(pilha *p, int valor) {
  elemento *e = malloc(sizeof(elemento));

  e->valor = valor;

  e->proximo = p->comeco;

  p->comeco = e;
}


int pilha_retira(pilha *p) {
  int valor;

  elemento *e = p->comeco;

  if(e == NULL) {
    fprintf(stderr, "ERRO: tentou retirar de lista vazia\n");
    exit(EXIT_FAILURE);
  }

  p->comeco = e->proximo;

  valor = e->valor;

  free(e);

  return valor;
}
