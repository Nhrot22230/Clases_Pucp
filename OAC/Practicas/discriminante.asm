section .data

	msg_a dq "Ingreso a numero a: ", 0
	len_a equ $ - msg_a
	msg_b dq "Ingreso a numero b: ", 0
	len_b equ $ - msg_b
	msg_c dq "Ingreso a numero c: ", 0
	len_c equ $ - msg_c

	lectura dq 0
	b_square dq 0
	four_ac dq 0
	num dq 0


section .text
	global _start 

_start:

_lectura_a:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg_a
	mov rdx, len_a
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

	mov rbx, [lectura]
	sub rbx, 48
	mov rax, 4
	mul rbx
	mov [four_ac], rax

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

_lectura_b:

	mov rax, 1
	mov rdi, 1
	mov rsi, msg_b
	mov rdx, len_b
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

	xor rdx, rdx
	mov rax, [lectura]
	sub rax, 48
	mov rbx, rax
	mul rbx
	mov [b_square], rax

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

_lectura_c:

	mov rax, 1
	mov rdi, 1
	mov rsi, msg_c
	mov rdx, len_c
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, lectura
	mov rdx, 1
	syscall

	xor rdx, rdx
	mov rbx, [lectura]
	sub rbx, 48
	mov rax, [four_ac]
	mul rbx
	mov [four_ac], rax


_comparacion:

	mov rax, [b_square]
	mov rcx, [four_ac]

	cmp rax, rcx
	jl _impresion_negativo
	sub rax, rcx
	mov [num], rax
	jmp _asignacion_3

_impresion_negativo:
	sub rcx, rax
	mov [lectura] , byte '-'
	mov [num], rcx
	mov rax, 1
	mov rdi, 1
	mov rsi, lectura
	mov rdx, 1
	syscall


_asignacion_3:
	mov r9, 0
	mov rax, [num]
	mov rbx, 10
	xor rdx, rdx

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
