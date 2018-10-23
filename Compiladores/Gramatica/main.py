def main():
    #python3 -lt filename.isa
    token = []
    parser = argparse.ArgumentParser(description="Um Compilador para uma linguagem do tipo LL(1)")
    parser.add_argument("-lt", help="Lista de tokens", action="store", dest="lexico", required=True)
    args = parser.parse_args()
    if args.lexico:
            file=open(args.lexico,"r")
            arquivo=file.read()
            print('{:15}'.format('Token'), '{:29}'.format('Lexema'), '{:10}'.format('Linha'),
                  '{:10}'.format('Coluna'))
            i = 0
            for tok in lexical.tokenize(arquivo):
                token.append(tok)
                print('{:15}'.format(token[i][0]), '{:20.11}'.format(token[i][1]), '{:10}'.format(token[i][2]), '{:10}'.format(token[i][3]))
                i += 1
    else:
        file = open(args.lexico, "r")
        arquivo = file.read()
        token=[]
        for tok in lexical.tokenize(arquivo):
            token.append(tok)
#executa a funcao main()'
if __name__ == "__main__":
    import lexical
    import argparse
    main()
