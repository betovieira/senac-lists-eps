#ifndef PILHA_H
#define PILHA_H


typedef struct _elemento {
  int valor;
  struct _elemento *proximo;
} elemento;

typedef struct {
  elemento *comeco;
} pilha;


pilha *pilha_aloca();
void pilha_libera(pilha *);

int pilha_vazia(pilha *);
void pilha_insere(pilha *, int);
int pilha_retira(pilha *);


#endif
