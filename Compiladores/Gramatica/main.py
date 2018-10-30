def main(token):
    #parser = argparse.ArgumentParser(description='Compilador para um linguagem do tipo LL(1)')
    #parser.add_argument("-lt", help="Exibe a listagem de tokens e suas posição", action='store', default=False)
    #parser.add_argument("codigo", type=str, help="Codigo fonte", action='store', default=False)
    #args=parser.parse_args()
    #python3 -lt filename.isa
    if len(sys.argv)>=3:
        file = open(sys.argv[2],"r")
        arquivo = file.read()
        file.close()
        print('{:15}'.format('Token'), '{:29}'.format('Lexema'), '{:10}'.format('Linha'),'{:10}'.format('Coluna'))
        i = 0
        for tok in lexical.tokenize(arquivo):
                token.append(tok)
                print('{:15}'.format(token[i][0]), '{:20.11}'.format(token[i][1]), '{:10}'.format(token[i][2]), '{:10}'.format(token[i][3]))
                i += 1

    else:
        file = open(sys.argv[1],"r")
        arquivo = file.read()
        file.close()
        for tok in lexical.tokenize(arquivo):
            token.append(tok)
    return token

#executa a funcao main()
if __name__ == "__main__":
    import sys
    import lexical
    token=[]
    from beuty import initsintatico
    main(token)
    #print(len(token))
    initsintatico(token)


