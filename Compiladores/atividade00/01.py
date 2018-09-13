arquivo = input("Digite o nome do arquivo: ")
print(arquivo)
file=open(arquivo,"r")
total=file.readlines()
print("linhas = ", len(total))

listaPalavras = 0
numlines = 0
numWords = 0
numChar = 0
with open(arquivo,'r') as file:
    for line in file:
        listaPalavras= line.split()
        numlines +=1
        numWords += len(listaPalavras)
        numChar += len(line)
print(f'linhas =  {numlines}  palavras = {numWords} Caracters = {numChar}')
