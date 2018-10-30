from bs4 import BeautifulSoup
from sintatico import analisadorsintatico


def beut(tabela1, tabela2):
    with open('tabela.html', 'r') as file:
        soup = BeautifulSoup(file, "html5lib")
        soup.prettify()

        tabela_all = soup.find_all('tbody')

        coluna1 = tabela_all[0].find_all('tr')
        coluna2 = tabela_all[1].find_all('tr')

        valores_return(coluna1, tabela1)
        valores_return(coluna2, tabela2)


def valores_return(colunas, tabela):
    for coluna in colunas:
        celula = coluna.find_all('td')
        celula = [ele.text.strip() for ele in celula]
        tabela.append([ele for ele in celula if ele])


def separar(palavra):
    numero = []
    for word in palavra:
        if word.isdigit():
            numero += word
    return (''.join(numero))


def initsintatico(token):
    tabela1 = []
    tabela2 = []
    beut(tabela1, tabela2)
    topo = tabela1[0]
    del tabela1[0]
    dict_tabela1 = {}
    dict_tabela2 = {}
    for colunas in tabela1:
        i = 0;
        for coluna in colunas:
            if coluna.isdigit() and i <= len(topo):
                dict_tabela1[(colunas[0], topo[i - 1])] = [int(coluna)]
            i += 1

    for i in range(len(tabela2)):
        if ((((tabela2[i][1]).split('::= '))[1]).split(" ")[0] != 'î'):
            dict_tabela2[int(separar(tabela2[i][0]))] = ((((tabela2[i][1]).split('::= '))[1]).split())
        else:
            dict_tabela2[int(separar(tabela2[i][0]))] = []
    analisadorsintatico(dict_tabela1, dict_tabela2, token)
