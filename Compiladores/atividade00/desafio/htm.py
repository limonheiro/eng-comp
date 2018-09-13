#!/usr/bin/python3

with open('Home | Edmodo') as pagina:
    for line in pagina:
        Nline=line.split('>')
        for i in Nline:
            if ('<' not in i)and('</'not in i):
                print(i)
