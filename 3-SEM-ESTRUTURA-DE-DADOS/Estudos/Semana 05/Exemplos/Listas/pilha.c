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


void pilha_imprime(pilha *p) {
  elemento *e;

  printf("P:");

  for(e = p->comeco; e != NULL; e = e->proximo)
    printf(" %d", e->valor);

  printf("\n");
}
