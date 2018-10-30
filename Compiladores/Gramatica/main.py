def main():
    token=[]
    parser = argparse.ArgumentParser(description='Compilador para um linguagem do tipo LL(1)')
    parser.add_argument("-lt", help="Show list tokens and lexems", action='store_true')
    parser.add_argument("-ls", help="Show sintatix List", action='store_true')
    parser.add_argument("codigo", type=str, help="Filename")
    parser.add_argument('-tudo', help='Show all', action='store_true')
    args=parser.parse_args()

    opction(args,token)


#executa a funcao main()
if __name__ == "__main__":
    import sys
    import argparse
    from selection import opction
    main()



