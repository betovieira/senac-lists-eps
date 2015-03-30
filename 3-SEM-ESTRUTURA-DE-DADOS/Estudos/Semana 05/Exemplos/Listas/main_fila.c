#include "fila.h"

#include <stdio.h>
#include <stdlib.h>



int main() {
  fila *f = fila_aloca();

  fila_imprime(f);

  fila_insere(f, 1);
  fila_insere(f, 2);
  fila_insere(f, 3);

  fila_imprime(f);

  printf("retirou %d\n", fila_retira(f));
  printf("retirou %d\n", fila_retira(f));

  fila_imprime(f);

  fila_insere(f, 4);
  fila_insere(f, 5);
  fila_insere(f, 6);

  fila_imprime(f);

  fila_libera(f);

  return EXIT_SUCCESS;
}
