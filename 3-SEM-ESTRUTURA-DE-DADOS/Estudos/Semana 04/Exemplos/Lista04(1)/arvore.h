#ifndef ARVORE_H
#define ARVORE_H


typedef struct _no {
  int valor;
  struct _no *pai, *esq, *dir;
} no;

typedef struct {
  no *raiz;
} arvore;


arvore *arvore_aloca();
void arvore_libera(arvore *);

int menor(no *);
int maior(no *);

int valida1(no *);
int valida2(no *);
int valida3(no *);

no *minimo1(no *);
no *minimo2(no *);

no *sucessor(no *);

void arvore_insere(arvore *, int);
void arvore_retira(arvore *, int);

void arvore_imprime(arvore *);


#endif
