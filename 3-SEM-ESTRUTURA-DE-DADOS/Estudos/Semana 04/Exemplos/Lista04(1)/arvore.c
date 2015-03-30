#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


arvore *arvore_aloca() {
  arvore *a = malloc(sizeof(arvore *));

  a->raiz = NULL;

  return a;
}


void no_libera(no *n) {
  if(n == NULL)
    return;

  no_libera(n->esq);
  no_libera(n->dir);

  free(n);
}

void arvore_libera(arvore *a) {
  no_libera(a->raiz);

  free(a);
}


/* Exercicio 01 */

int menor(no *n) {
  int valor, temp;

  valor = n->valor;

  if(n->esq != NULL) {
    temp = menor(n->esq);

    if(valor > temp)
      valor = temp;
  }

  if(n->dir != NULL) {
    temp = menor(n->dir);

    if(valor > temp)
      valor = temp;
  }

  return valor;
}


/* Exercicio 02 */

int maior(no *n) {
  int valor, temp;

  valor = n->valor;

  if(n->esq != NULL) {
    temp = maior(n->esq);

    if(valor < temp)
      valor = temp;
  }

  if(n->dir != NULL) {
    temp = maior(n->dir);

    if(valor < temp)
      valor = temp;
  }

  return valor;
}


/* Exercicio 03 */

int valida1(no *n) {
  if(n == NULL)
    return 1;

  if(n->esq != NULL && (maior(n->esq) > n->valor || !valida1(n->esq)))
    return 0;

  if(n->dir != NULL && (menor(n->dir) < n->valor || !valida1(n->dir)))
    return 0;

  return 1;
}


/* Exercicio 04 Versao 1: utiliza apontadores para devolver
   o menor, o maior e o resultado da validacao de uma vez. */

void valida2_aux(no *n, int *pmenor, int *pmaior, int *pvalida) {
  int men, mai, val;

  if(n == NULL) {
    *pvalida = 1;

    /* Em uma arvore vazia, o menor e
       o maior nao estao definidos. */

    return;
  }

  *pmenor = n->valor;
  *pmaior = n->valor;

  if(n->esq != NULL) {
    valida2_aux(n->esq, &men, &mai, &val);

    if(mai > n->valor || !val) {
      *pvalida = 0;

      /* Em uma arvore invalida, nao
         importa o menor e o maior. */

      return;
    }

    *pmenor = men;
  }

  if(n->dir != NULL) {
    valida2_aux(n->dir, &men, &mai, &val);

    if(men < n->valor || !val) {
      *pvalida = 0;

      /* Em uma arvore invalida, nao
         importa o menor e o maior. */

      return;
    }

    *pmaior = mai;
  }

  *pvalida = 1;
}

int valida2(no *n) {
  int men, mai, val;

  valida2_aux(n, &men, &mai, &val);

  return val;
}


/* Exercicio 04 Versao 2: verifica recursivamente se
   os valores de uma arvore estao em um intervalo. */

int valida3_aux(no *n, int men, int mai) {
  if(n == NULL)
    return 1;

  if(!valida3_aux(n->esq, men, n->valor))
    return 0;

  if(n->valor < men || n->valor > mai)
    return 0;

  if(!valida3_aux(n->dir, n->valor, mai))
    return 0;

  return 1;
}

int valida3(no *n) {
  return valida3_aux(n, -INT_MAX, INT_MAX);
}


/* Exercicio 05 */

no *minimo1(no *n) {
  if(n->esq == NULL)
    return n;

  return minimo1(n->esq);
}


/* Exercicio 06 */

no *minimo2(no *n) {
  while(n->esq != NULL)
    n = n->esq;

  return n;
}


/* Exercicio 07 */

no *sucessor(no *n) {
  if(n->dir != NULL)
    return minimo2(n->dir);

  while(n->pai != NULL && n->pai->dir == n)
    n = n->pai;

  return n->pai;
}


/* Exercicio 08 */

void arvore_insere(arvore *a, int valor) {
  no *pai, *n;

  pai = NULL;

  n = a->raiz;

  while(n != NULL) {
    pai = n;

    if(valor < n->valor)
      n = n->esq;
    else
      n = n->dir;
  }

  n = malloc(sizeof(no));
  n->valor = valor;
  n->pai = pai;
  n->esq = NULL;
  n->dir = NULL;

  if(pai == NULL)
    a->raiz = n;
  else
    if(n->valor < pai->valor)
      pai->esq = n;
    else
      pai->dir = n;
}


/* Exercicio 09 */

void arvore_retira(arvore *a, int valor) {
  no *n, *filho;

  n = a->raiz;

  while(n != NULL && n->valor != valor)
    if(valor < n->valor)
      n = n->esq;
    else
      n = n->dir;

  if(n == NULL)
    return;

  if(n->esq != NULL && n->dir != NULL) {
    no *suc = minimo2(n->dir);

    n->valor = suc->valor;

    n = suc;
  }

  if(n->esq != NULL)
    filho = n->esq;
  else
    filho = n->dir;

  if(n->pai == NULL)
    a->raiz = filho;
  else
    if(n->pai->esq == n)
      n->pai->esq = filho;
    else
      n->pai->dir = filho;

  if(filho != NULL)
    filho->pai = n->pai;

  free(n);
}


void no_imprime(no *no) {
  if(no == NULL)
    return;

  no_imprime(no->esq);

  printf(" %d", no->valor);

  no_imprime(no->dir);
}

void arvore_imprime(arvore *a) {
  printf("A:");

  no_imprime(a->raiz);

  printf("\n");
}
