#include "hash.h"

#include <stdio.h>
#include <stdlib.h>


hash *hash_aloca(int m) {
  int i;

  hash *h = malloc(sizeof(hash));

  h->m = m;

  h->l = malloc(h->m * sizeof(lista *));

  for(i = 0; i < h->m; i++)
    h->l[i] = lista_aloca();

  return h;
}


void hash_libera(hash *h) {
  int i;

  for(i = 0; i < h->m; i++)
    lista_libera(h->l[i]);

  free(h->l);

  free(h);
}


void hash_insere(hash *h, int valor) {
  lista *l = h->l[valor % h->m];

  lista_insere(l, valor);
}


void hash_retira(hash *h, int valor) {
  lista *l = h->l[valor % h->m];

  lista_retira(l, valor);
}


void hash_imprime(hash *h) {
  int i;

  for(i = 0; i < h->m; i++) {
    printf("%d:", i);

    lista_imprime(h->l[i]);
  }
}
