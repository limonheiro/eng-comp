import lexical
import sys

def main():
    #python3 -lt filename.isa
    if len(sys.argv) >=3:
        argumento = sys.argv[1]
        arquivo = sys.argv[2]
        file = open(arquivo,"r")
        statements = file.read()
        token=[]
        if argumento == '-lt':
            print('{:15}'.format('Token'), '{:29}'.format('Lexema'), '{:10}'.format('Linha'),
                  '{:10}'.format('Coluna'))
            i = 0
            for tok in lexical.tokenize(statements):
                token.append(tok)
                print('{:15}'.format(token[i][0]), '{:20.10}'.format(token[i][1]), '{:10}'.format(token[i][2]), '{:10}'.format(token[i][3]))
                i += 1

        else:
            lexical.__help__()
    else:
        arquivo = sys.argv[1]
        file = open(arquivo,"r")
        statements = file.read()
        token=[]
        for tok in lexical.tokenize(statements):
            token.append(tok)
#executa a funcao main()
if __name__ =="__main__":
    main()
