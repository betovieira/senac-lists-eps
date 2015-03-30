#ifndef HUFFMAN_H
#define HUFFMAN_H


typedef struct _no {
  unsigned char letra;
  int frequencia;
  struct _no *pai, *esq, *dir;
} no;

typedef struct {
  int max, n;
  no **v;
} heap;


heap *heap_aloca(int);
void heap_libera(heap *);

void heap_insere(heap *, no *);
no *heap_retira(heap *);

void heap_imprime(heap *);
int heap_tamanho(heap *);


#endif
