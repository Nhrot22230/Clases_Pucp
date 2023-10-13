section .data
	msg_in db "Inserte el numero: ", 0
	len_in equ $ - msg_in
	lectura dq 0
	num dq 0
	solution dq 0
	cifra dq 1

section .text
	global _start

_start:
	xor rcx, rcx
	xor r9, r9

_mensaje_inicio:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg_in
	mov rdx, len_in
	syscall

_bucle_lectura:
	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

	mov rdx, [lectura]
	cmp rdx, 10
	je _bucle_procesado
	
	inc r9
	sub rdx, 48
	push rdx
	xor rdx, rdx

	jmp _bucle_lectura

_bucle_procesado:
	pop rcx
	mov rax, [cifra]
	mul rcx
	add [num], rax

	mov rax, [cifra]
	mov rcx, 10
	mul rcx
	mov [cifra], rax

	dec r9
	cmp r9, 0
	jne _bucle_procesado 

_asignacion:
	mov rax, [num]
	xor rcx, rcx
	mov rbx, 10
	xor r9, r9

_push_loop:
	inc r9
	div rbx
	push rdx
	xor rdx, rdx
	cmp rax, 10
	jl _aux
	jmp _push_loop

_aux:
	inc r9
	push rax

_pop_loop:
	pop rcx
	add rcx, 48
	mov [solution], rcx

_imprimir_entero:
	mov rax, 1
	mov rdi, 1
	mov rsi, solution
	mov rdx, 1
	syscall

	dec r9
	cmp r9, 0
	jne _pop_loop


_final:
	mov [solution], byte 10
	mov rax, 1
	mov rdi, 1
	mov rsi, solution
	mov rdx, 1
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
	