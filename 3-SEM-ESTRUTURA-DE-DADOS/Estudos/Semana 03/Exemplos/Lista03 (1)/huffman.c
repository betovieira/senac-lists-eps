#include "huffman.h"

#include <stdio.h>
#include <stdlib.h>


void erro(char *mensagem) {
  fprintf(stderr, "ERRO: %s\n", mensagem);
  exit(EXIT_FAILURE);
}


int pai(int i) {
  return (i - 1) / 2;
}


int esq(int i) {
  return 2 * i + 1;
}


int dir(int i) {
  return 2 * i + 2;
}


void troca(no **v, int i, int j) {
  no *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


void sobe(heap *h, int i) {
  while(pai(i) >= 0 && h->v[i]->frequencia < h->v[pai(i)]->frequencia) {
    troca(h->v, i, pai(i));

    i = pai(i);
  }
}


void desce(heap *h, int i) {
  int menor;

  while(1) {
    menor = i;

    if(esq(i) < h->n && h->v[menor]->frequencia > h->v[esq(i)]->frequencia)
      menor = esq(i);

    if(dir(i) < h->n && h->v[menor]->frequencia > h->v[dir(i)]->frequencia)
      menor = dir(i);

    if(menor == i)
      break;

    troca(h->v, i, menor);

    i = menor;
  }
}


heap *heap_aloca(int max) {
  if(max <= 0)
    erro("maximo do heap deve ser positivo");

  heap *h = malloc(sizeof(heap));

  h->max = max;

  h->n = 0;

  h->v = malloc(h->max * sizeof(no *));

  return h;
}


void heap_libera(heap *h) {
  free(h->v);

  free(h);
}


void heap_insere(heap *h, no *valor) {
  if(h->n == h->max)
    erro("tentou inserir em heap cheio");

  h->v[h->n] = valor;

  h->n++;

  sobe(h, h->n - 1);
}


no *heap_retira(heap *h) {
  if(h->n == 0)
    erro("tentou retirar de heap vazio");

  no *valor = h->v[0];

  h->v[0] = h->v[h->n - 1];

  h->n--;

  desce(h, 0);

  return valor;
}


void heap_imprime(heap *h) {
  int i;

  printf("H:");

  for(i = 0; i < h->n; i++)
    printf(" %d", h->v[i]->frequencia);

  printf("\n");
}


int heap_tamanho(heap *h) {
  return h->n;
}
