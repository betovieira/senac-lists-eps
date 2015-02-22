/* Implementação de PILHA com lista ligada */
#include <stdio.h> 
#include <stdlib.h> 

/* Estruturas */
typedef struct _elemento {
	int valor;
	struct _elemento *prox;
} Elemento;

typedef struct {
	Elemento *topo;
} Pilha;

/* Protótipos */
Pilha* aloca();
void empilha(Pilha*, int);
int vazia(Pilha*);
int desempilha(Pilha *);
void imprime(Pilha *);
void libera(Pilha *);

/* Aloca a estrutura pilha */
Pilha* aloca()
{
	Pilha *p;
	p = malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

/* Empilha */
void empilha(Pilha *p, int valor)
{
	Elemento *d;
	
	d = malloc(sizeof(Elemento));
	d->valor = valor;

	d->prox = p->topo;
	p->topo = d;
}

/* Verifica se a pilha está vazia */
int vazia(Pilha *p)
{
	return p->topo == NULL;
}

/* Desempilha */
int desempilha(Pilha *p){
	Elemento *aux;
	int valor;

	if(vazia(p)){
		fprintf(stderr, "%s\n", "Erro ao desempilhar!");
		exit(EXIT_FAILURE);
	}

	aux = p->topo;
	valor = aux->valor;

	p->topo = aux->prox;
	free(aux);

	return valor;
}

/* Imprime o conteúdo da pilha */
void imprime(Pilha *p)
{
	Elemento *i;
	
	for(i = p->topo; i != NULL; i= i->prox)
		printf("%d", i->valor);
	printf("\n");
}

/* Retorna o tamanho da pilha */
int tamanho(Pilha *p)
{
	Elemento *i;
	int n;

	n = 0;
	for(i = p->topo; i != NULL; i= i->prox)
		n++;

	return n;
}

/* Libera os elementos e a estrutura da pilha da memória */
void libera(Pilha *p)
{
	Elemento *i;
	for(i = p->topo; i != NULL; i= i->prox)
		free(i);
	free(p);
}

