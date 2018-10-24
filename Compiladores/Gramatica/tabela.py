def tabela_criar():
    from builtins import type
    dict={}
    with open('roberto.txt', 'r') as file:
        head = file.readline().rstrip().split(',')
        for row in file:
            cont = 0
            for colunm in row.split(','):
                if colunm.isdigit():
                    key1=''.join(row.split(',')[0])
                    key2=''.join(head[cont])
                    dict[(key1,key2)]=[colunm]
                cont +=1