;flat assembler  version 1.73.02
;fasm final.asm
;ld -lc -e main -dynamic-linker /lib/ld-linux.so.2  final.o -o final -m elf_i386
;OS: Ubuntu 18.04.1 LTS x86_64 
;Kernel: 4.15.0-42-generic 
;CPU: Intel i5-2520M (4) @ 3.200GHz

format ELF
public main as 'main' 
extrn 'exit'as exit
extrn 'printf' as printf
extrn 'scanf'as scanf

section '.text' executable
main:
;Atribuição
mov eax,[var1]
mov eax, 1
mov [var1],eax
xor eax,eax

;Atribuição
mov eax,[var2]
mov eax, 3
mov [var2],eax
xor eax,eax

;Adicção
mov eax, [var1]
mov edx, [var2]
add eax, edx
mov [var3], eax
xor eax,eax

;Impressão na tela
push [var3]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg0
call printf
add esp, 4

;Subtração
mov eax, [var1]
mov edx, [var2]
sub eax, edx
mov [var3], eax
xor eax,eax

;Impressão na tela
push [var3]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg1
call printf
add esp, 4

;Atribuição
mov eax,[var3]
mov eax, [var1]
mov [var3],eax
xor eax,eax

;Impressão na tela
push [var3]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg2
call printf
add esp, 4

;Divisao
xor edx, edx
mov eax, [var1]
div [var2]
mov [var3], eax
xor eax,eax

;Impressão na tela
push [var3]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg3
call printf
add esp, 4

;Label
_C0:
xor eax,eax
xor ebx, ebx
mov eax, [var3]
mov ebx, [var1]
cmp eax, ebx
jbe _C1
;Label
_C2:
xor eax,eax
xor ebx, ebx
mov eax, [var1]
mov ebx, [var2]
cmp eax, ebx
jbe _C3
;Impressão na tela
push [var2]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg4
call printf
add esp, 4

jmp EXIT_C2
_C3:
EXIT_C2:
jmp EXIT_C0
_C1:
;Impressão na tela
push [var2]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg5
call printf
add esp, 4

EXIT_C0:
sair:
push 0
call exit

section '.data' writeable
formatacao db '%d' , 0
var1 dd 0
var2 dd 0
var3 dd 0
msg0 db ' ',10,0,'', 0,0
msg1 db ' ',10,0,'', 0,0
msg2 db ' ',10,0,'', 0,0
msg3 db ' ',10,0,'', 0,0
msg4 db ' ',10,0,'', 0,0
msg5 db ' ',10,0,'', 0,0