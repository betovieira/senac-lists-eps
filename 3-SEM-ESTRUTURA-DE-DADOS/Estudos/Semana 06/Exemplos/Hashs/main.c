#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
  int n;

  printf("Digite um numero: ");
  scanf("%d", &n);

  int i, v[n];

  hash *h = hash_aloca(11);

  srand(time(NULL));

  for(i = 0; i < n; i++) {
    v[i] = (rand() / (float) RAND_MAX) * 100 + 0.5;

    printf("\ninserindo %d...\n", v[i]);

    hash_insere(h, v[i]);

    hash_imprime(h);
  }

  while(n > 0) {
    i = (rand() / (float) RAND_MAX) * (n - 1) + 0.5;

    int temp = v[i];
    v[i] = v[n - 1];
    v[n - 1] = temp;

    printf("\nretirando %d\n", v[n - 1]);

    hash_retira(h, v[n - 1]);

    hash_imprime(h);

    n--;
  }

  hash_libera(h);

  return EXIT_SUCCESS;
}
