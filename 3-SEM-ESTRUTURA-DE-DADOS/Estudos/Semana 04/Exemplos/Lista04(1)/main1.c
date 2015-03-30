/* Exercicio 10 */



#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
  int n;

  printf("Digite um numero: ");
  scanf("%d", &n);

  int i, v[n];

  arvore *a = arvore_aloca();

  srand(time(NULL));

  for(i = 0; i < n; i++) {
    v[i] = (rand() / (float) RAND_MAX) * 100 + 0.5;

    printf("\ninserindo %d...\n", v[i]);

    arvore_insere(a, v[i]);

    arvore_imprime(a);

    printf("V: %d %d %d\n", valida1(a->raiz), valida2(a->raiz), valida3(a->raiz));
  }

  while(n > 0) {
    i = (rand() / (float) RAND_MAX) * (n - 1) + 0.5;

    int temp = v[i];
    v[i] = v[n - 1];
    v[n - 1] = temp;

    printf("\nretirando %d\n", v[n - 1]);

    arvore_retira(a, v[n - 1]);

    arvore_imprime(a);

    printf("V: %d %d %d\n", valida1(a->raiz), valida2(a->raiz), valida3(a->raiz));

    n--;
  }

  arvore_libera(a);

  return EXIT_SUCCESS;
}
