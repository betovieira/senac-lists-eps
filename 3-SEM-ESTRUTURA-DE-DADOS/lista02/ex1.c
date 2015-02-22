/*
	Programa que recebe dois números inteiros arbirtariamente grandes e imprime a soma desses inteiros.
	Para contornar limites, utilize listas ligadas para armazenar seus dígitos
	
	ALGORITMO	
	-> Fazer uma lista
	-> Pegar uma string do usuario
	-> Ler e colocar em uma lista ligada
	-> transformar o caractere em dígito
	-> empilhar o primeiro numero
	-> empilhar o segundo numero
	-> Empilhar a soma dos números
	-> Imprimir pilha
	-> Liberar a pilha

	CASES
	- Somo os dois digitos + o sobe e eles são menores que dez:
		- Eu coloco na pilha de resultado
		- Coloco zero como sobe
	- Se eu somo os dois + o sobe e eles são maiores que 9
		- Então eu tiro a diferença entre o número somado - 10
				e empilho ele na do resultado
		- E o resto eu coloco como valor no sobe
*/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*Declaração de Variáveis*/
	Pilha *p1;
	Pilha *p2;
	Pilha *r;
	int sobe;
	int somaDigito;
	int n1,n2;

	char num1[100];
	char num2[100];

	/*Dados do usuário*/
	fgets(num1, 1000, stdin);
	fgets(num2, 1000, stdin);

	/*Inicialização de variaveis*/
	p1 = aloca();
	p2 = aloca();
	r = aloca();
	sobe = 0;

	/*Empilha todos os números das duas strings*/
	for(int i = 0; i < strlen(num1) - 1; i++)
		empilha(p1, num1[i] - 48);
	
	for(int i = 0; i < strlen(num2) - 1; i++)
		empilha(p2, num2[i] - 48);

	/*Enquanto nenhuma das listas estiver vazia 
		irá somar cada casa dos números*/
	while(!vazia(p1) && !vazia(p2))
	{
		n1 = desempilha(p1);
		n2 = desempilha(p2);
		somaDigito = n1 + n2 + sobe;

		/*Se a casa do número for maior que 9 então
			sobe para a proxima casa */
		if(somaDigito <= 9){
			empilha(r, somaDigito);
			sobe = 0;
		}else{
			empilha(r, somaDigito - 10);
			sobe = somaDigito/10;
		}

	}	

	/*Caso o número 1 seja maior que o número 2*/
	while(!vazia(p1))
	{
		n1 = desempilha(p1);
		somaDigito = n1+sobe;

		if(somaDigito <= 9){
			empilha(r, somaDigito);
			sobe = 0;
		}else{
			empilha(r, somaDigito - 10);
			sobe = somaDigito / 10;
		}
	}

	/*Caso o número 2 seja maior que o número 1*/
	while(!vazia(p2))
	{
		n2 = desempilha(p2);
		somaDigito = n2+sobe;

		if(somaDigito <= 9){
			empilha(r, somaDigito);
			sobe = 0;
		}else{
			empilha(r, somaDigito - 10);
			sobe = somaDigito / 10;
		}
	}

	/*Se existir algum número ainda que está no sobe*/
	if(sobe != 0)
		empilha(r, sobe);
	
	printf("Resultado: ");
	imprime(r);

	libera(p1);
	libera(p2);
	libera(r);
	
	return 0;
}