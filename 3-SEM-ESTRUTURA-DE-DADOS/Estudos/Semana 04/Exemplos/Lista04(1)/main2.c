/* Bonus: programa que comeca construindo uma arvore
   normalmente, mas depois modifica os valores dos nos
   arbitrariamente para testar as funcoes de validacao. */



#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int gera() {
  return (rand() / (float) RAND_MAX) * 100 + 0.5;
}


void modifica(no *n) {
  if(n == NULL)
    return;

  modifica(n->esq);

  n->valor = gera();

  modifica(n->dir);
}


int main() {
  int n, i;

  printf("Digite um numero: ");
  scanf("%d", &n);

  arvore *a = arvore_aloca();

  srand(time(NULL));

  for(i = 0; i < n; i++)
    arvore_insere(a, gera());

  arvore_imprime(a);

  printf("V: %d %d %d\n", valida1(a->raiz), valida2(a->raiz), valida3(a->raiz));

  for(i = 0; i < n; i++) {
    modifica(a->raiz);

    arvore_imprime(a);

    printf("V: %d %d %d\n", valida1(a->raiz), valida2(a->raiz), valida3(a->raiz));
  }

  arvore_libera(a);

  return EXIT_SUCCESS;
}
