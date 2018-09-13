def write():
 file1=open('arquivo1','a')
 nome = input("Nome: ")
 nome+="\n"
 file1.write(nome)
 file1.close()
 return

def ordenar():
 file1=open('arquivo1','r')
 arquivo2=sorted(file1.readlines())
 file1.close()
 file2=open('arquivo2','w')
 for i in arquivo2:
     file2.write(i)
 file2.close()

C=int(input("Quantidade de nomes:"))
for i in range(0,C):
    write()
ordenar()
