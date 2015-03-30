#ifndef HASH_H
#define HASH_H


#include "lista.h"


typedef struct {
  int m;
  lista **l;
} hash;


hash *hash_aloca(int m);
void hash_libera(hash *);

void hash_insere(hash *, int);
void hash_retira(hash *, int);

void hash_imprime(hash *);


#endif
