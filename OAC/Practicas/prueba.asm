; SEGMENTO DE DATOS
section .data
	primero dq 1
	segundo dq 1
	solution dq 0

section .text
	global _start

_start:
	mov r8, 20

_fibo_loop:
	mov rax, [primero]
	add rax, [segundo] ; rax = f(n) = f(n-1) + f(n-2)
	mov rdx, [segundo]

	mov [primero], rdx
	mov [segundo], rax

	xor rdx, rdx
	mov rbx, 10
	mov r9, 0

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


	mov [solution], byte 10
		mov rax, 1
		mov rdi, 1
		mov rsi, solution
		mov rdx, 1
		syscall

	dec r8
	cmp r8, 0
	jne _fibo_loop

_final:
	mov rax, 60
	mov rdi, 0
	syscall



