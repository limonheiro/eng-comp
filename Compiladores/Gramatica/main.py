def main():
    parser = argparse.ArgumentParser(description='Compilador para um linguagem do tipo LL(1)')
    parser.add_argument("-lt", help="Exibe a listagem de tokens e lexemas segundo a sua posição",dest="lexico")
    parser.add_argument("codigo", type=str, help="Codigo fonte")
    args=parser.parse_args()
    #python3 -lt filename.isa
    if args.lexico:
        file = open(args.lexico,"r")
        arquivo = file.read()
        file.close()
        token=[]
        print('{:15}'.format('Token'), '{:29}'.format('Lexema'), '{:10}'.format('Linha'),'{:10}'.format('Coluna'))
        i = 0
        for tok in lexical.tokenize(arquivo):
                token.append(tok)
                print('{:15}'.format(token[i][0]), '{:20.11}'.format(token[i][1]), '{:10}'.format(token[i][2]), '{:10}'.format(token[i][3]))
                i += 1

    else:
        file = open(args.codigo,"r")
        arquivo = file.read()
        file.close()
        token=[]
        for tok in lexical.tokenize(arquivo):
            token.append(tok)
#executa a funcao main()


if __name__ == "__main__":
    import argparse
    import lexical
    from beuty import init_sintatico
    main()
    init_sintatico()
