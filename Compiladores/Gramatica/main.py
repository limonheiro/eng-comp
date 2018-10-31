def main():

    parser = argparse.ArgumentParser(description='Compilador para uma linguagem do tipo LL(1)')
    parser.add_argument("-lt", help="Show list tokens and lexems", action='store_true')
    parser.add_argument("-ls", help="Show sintatix List", action='store_true')
    parser.add_argument("-lse", help="Show log semantic", action='store_true')
    parser.add_argument("filename", type=str, help="Filename")
    parser.add_argument('-tudo', help='Show all', action='store_true')
    args=parser.parse_args()

    opction(args)

#executa a funcao main()
if __name__ == "__main__":
    import sys
    import argparse
    from selection import opction
    main()