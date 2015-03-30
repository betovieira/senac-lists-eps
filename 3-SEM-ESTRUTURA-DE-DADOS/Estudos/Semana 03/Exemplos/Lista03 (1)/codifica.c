#include "pilha.h"
#include "huffman.h"

#include <stdio.h>
#include <stdlib.h>



#define TAM 256



void libera(no *n) {
  if(n == NULL)
    return;

  libera(n->esq);
  libera(n->dir);

  free(n);
}


int main() {
  int i, frequencias[TAM], max;
  FILE *entrada;
  pilha *p;
  no *n, *nos[TAM], *esq, *dir;
  heap *h;

  entrada = fopen("decodificado.txt", "r");

  for(i = 0; i < TAM; i++)
    frequencias[i] = 0;

  while(1) {
    i = getc(entrada);

    if(i == EOF)
      break;

    frequencias[i]++;
  }

  rewind(entrada);

  max = 0;

  for(i = 0; i < TAM; i++)
    if(frequencias[i] > 0)
      max++;

  printf("%d ", max);

  h = heap_aloca(max);

  for(i = 0; i < TAM; i++)
    if(frequencias[i] > 0) {
      printf("%c %d ", i, frequencias[i]);

      n = malloc(sizeof(no));
      n->letra = i;
      n->frequencia = frequencias[i];
      n->pai = NULL;
      n->esq = NULL;
      n->dir = NULL;

      heap_insere(h, n);

      nos[i] = n;
    }

  while(heap_tamanho(h) > 1) {
    esq = heap_retira(h);
    dir = heap_retira(h);

    n = malloc(sizeof(no));
    n->frequencia = esq->frequencia + dir->frequencia;
    n->pai = NULL;
    n->esq = esq;
    n->dir = dir;

    esq->pai = n;
    dir->pai = n;

    heap_insere(h, n);
  }

  n = heap_retira(h);

  heap_libera(h);

  p = pilha_aloca();

  while(1) {
    i = getc(entrada);

    if(i == EOF)
      break;

    for(n = nos[i]; n->pai != NULL; n = n->pai)
      if(n == n->pai->esq)
        pilha_insere(p, 0);
      else
        pilha_insere(p, 1);

    while(!pilha_vazia(p))
      printf("%d", pilha_retira(p));
  }

  pilha_libera(p);

  libera(n);

  fclose(entrada);

  return EXIT_SUCCESS;
}
