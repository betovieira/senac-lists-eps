'''
	Aluno: Humberto Vieira de Castro

	DESCRIÇÃO DO PROBLEMA
		- Lê uma sequencia de números inteiros e coloca em uma lista ligada até achar um 0
		- Depois separa essa lista em duas outras listas (pares e impares)

	ALGORITMO
		- Abro o arquivo
		- Separo cada numero da linha em pares e impares (Coloco em duas listas)
		- Até achar um 0
		- Procurar em todas as linhas até achar uma linha com  apenas um 0
		- Toda vez que terminar uma linha, colocar na strFinal dois \n
		- Imprimir a lista de pares e depois uma lista de impar

'''

def retiraQuebraDeLinha(palavra):
	novaPalavra = ''
	for letra in palavra:
		if(letra != '\n'):
			novaPalavra = novaPalavra + letra
	
	return novaPalavra

class Sequencia(object):
	def __init__(self, caminhoArquivo = input("Digite o caminho do arquivo"), listPar = list(), listImp = list(), strFinal = ''):
		self.caminhoArquivo = caminhoArquivo
		self.listPar = listPar
		self.listImp = listImp
		self.strFinal = strFinal

	def __str__(self):
		'''
		IMPRIME UMA STRING QUE VAI SER COLOCADA NO TERMINAL
		'''

	def separaListas(self):
		arquivo = open(self.caminhoArquivo, 'r')

		for linha in arquivo.readlines():
			
			if(linha == '0'):
				break

			numSeparados = retiraQuebraDeLinha(linha).split(' ')
			i = 0

			while(i < len(numSeparados)):
				numAtual = int(numSeparados[i])

				if(numAtual % 2 == 0):
					self.listPar.append(numAtual)
				else:
					self.listImp.append(numAtual)

				i = i + 1



		arquivo.close()

	def colocaOrdemExibicao(self):
		i = 0

		while(i < len(listPar)):
			self.strFinal = self.strFinal + self.listPar(i)
			i = i + 1

		i = 0
		
		self.strFinal = self.strFinal + '\n'

		while(i < len(listImp)):
			self.strFinal = self.strFinal + self.listPar(i)
			i = i + 1
		
		self.strFinal = self.strFinal + '\n\n'
		

c = Sequencia()
