/* Se a retirada de uma pilha vazia nao encerrasse
   o programa, seria necessario mais cuidado com
   reinicializacao e possiveis vazamentos de memoria. */



#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>



int main() {
  char c;
  int a, b, num, pot;

  pilha *pd = pilha_aloca();
  pilha *pn = pilha_aloca();

  printf("Digite a expressao: ");

  while(1) {
    c = getchar();

    if(c == '\n')
      break;

    if(c >= 48 && c <= 57)
      pilha_insere(pd, c - 48);
    else {
      if(!pilha_vazia(pd)) {
        num = 0;

        pot = 1;

        while(!pilha_vazia(pd)) {
          num += pilha_retira(pd) * pot;

          pot *= 10;
        }

        pilha_insere(pn, num);
      }

      if(c == '+' || c == '-' || c == '*' || c == '/') {
        b = pilha_retira(pn);
        a = pilha_retira(pn);

        switch(c) {
        case '+':
          num = a + b;
          break;
        case '-':
          num = a - b;
          break;
        case '*':
          num = a * b;
          break;
        case '/':
          num = a / b;
          break;
        }

        pilha_insere(pn, num);
      }
    }
  }

  num = pilha_retira(pn);

  if(pilha_vazia(pn) && pilha_vazia(pd))
    printf("RESULTADO: %d\n", num);
  else
    printf("EXPRESSAO INCOMPLETA\n");

  pilha_libera(pn);
  pilha_libera(pd);

  return EXIT_SUCCESS;
}
