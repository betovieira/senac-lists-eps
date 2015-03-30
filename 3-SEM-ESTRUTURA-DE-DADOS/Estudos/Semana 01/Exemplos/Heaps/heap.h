#ifndef HEAP_H
#define HEAP_H


typedef struct {
  int max, n, *v;
} heap;


heap *heap_aloca(int max);
void heap_libera(heap *h);

void heap_insere(heap *h, int valor);
int heap_retira(heap *h);

void heap_imprime(heap *h);


#endif
