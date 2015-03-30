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
  int i, frequencias[TAM], max, j;
  FILE *entrada;
  no *n, *esq, *dir, *m;
  heap *h;

  entrada = fopen("codificado.txt", "r");

  for(i = 0; i < TAM; i++)
    frequencias[i] = 0;

  fscanf(entrada, "%d", &max);
  getc(entrada);

  h = heap_aloca(max);

  for(j = 0; j < max; j++) {
    i = getc(entrada);
    getc(entrada);

    fscanf(entrada, "%d", &frequencias[i]);
    getc(entrada);

    n = malloc(sizeof(no));
    n->letra = i;
    n->frequencia = frequencias[i];
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;

    heap_insere(h, n);
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

  m = n;

  while(1) {
    i = getc(entrada);

    if(i == EOF)
      break;

    if(i == '0')
      m = m->esq;
    else
      m = m->dir;

    if(m->esq == NULL && m->dir == NULL) {
      printf("%c", m->letra);

      m = n;
    }
  }

  libera(n);

  fclose(entrada);

  return EXIT_SUCCESS;
}
