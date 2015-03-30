#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>



int main() {
  pilha *p = pilha_aloca();

  pilha_imprime(p);

  pilha_insere(p, 1);
  pilha_insere(p, 2);
  pilha_insere(p, 3);

  pilha_imprime(p);

  printf("retirou %d\n", pilha_retira(p));
  printf("retirou %d\n", pilha_retira(p));

  pilha_imprime(p);

  pilha_insere(p, 4);
  pilha_insere(p, 5);
  pilha_insere(p, 6);

  pilha_imprime(p);

  pilha_libera(p);

  return EXIT_SUCCESS;
}
