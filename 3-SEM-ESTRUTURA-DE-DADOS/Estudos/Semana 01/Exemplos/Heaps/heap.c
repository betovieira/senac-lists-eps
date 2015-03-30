#include "heap.h"

#include <stdio.h>
#include <stdlib.h>



void erro(char *mensagem) {
  fprintf(stderr, "ERRO: ");

  fputs(mensagem, stderr);

  fprintf(stderr, "\n");

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


void troca(int *v, int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


void sobe(heap *h, int i) {
  while(pai(i) >= 0 && h->v[i] > h->v[pai(i)]) {
    troca(h->v, i, pai(i));

    i = pai(i);
  }
}


void desce(heap *h, int i) {
  int maior;

  while(1) {
    maior = i;

    if(esq(i) < h->n && h->v[maior] < h->v[esq(i)])
      maior = esq(i);

    if(dir(i) < h->n && h->v[maior] < h->v[dir(i)])
      maior = dir(i);

    if(maior == i)
      break;

    troca(h->v, i, maior);

    i = maior;
  }
}


heap *heap_aloca(int max) {
  if(max <= 0)
    erro("maximo do heap deve ser positivo");

  heap *h = malloc(sizeof(heap));

  h->max = max;

  h->n = 0;

  h->v = malloc(h->max * sizeof(int));

  return h;
}


void heap_libera(heap *h) {
  free(h->v);

  free(h);
}


void heap_insere(heap *h, int valor) {
  if(h->n == h->max)
    erro("tentou inserir em heap cheio");

  h->v[h->n] = valor;

  h->n++;

  sobe(h, h->n - 1);
}


int heap_retira(heap *h) {
  if(h->n == 0)
    erro("tentou retirar de heap vazio");

  int valor = h->v[0];

  h->v[0] = h->v[h->n - 1];

  h->n--;

  desce(h, 0);

  return valor;
}


void heap_imprime(heap *h) {
  int i;

  printf("H:");
  for(i = 0; i < h->n; i++)
    printf(" %d", h->v[i]);
  printf("\n");
}
