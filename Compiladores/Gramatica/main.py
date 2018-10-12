import lexical
import sys

def main():
    #python3 -lt filename.isa
    if sys.argv[2] != '':
        argumento = sys.argv[1]
        arquivo = sys.argv[2]
        file = open(arquivo,"r")
        statements = file.read()
        if argumento == '-lt':
            for token in lexical.tokenize(statements):
                print(token)
    else:
        arquivo = sys.argv[1]
        file = open(arquivo,"r")
        statements = file.read()
        lexical.tokenize(statements)
#executa a função main()
if __name__=="__main__":
    main()
