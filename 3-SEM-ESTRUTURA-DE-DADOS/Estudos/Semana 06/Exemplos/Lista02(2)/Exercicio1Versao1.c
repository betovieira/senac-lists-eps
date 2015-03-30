/* Se a retirada de uma pilha vazia nao encerrasse
   o programa, seria necessario mais cuidado com
   reinicializacao e possiveis vazamentos de memoria. */



#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>



pilha *le_numero() {
  char c;

  pilha *p = pilha_aloca();

  while(1) {
    c = getchar();

    if(c == '\n')
      break;

    if(c < 48 || c > 57) {
      fprintf(stderr, "ERRO: digitou inteiro nao-negativo invalido\n");
      exit(EXIT_FAILURE);
    }

    pilha_insere(p, c - 48);
  }

  if(pilha_vazia(p)) {
    fprintf(stderr, "ERRO: nao digitou inteiro nao-negativo\n");
    exit(EXIT_FAILURE);
  }

  return p;
}


int main() {
  int da, db, ds, vai;
  pilha *a, *b, *s;

  printf("Digite o primeiro inteiro nao-negativo: ");
  a = le_numero();

  printf("Digite o segundo inteiro nao-negativo: ");
  b = le_numero();

  vai = 0;

  s = pilha_aloca();

  while(!pilha_vazia(a) || !pilha_vazia(b) || vai) {
    if(pilha_vazia(a))
      da = 0;
    else
      da = pilha_retira(a);

    if(pilha_vazia(b))
      db = 0;
    else
      db = pilha_retira(b);

    ds = vai + da + db;

    vai = ds / 10;

    pilha_insere(s, ds % 10);
  }

  printf("SOMA: ");
  while(!pilha_vazia(s))
    printf("%d", pilha_retira(s));
  printf("\n");

  pilha_libera(s);
  pilha_libera(b);
  pilha_libera(a);

  return EXIT_SUCCESS;
}
