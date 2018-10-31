def semantic(token):
    variaveis(token)
    divisao(token)
    recebe(token)
def recebe(token):
    for i in range(len(token)):
        if 'recebe' in token[i] and 'frase' in token[i+1]:
            Erro()
            print(f'Divisão por zero: '+reset(token[i+1]))
def divisao(token):
    for i in range(len(token)):
        if 'divisao' in token[i] and '0' in token[i+1]:
            Erro()
            print(f'Divisão por zero: '+reset(token[i+1]))


def variaveis(token):
    if(token[0][0]=='programa'):
        variaveis=[]
        for var in token:
            if 'id'in var and var[2]==2:
                if var[1] not in variaveis:
                    variaveis.append(var[1])
                else:
                    Erro()
                    print(f'{var[1]} declaração duplicada: '+reset(var))
        for code in token:
            if 'id' in code:
                if not(code[1] in variaveis):
                    Erro();
                    print(f'{code[1]} não declarado: '+reset(code))
def Erro():
    from colorama import Fore, Back
    print(Fore.BLACK + Back.CYAN + 'Erro semantico:')
def reset(linha):
    from colorama import Style
    return f'linha{linha[2]} : coluna{linha[3]}' + Style.RESET_ALL