; Programa sumas.asm
; Para ensamblar ejecutar:
; nasm -f elf64 sumas.asm -o sumas.o
; Para enlazar ejecutar:
; ld sumas.o -o sumas
; Para correr el ejecutable:
; ./sumas

; SEGMENTO DE DATOS
section .data
	saludo db "Ingrese un numero para n: "
	len_saludo equ $ - saludo
	msj_res db "La solucion es: "
	len_msj_res equ $ - msj_res
    
    num dq 0
    solution dq 0

; SEGMENTO DE TEXTO
section .text
	global _start

; SYS_WRITE
_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, saludo
	mov rdx, len_saludo
	syscall

; SYS_READ
	mov rax, 0
	mov rdi, 0
	mov rsi, num
	mov rdx, 1
	syscall

	mov rcx, [num]
	sub rcx, 30H


_countLoop:
	mov rax, rcx
	mul rcx ; rax = rax * rcx
	add [solution], rax
	dec rcx
	cmp rcx, 0
	jne	_countLoop

; SYS_WRITE
	mov rax, 1
	mov rdi, 1
	mov rsi, msj_res
	mov rdx, len_msj_res
	syscall

test:                 ; pushea en pila el resultado
	xor rcx, rcx
	mov r8, 10
	mov rcx, [solution]
	mov rbx, 0
	xor rdx, rdx

division:
	mov rax, rcx
	cmp rax, r8
	jl aux  ; si el numero es menor a 1 digito

	div r8  ; rdx residuo rax cociente
	inc rbx
	push rbx

	mov rcx, rax
	jmp division

aux:
	push rax
	inc rbx

loopPrint:
	cmp rbx, 0
	je final
	dec rbx
    pop rcx


    add rcx, 30H
    mov [solution], rcx


    mov rax, 1
    mov rdi, 1
    mov rsi, solution
    mov rdx, 1
    syscall
    jmp loopPrint

final:
; SYS_EXIT
	mov rax, 60
	mov rdi, 0
	syscall