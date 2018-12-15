'''
    intermediario(token, argumentos, posicao inicial que deseja converter para assembler, posição final, valor inicial das Labels dos loops, texto final)
'''
def intemerdiario(token,args, inicio, fim, loop,condicional, texto):
    L=0
    C=0
    pilha=[]
    i=inicio
    senao=""
    while i < fim :
        if 'inteiro' in token[i][0]:
            if (args.lgc):
                print ("Inteiro identificado:")
            texto.extend(variaveis(token,i))
        elif 'leia' in token[i][0]:
            if (args.lgc):
                print ("leia identificado:")
            texto.append('LEIA '+token[i+2][1])
        elif 'escreva' in token[i][0]:
            if (args.lgc):
                print ("escreva identificado:")
            texto.append('ESCREVA '+ token[i+2][1])
        elif 'recebe' in token[i][0]:
            if (args.lgc):
                print ("Atribuição identificada:")
            exp=[]
            from infixtoposfix import infixToPostfix
            exp.append(infixToPostfix(expressao(token, i)))
            simpleexpre(exp,token[i-1][1],texto)
        elif 'enquanto' in token[i][0]:
            if (args.lgc):
                print ("função enquanto identificado:")
            texto.append(f'_L{L}: repeat {token[i+2][1]}'+ (' >=' if '<' in token[i+3][1] else ' <=')+f' {token[i+4][1]} goto _L{L+1} ')
            i=intemerdiario(token, args, i+6, fim, L+1, C, texto)
            texto.append(f'goto _L{L}')
            texto.append(f'_L{L+1}:')
            L=L+i
            C=L
        elif 'se' == token[i][0]:
            if (args.lgc):
                print ("\'se\' identificado:")
            texto.append(f'_C{C}: if {token[i+2][1]}' + (' >' if '<' in token[i+3][1] else ' <')+f' {token[i+4][1]} goto _C{C+1}')
            i=intemerdiario(token, args, i+6, fim, L, C+1, texto)
            if 'senao' == token[i+1][0]:
                if (args.lgc):
                    print ("\'senao\' identificado:")
                texto.append(f'goto sair_C{C}')
            texto.append(f'_C{L+1}:')
            C = C + i
            L = C
        elif 'senao' == token[i][0]:
            senao=texto[-1]
        elif '}' in token[i][1]:
            if len(senao)>0:
                texto.append(f'sair{senao}')
                senao=""
            else:
                return i
        i=i+1

    with open('intermediario.s','w') as f:
        if (args.lgc):
            print ("Escrevendo no arquivo:")
        f.write('\n'.join(texto))
def simpleexpre(exp,var,texto):
    '''
    ADD dest,src1,src2	dest = src1 + src2
    SUB dest,src1,src2	dest = src1 - src2
    ADDI dest,src1,I	dest = src1 + I
    MUL dest,src1,src2	dest = src1 × src2
    DIV dest,src1,src2	dest = src1/src2
    '''
    t=1
    exp=exp[0].split()
    values=[]
    operador=['+','-','*','/']
    for i in range(len(exp)):
        if exp[i] in operador:
            a = values.pop()
            b = values.pop()
            if i == len(exp)-1:
                texto.append(f'{var} := {b} {a} {exp[i]}')
            else:
                texto.append(f'T{t} := {b} {a} {exp[i]}')
                values.append(f'T{t}')
                t+=1
        else:
            values.append(exp[i])
    if len(values) > 0:
        texto.append(f'{var} := {values[0]}')

def expressao(token, i):
    l=i+1
    var=[]
    while not('fim_linha' in token[l][0]):
        var.append(token[l][1])
        l+=1
    return ' '.join(var)
def variaveis(token,i):
    l=i+1
    var=[]
    while not('fim_linha' in token[l][0]):
        if not('virgula' in token[l][0]):
            var.append('INTEIRO '+token[l][1])
        l+=1
    return var
def gerarcodigo(token,args):
    texto=[]
    '''
    intermediario(token, args, posicao inicial que deseja converter para assembler, posição final, valor inicial das Labels dos loops, valor inicial das Labels dos condicionais)
    '''
    intemerdiario(token, args, 0, len(token), 0, 0, texto)
    gerar()
