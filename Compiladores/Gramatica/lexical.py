import collections
import re

Token = collections.namedtuple('Token', ['typ', 'value', 'linha', 'coluna'])

def tokenize(code):
    token_specification = [
		('inicio',r'\{'),
		('fim',r'\}'),
		('a_parentese',r'\('),
		('f_parentese',r'\)'),
		('leia',r'leia'),
		('escreva',r'escreva'),
		('se',r'se'),
		('senao',r'senao'),
		('enquanto',r'enquanto'),
		('programa',r'programa'),
		('fimprograma',r'fimprograma'),
		('inteiro',r'inteiro'),
        ('numero',  r'[+-]?[0-9]+'),  # Integer or decimal number
		("fim_linha", r';'),
		("virgula", r','),
        ('recebe',  r'='),           # Assignment operator
        ('id',r'[A-Za-z]([A-Za-z0-9_])*'),    # Identifiers
        ('OP',r'[+\-*/]'),      # Arithmetic operators
        ('WS', r'(\s)+'),           # Line endings
		('menor', r'<'),
		('maior', r'>'),
		('soma', r'\+'),
		('subtração', r'-'),
		('multiplicação',r'\*'),
		('divisão',r'/'),
		('frase',r'".*?"'),
        ('MISMATCH',r'.'),            # Any other character
		('NEWLINE', r'\n'),			
		('SKIP',r'[ \t]+'),       # Skip over spaces and tabs
    ]
    tok_regex = '|'.join('(?P<%s>%s)' % pair for pair in token_specification)
    line_num = 1
    line_start = 0
    for mo in re.finditer(tok_regex, code):
        kind = mo.lastgroup
        value = mo.group(kind)
        if (kind == 'NEWLINE'):
            line_start = mo.end()
            line_num += 1
        elif kind == 'SKIP':
            pass
        elif kind == 'MISMATCH':
            raise RuntimeError(f'{value!r} unexpected on line {line_num}')
        column = mo.start() - line_start
        yield Token(kind, value, line_num, column)

statements = '''
programa
inteiro var1, var2;
escreva("@Digite um valor: ")
leia(var1);
var2=1;
enquanto(var1 > 1){
 var2 = var1 * var2 ;
 var1 = var1 - 1;
}
escreva(var2);
fimprograma
'''
try:
	for token in tokenize(statements):
		print(token)
		
except LexerError as err:
	print('erro ')