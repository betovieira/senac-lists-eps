#include "busca.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
  int num, min, *vet, i, q;

  srand(time(NULL));

  printf("\n");
  do {
    printf("Digite a quantidade de inteiros: ");
    scanf("%d", &num);
  } while(num < 1);

  vet = malloc(num * sizeof(int));

  printf("Digite o primeiro inteiro: ");
  scanf("%d", &vet[0]);

  for(i = 1; i < num; i++)
    vet[i] = vet[i - 1] + ((float) rand() / RAND_MAX) * 5 + 0.5;

  printf("\n", num);
  for(i = 0; i < num; i++)
    printf("%d ", vet[i]);
  printf("\n\n");

  printf("Digite o inteiro desejado: ");
  scanf("%d", &q);

  printf("\nResposta da busca linear: %d", busca_linear(vet, num, q));
  printf("\nResposta da busca binaria iterativa: %d", busca_binaria_1(vet, num, q));
  printf("\nResposta da busca binaria recursiva: %d\n\n", busca_binaria_2(vet, num, q));

  free(vet);

  return 0;
}
