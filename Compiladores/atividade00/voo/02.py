Origem=input("Origem: ")
Destino=input("Destino: ")
aux=0
with open("voo.txt") as f:
    for line in f:
        Nline = line.split('>')
        if (Origem in Nline[2]) and (Destino in Nline[3]):
           aux += line.count(Origem)>0
           print(line)
if aux == 0:
    print("Destino inexistente")