def gerar():
    texto=[]
    with open('intermediario.s','r') as f:
        texto=f.readlines()
    i=0
    final=[]
    db=[]
    msg=-1
    final.append(';fasm final.asm')
    final.append(';ld -lc -e main -dynamic-linker /lib/ld-linux.so.2  final.o -o final -m elf_i386')
    final.append(f'\nformat ELF')
    final.append('public main as \'main\' ')
    final.append('extrn \'exit\'as exit')
    final.append('extrn \'printf\' as printf')
    final.append('extrn \'scanf\'as scanf\n')

    final.append('section \'.text\' executable')

    final.append('main:')

    while i < len(texto):
        if 'ESCREVA' in texto[i].split('"')[0]:
            final.append(';Impressão na tela')
            if '"' in texto[i]:
                msg += 1
                size = texto[i].strip('ESCREVA')
                text = size.strip('\n').replace('"','')
                final.append(f'push msg{msg}')
                final.append(f'call printf')
                final.append(f'add esp, 4\n')

                db.append(f'msg{msg} db \'{text.strip()}\', 10,0')
            else:
                expre = texto[i].split()
                final.append(f'push {"["+expre[1]+"]" if expre[1].isidentifier() else expre[1] }')
                final.append(f'push formatacao')
                final.append(f'call printf')
                final.append(f'add esp, 4\n')
        elif 'LEIA' in texto[i].split()[0]:
            final.append(';Ler do Teclado')
            final.append(f'push {texto[i].split()[1]}')
            final.append(f'push formatacao')
            final.append(f'call scanf')
            final.append(f'add esp, 8\n')
        elif len(texto[i].split())>2:
            if ':=' in texto[i].split()[1]:
                expre = texto[i].split()
                if not (expre[0] in ''.join(db)):
                    db.append(f'{expre[0]} dd 0')
                if len(expre)==3:
                    final.append(f';Atribuição')
                    final.append(f'mov eax,[{expre[0]}]')
                    final.append(f'mov eax, {"["+expre[2]+"]" if expre[2].isidentifier() else expre[2] }')
                    final.append(f'mov [{expre[0]}], eax')
                    final.append(f'xor eax,eax\n')
                elif '+' is expre[4]:
                    final.append(f';Adicção')
                    final.append(f'mov eax, {"["+expre[2]+"]" if expre[2].isidentifier() else expre[2] }')
                    final.append(f'mov edx, {"["+expre[3]+"]" if expre[3].isidentifier() else expre[3] }')
                    final.append(f'add eax, edx')
                    final.append(f'mov {"["+expre[0]+"]"}, eax')
                    final.append(f'xor eax,eax\n')
                elif '-' is expre[4]:
                    final.append(f';Subtração')
                    final.append(f'mov eax, {"["+expre[2]+"]" if expre[2].isidentifier() else expre[2] }')
                    final.append(f'mov edx, {"["+expre[3]+"]" if expre[3].isidentifier() else expre[3] }')
                    final.append(f'sub eax, edx')
                    final.append(f'mov {"["+expre[0]+"]"}, eax')
                    final.append(f'xor eax,eax\n')
                elif '*' is expre[4]:
                    final.append(f';Multiplicação')
                    final.append(f'mov eax, {"[" + expre[2] + "]" if expre[2].isidentifier() else expre[2] }')
                    final.append(f'mov edx, {"[" + expre[3] + "]" if expre[3].isidentifier() else expre[3] }')
                    final.append(f'imul eax, edx')
                    final.append(f'mov {"[" + expre[0] + "]"}, eax')
                    final.append(f'xor eax,eax\n')
                elif '/' is expre[4]:
                    final.append(f';Divisao')
                    final.append(f'mov edx, 0')
                    final.append(f'mov eax, {"[" + expre[2] + "]" if expre[2].isidentifier() else expre[2] }')
                    final.append(f'div {"[" + expre[3] + "]" if expre[3].isidentifier() else expre[3] }')
                    final.append(f'mov {"[" + expre[0] + "]"}, eax')
                    final.append(f'xor eax,eax\n')
        #elif 'LEIA' in texto[i]:
        i+=1
    final.append('sair:')
    final.append('push 0')
    final.append('call exit\n')

    if(len(db)>0):
        final.append('section \'.data\' writeable')
        final.append('formatacao db \'%d\' , 0')
        final.extend(db)
    with open('final.asm','w') as f:
        f.write('\n'.join(final))