from colorama import Fore, Back, Style
def analisadorsintatico(dict1, dict2, programa, args):
    pilha = ["<INICIO>"]
    i=0
    while(i <= (len(programa)-1)):
        if pilha[-1] == programa[i][0]:
            pilha.pop()
            i += 1
        else:
            if((pilha[-1],programa[i][0]) in dict1):
                if(dict2[dict1[pilha[-1],programa[i][0]][0]] != []):
                    if(args):
                        print(dict1[pilha[-1],programa[i][0]][0],dict2[dict1[pilha[-1],programa[i][0]][0]])
                exp=dict2[dict1[pilha[-1], programa[i][0]][0]]
                if(exp == []):
                    pilha.pop()
                else:
                    pilha.pop()
                    exp.reverse()
                    pilha.extend(exp)
                    exp.reverse()
            else:
                t = Fore.BLACK + Back.CYAN +"Erro Sintatico "
                print(t)
                print(programa[i])
                print(Style.RESET_ALL)
                args=False
                break
    if(args):
        print("Sintatico terminado com Sucesso")