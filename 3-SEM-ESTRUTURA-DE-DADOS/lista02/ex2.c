/*	DESCRIÇÃO
	-> Recebe um expressão pós-fixa 129+19**
	-> Verifica se ela é válida
	-> Todos são inteiros não negativos
	-> Todo caractere que não for digito ou uma das quatro operações é um espaço para outro número
	-> Quebra linha representa término
	-> 2 listas: Uma pra armazenar digitos de um mesmo número e outra para calcular o resultado das operações
	-> Dois números são separados por espaço, qualquer um que não seja os operadores ou números são
	
	ALGORITMO
	-> Pega a expressão do usuário
	-> Varre o string
		-> NUMERO: Se tiver número ele empilha (na Pilha NUMERO) até achar um espaço
			-> Desempilha até multiplicando por multiplos de dez
			-> Depois empilha na outra pilha, que grava os números (na Pilha Expressão)
		-> EXPRESSAO: Se encontrar um sinal + - * / Ele desempilha os dois ultimos números
			-> E faz o calculo segundo o sinal que é achado. 
		-> INVALIDA: Caso haja algo em qualquer uma das pilhas "Expressão Inválida"
	
	FORMATO DA STRING "NUM NUM NUM NUM OPERADOR OPERADOR OPERADOR" ENTRE OS OPERADORES NÃO PODE HAVER ESPAÇO
*/
	
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "lista.h"

int main()
{
	/* Declara as variáveis */
	char *expr;
	Pilha *pNum;
	Pilha *pExpr;
	int multDez;
	int numero;
	int r;

	/* Inicializa as variáveis */
	expr = malloc(sizeof(char) * 100);
	pExpr = aloca();
	pNum = aloca();
	r = 0;

	/* Pega a expressão do usuário */
	fgets(expr, 100, stdin);

	/* Percorre a string expressão do usuário */
	for(int i = 0; expr[i] != '\n'; i++)
	{
		/* Verifica se é um numero de 0 a 9 */
		if(expr[i] >= '0' && expr[i] <= '9')
		{
			empilha(pNum, expr[i] - '0');
		}
		/* Verifica se é algum dos sinais */
		else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			/* Verifica se o tamanho da string é maior que 2 */
			if(tamanho(pExpr) < 2){
				printf("Formação da inválida: Excesso de operadores\n");
				return EXIT_FAILURE;
			}

			/* Coloca os valores de desempilhados da expressão */
			int num1 = desempilha(pExpr);
			int num2 = desempilha(pExpr);

			/* Verifica qual operação deve ser feita */
			if(expr[i] == '+')
				empilha(pExpr, num1 + num2);
			else if(expr[i] == '-')
				empilha(pExpr, num1 - num2);
			else if(expr[i] == '*')
				empilha(pExpr, num1 * num2);
			else if(expr[i] == '/')
				empilha(pExpr, num1 / num2);
		}
		/* Caso seja um separador */
		else
		{
			numero = 0;
			multDez = 1;
			
			/* Será formado o número que será colocado na expressão */
			while(!vazia(pNum)){
				numero += multDez * desempilha(pNum);
				multDez *= 10;
			}	
			
			/* Empilha o número feito */
			empilha(pExpr, numero);
		}
	}
	
	/* Desempilha o número final */
	r = desempilha(pExpr);

	/* Caso ainda haja números na expressão, é um erro */
	if(!vazia(pExpr))
		printf("Formação da inválida: Excesso de números\n");
	else
		printf("Resultado: %d\n", r);
	
	/* Libera as pilhas alocadas*/
	libera(pNum);
	libera(pExpr);

	return 0;
}