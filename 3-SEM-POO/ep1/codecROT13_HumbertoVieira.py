'''
	ALUNO: Humberto Vieira de Castro
	Programação Orientada a Objetos
	3º Semestre

	PROJETO: Codificador e decodificador utilizando código ROT13
'''
import random
'''
	PREPARASTRING:
		- O intuito dessa função é retirar os espaços a mais que estejam na string
'''
def preparaString(string):
	novaString = ''
	ant = ''

	for carac in string:
		if(carac == ' '):
			if(ant != ' '):
				novaString = novaString + carac
				ant = ' '
		else:
			novaString = novaString + carac
			ant = carac

	return novaString

'''
	NUMLINHASARQUIVO:
		- Serve para contar quantas linhas tem no arquivo de texto
'''
def numLinhasArquivo(caminho):
	i = 0
	arq_texto = open(caminho,'r')

	for linha in arq_texto.readlines():
		i = i + 1

	arq_texto.close()
	return i

'''
	ROT13: 
		- Função que rotaciona a palavra
'''
def rot13(palavra, rot):
	#Inicializa variáveis
	novaPalavra = ''	

	#Percorre cada letra da palavra
	for letra in palavra:
		#Conta o quanto vai ter que rotacionar
		nLetra = ord(letra) + (rot) + 13

		#Se não for uma linha vazia
		if (letra != '\n'):
			#Verifica se esta entre os maiúsculos 
			if(ord(letra) >= ord('A') and ord(letra) <= ord('Z')):
				#Procura o valor da rotacao ate ficar no intervalo maiusculos
				while(nLetra < ord('A') or nLetra > ord('Z')):
					if(nLetra > ord('Z')):
						nLetra = (nLetra % ord('Z')) + ord('A') - 1
					elif(nLetra < ord('A')):
						nLetra = ord('Z') - (ord('A') % nLetra) + 1
			#Verifica se esta entre os minúsculos
			elif(ord(letra) >= ord('a') and ord(letra) <= ord('z')):
				#Procura o valor da rotação ate ficar no intervalo de minusculos
				while(nLetra < ord('a') or nLetra > ord('z')):
					if(nLetra > ord('z')):
						nLetra = ((nLetra % ord('z')) + ord('a') - 1)
					elif(nLetra < ord('a')):
						nLetra = ord('z') - (ord('a') % nLetra) + 1

			#Coloca cada letra na novaPalavra
			novaPalavra = novaPalavra + chr(nLetra)

	return novaPalavra	


'''
	DESCRIÇÃO - CODIFICADOR
		- Ler um arquivo contendo linhas de textos separados por linhas em branco
		- Por cada palavra contida deve gerar números aleatórios com rotações de [-20..20]
		- Saída do codificador deve ser um texto rotacionado, seguido de uma linha em branco
		- As sentenças de entrada e saída devem sem separadas por duas linhas em branco
'''
def codifica(caminhoEntrada, caminhoSaida, qtdLinhasArquivo):
	#Inicializa variáveis
	arq_texto = open(caminhoEntrada,'r')
	i = 0
	strfinal = ''
	contaLinhas = 0

	#Percorre linha por linha de um arquivo
	for linha in arq_texto.readlines():
		#Se não for uma linha vazia
		if(linha != '\n'):	
			#Retira os espaços a mais da string
			linha = preparaString(linha)

			#Separa cada palavra separada por espaço
			palavra = linha.split(' ')
			
			palavraCodificada = list(range(len(palavra)))
			listRandomicos = list(range(len(palavra)))

			i = 0
			#Codifica a palavra através de um número randomico
			while(i < len(palavra)):
				rot = random.randint(-20, 20)
				palavraCodificada[i] = rot13(palavra[i], rot)
				listRandomicos[i] = rot
				i = i + 1
			
			i = 0
			#Coloca tudo o que esta dentro da palavra codificada 
			#na string de retorno
			for item in palavraCodificada:
				#Esse if serve para não adicionar espaço no final de cada linha
				if(i != len(palavra) - 1):
					strfinal = strfinal + str(item) + ' '
				else:
					strfinal = strfinal + str(item) + '\n'
				i = i + 1

			i = 0
			strfinal = strfinal + '\n'
			#Coloca os números randomicos na string de retorno
			for item in listRandomicos:
				if(i != len(listRandomicos) - 1):
					strfinal = strfinal + str(item) + ' '
				else:
					strfinal = strfinal + str(item) +'\n'
				i = i + 1

			contaLinhas = contaLinhas + 1

			#Se for a ultima linha, não coloca duas linhas vazias de separação
			if(contaLinhas < qtdLinhasArquivo/2):
				strfinal = strfinal + "\n\n"		


	#Imprime no arquivo
	arq_texto = open(caminhoSaida,'w')
	arq_texto.writelines(strfinal)

	arq_texto.close()

'''
	DESCRIÇÃO - RETIRAQUEBRADELINHA
	- Função retira os quebra linha da ultima palavra da linha
		para não dar erro no processo de decodificação
'''
def retiraQuebraDeLinha(palavra):
	novaPalavra = ''
	for letra in palavra:
		if(letra != '\n'):
			novaPalavra = novaPalavra + letra
	
	return novaPalavra


'''
	DESCRIÇÃO - DECODIFICADOR
		- Ler um arquivo de texto e separar as palavras das linhas
		- Ler os números relacionados aquelas palavras
		- Fazer a rotação inversa a dos números utilizando cada palavra
		- Colocar na strfinal
		- Ler a proxima linha 
'''
def decodifica(caminhoEntrada, caminhoSaida):
	#Inicializa variáveis
	arq_texto = open(caminhoEntrada, 'r')
	lPalavraCodificada = []
	lNumRandomico = []
	strFinal = '' 
	i = 0
	j = 0
	controle = 1

	#Lê cada linha do arquivo
	linhas = arq_texto.readlines()
	for i in range(len(linhas) + 1):
		#Primeira lInha == Palavra codificada
		if(controle == 1): 
			lPalavraCodificada = preparaString(linhas[i]).split(' ')
		#Terceira linha == Numeros das rotações 
		elif(controle == 3):
			lNumRandomico = linhas[i].split(' ')
			#tamanho de itens das listas
			nPalavra = len(lPalavraCodificada)

			j = 0
			#Decodifica palavra por palavra
			while(j < nPalavra):
				strFinal = strFinal + rot13(lPalavraCodificada[j], (-1) * int(retiraQuebraDeLinha(lNumRandomico[j]))) + " " 
				j = j + 1

			#Coloca a variavel de controle para -2 pois precisa começar a contar a partir das linhas com '\n'
			controle = -2
			strFinal = strFinal + "\n\n"

		controle = controle + 1
		i = i + 1

	arq_texto = open(caminhoSaida,'w')
	arq_texto.writelines(strFinal)

	arq_texto.close()			

#Função Principal
def main():
	opcao = input("1 - Codificar\n2 - Decodificar:\n")

	if(opcao == '1' or opcao == '2'):
		try:
			nomeArquivoEntrada = input("Digite o nome do arquivo de entrada:\n")
			nomeArquivoSaida = input("Digite o nome do arquivo de saida:\n")

			qtdLinhasArquivo = numLinhasArquivo(nomeArquivoEntrada)

			if(opcao == '1'):
				codifica(nomeArquivoEntrada, nomeArquivoSaida, qtdLinhasArquivo)
			elif(opcao == '2'):
				decodifica(nomeArquivoEntrada, nomeArquivoSaida)
			
		except IOError as e:
			print("Arquivo não existente\n")
	else:
		print("Opção Inválida")

#Chama a função principal
main()