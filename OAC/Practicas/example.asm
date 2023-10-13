section .data
	msg_in dq "Ingrese la cantidad de cifras: ", 0
	len_in equ $ - msg_in
	msg_num dq "Ingrese el numero: ", 0
	len_num equ $ - msg_num

	cant dq 0
	num dq 0
	lectura dq 0
	cifra dq 1
section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg_in
	mov rdx, len_in
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, cant
	mov rdx, 1
	syscall
	
	mov rcx, [cant]
	sub rcx, 48
	mov [cant], rcx
	xor rcx, rcx

	mov rax, 1
	mov rdi, 1
	mov rsi, msg_num
	mov rdx, len_num
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall
	
_asignacion_1:
	mov r9, [cant]
	dec r9

_bucle_multiplicacion:
	cmp r9, 0
	je _asignacion_2

	mov rax, [cifra]
	mov rbx, 10
	mul rbx
	mov [cifra], rax
	xor rdx, rdx
	
	dec r9
	jmp _bucle_multiplicacion

_asignacion_2:
	mov r9, [cant]

_bucle_lectura:
	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall
	
	mov rcx, [lectura]
	sub rcx, 48
	mov rax, [cifra]
	mul rcx
	add [num], rax
	xor rdx, rdx

	mov rax, [cifra]
	mov rcx, 10
	div rcx
	mov [cifra], rax
	xor rdx, rdx

	dec r9
	cmp r9, 0
	jne _bucle_lectura

_asignacion_3:
	mov r9, 0
	mov rax, [num]
	mov rbx, 10

_bucle_push:
	cmp rax, 10
	jl _aux

	div rbx
	push rdx
	xor rdx, rdx

	inc r9
	jmp _bucle_push

_aux:
	push rax
	inc r9

_bucle_pop:
	pop rcx
	add rcx, 48
	mov [lectura], rcx

	mov rax, 1
	mov rdi, 1
	mov rsi, lectura
	mov rdx, 1
	syscall

	dec r9
	jne _bucle_pop

_final:
	mov [lectura], byte 10
	mov rax, 1
	mov rdi, 1
	mov rsi, lectura
	mov rdx, 1
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
