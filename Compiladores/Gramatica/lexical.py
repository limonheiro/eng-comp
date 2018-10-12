import collections
import re
import sys

Token = collections.namedtuple('Token', ['tipo', 'lexema', 'linha', 'coluna'])

def tokenize(code):
    token_especificacao = [
		('inicio'       ,r'\{'), #inicio {
		('fim'          ,r'\}'), # fim }
		('a_parentese'  ,r'\('), #parentese de abertura
		('f_parentese'  ,r'\)'), #parentese de fechamento
		('leia'         ,r'leia'), #leia
		('escreva'      ,r'escreva'), #escreva
		('se'           ,r'se'), #se
		('senao'        ,r'senao'), #senao
		('enquanto'     ,r'enquanto'), #enquanto
		('programa'     ,r'programa'), #programa
		('fimprograma'  ,r'fimprograma'), #fimprograma
		('inteiro'      ,r'inteiro'),     #variavel
                ('numero'       ,r'[+-]?[0-9]+'),  # inteiro
		("fim_linha"    ,r';'), #fim de linha
		("virgula"      ,r','), # virgula
                ('recebe'       ,r'='),           # recebe
                ('id'           ,r'[A-Za-z]([A-Za-z0-9_])*'),    # Id
                ('subtração'    ,r'\-'),            #subtração
                ('soma'         ,r'\\+'),           #soma
                ('multiplicação',r'\*'),            #multiplicação
                ('divisão'      ,r'/'),             #divisão
                ('WS'           ,r' +'),           # espaço 
		('menor'        ,r'<'),             #operadore lógico menor
		('maior'        ,r'>'),             #operador lógico maior
		('frase'        ,r'".*?"'),         #frase
                ('ERRO'         ,r'.'),            # qualquer caracter não identificado
		('Linha'        ,r'\n'),	    #fim de linha   	
    ]
    ####
    token_regex = '|'.join('(?P<%s>%s)' % pair for pair in token_especificacao)
    print(token_regex)
    linha = 1
    linha_inicia = 0
    for mo in re.finditer(token_regex, code):
        kind = mo.lastgroup
        value = mo.group(kind)
        if (kind == 'Linha'):
            linha_inicia = mo.end()
            linha += 1
        elif kind == 'tab':
            pass
        elif kind == 'ERRO':
            print(f'########################################################')
            print(f'{value!r} não esperado na linha {linha_inicia} e coluna {coluna}')
            print(f'########################################################')
            if value == '"':
                print(f'" de fechamento não encontrada')
            else:
                print(f'caracter desconhecido')
            pass
        coluna = mo.start() - linha_inicia
        if (kind != 'ERRO') and (kind != 'Linha') and (kind != 'WS'):
            yield Token(kind, value, linha, coluna)
def main():
    #python3 -lt filename.isa
    if sys.argv[2] != '':
        argumento = sys.argv[1]
        arquivo = sys.argv[2]
        file = open(arquivo,"r")
        statements = file.read()
        if argumento == '-lt':
            for token in tokenize(statements):
                print(token)
    else:
        arquivo = sys.argv[1]
        file = open(arquivo,"r")
        statements = file.read()
        tokenize(statements)
#executa a função main()
main()