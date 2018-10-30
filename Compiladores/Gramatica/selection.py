def opction(args,token):
    if args.tudo:
        vlt(args.codigo, token)
        ls(token,True)
    elif(args.ls):
        import lexical
        lt(args.codigo, token)
        ls(token,args.ls)
    elif(args.lt):
        vlt(args.codigo,token)
        ls(token, args.ls)
    else:
        lt(args.codigo, token)
        ls(token,args.ls)

def vlt(filename,token):
    import lexical
    file = open(filename, "r")
    arquivo = file.read()
    file.close()
    print('{:15}'.format('Token'), '{:29}'.format('Lexema'), '{:10}'.format('Linha'), '{:10}'.format('Coluna'))
    i = 0
    for tok in lexical.tokenize(arquivo):
        token.append(tok)
        print('{:15}'.format(token[i][0]), '{:20.11}'.format(token[i][1]), '{:10}'.format(token[i][2]),
              '{:10}'.format(token[i][3]))
        i += 1
def lt(filename, token):
    import lexical
    file = open(filename, "r")
    arquivo = file.read()
    file.close()
    for tok in lexical.tokenize(arquivo):
        token.append(tok)
def ls(token,args):
    from beuty import initsintatico
    initsintatico(token,args)