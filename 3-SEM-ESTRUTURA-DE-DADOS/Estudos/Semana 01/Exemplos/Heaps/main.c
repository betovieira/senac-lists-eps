#include <stdio.h>
#include <stdlib.h>

#include "heap.h"



int main() {
  heap *h = heap_aloca(10);

  heap_insere(h, 4);
  heap_insere(h, 1);
  heap_insere(h, 3);
  heap_insere(h, 2);
  heap_insere(h, 16);
  heap_insere(h, 9);
  heap_insere(h, 10);
  heap_insere(h, 14);
  heap_insere(h, 8);
  heap_insere(h, 7);

  heap_imprime(h);

  int valor = heap_retira(h);

  printf("retirou %d\n", valor);
  heap_imprime(h);

  heap_insere(h, valor);

  printf("inseriu %d\n", valor);
  heap_imprime(h);

  heap_libera(h);

  return EXIT_SUCCESS;
}
