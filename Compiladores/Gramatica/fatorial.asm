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
;Impressão na tela
push msg0
call printf
add esp, 4

;Ler do Teclado
push var1
push formatacao
call scanf
add esp, 8

;Atribuição
mov eax,[var2]
mov eax, 1
mov [var2],eax
xor eax,eax

;Label
_L0:
xor eax,eax
xor ebx, ebx
mov eax, [var1]
mov ebx, 1
cmp eax, ebx
jbe _L1
;Multiplicação
mov eax, [var1]
mov edx, [var2]
imul eax, edx
mov [var2], eax
xor eax,eax

;Subtração
mov eax, [var1]
mov edx, 1
sub eax, edx
mov [var1], eax
xor eax,eax

jmp _L0
_L1:
;Impressão na tela
push [var2]
push formatacao
call printf
add esp, 4

;Impressão na tela
push msg1
call printf
add esp, 4

sair:
push 0
call exit

section '.data' writeable
formatacao db '%d' , 0
msg0 db 'Escreva um numero: ', 0,0
var2 dd 0
var1 dd 0
msg1 db '',10,0,'', 0,0