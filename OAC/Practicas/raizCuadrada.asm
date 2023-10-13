section .data
	msj_inicio db "Inserte un numero: ", 0
	len_inicio equ $ - msj_inicio
	msj_salida db "La raiz del numero es: ", 0
	len_salida equ $ - msj_salida
	solution dq 0
	num dq 0
	cifra dq 1
	cantDecimales dq 4
	factorDecimales dq 10000  ; 2 decimales

section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, msj_inicio
	mov rdx, len_inicio
	syscall

	xor r9, r9
_lectura_numero:
	mov rax, 0
	mov rdi, 0
	mov rsi, num
	mov rdx, 1
	syscall

	mov rax, [num]
	mov [num], byte 0

	cmp rax, 10
	je _fin_lectura
	
	sub rax, 48
	push rax
	inc r9
	jmp _lectura_numero


_fin_lectura:
	pop rcx
	mov rax, [cifra]
	mul rcx
	add [num], rax

	xor rdx, rdx

	mov rax, [cifra]
	mov rcx, 10
	mul rcx
	mov [cifra], rax

	xor rdx, rdx

	dec r9
	cmp r9, 0
	jne _fin_lectura

_convertir_flotante:
	xor rax, rax
	mov eax, [num]
	cvtsi2sd xmm0, rax
	sqrtsd xmm0, xmm0

	xor rax, rax
	mov rax, [factorDecimales]
	cvtsi2sd xmm1, rax
	
	mulsd xmm0, xmm1
	cvtsd2si rax, xmm0
	mov [num], rax

_antes_imprimir:
	mov rax, 1
	mov rdi, 1
	mov rsi, msj_salida
	mov rdx, len_salida
	syscall

_imprimir_numero:
	mov rax, [num]
	xor rdx, rdx
	xor rcx, rcx
	xor r9, r9
	mov r8, 10
_imp_push_loop:
	
	inc r9
	cmp rax, 10
	jl _imp_aux
	
	div r8
	add rdx, 48
	push rdx
	
	xor rdx, rdx
	jmp _imp_push_loop

_imp_aux:
	add rax, 48
	push rax

_imp_pop_loop:
	pop rcx
	mov [solution], rcx

	mov rax, 1
	mov rdi, 1
	mov rsi, solution
	mov rdx, 1
	syscall

	dec r9
	mov r8, [cantDecimales]
	cmp r9, r8
	je _imprimir_puntito
_fin_puntito:
	cmp r9, 0
	jne _imp_pop_loop
	jmp _final

_imprimir_puntito:
	mov rcx, 46
	mov [solution], rcx
	mov rax, 1
	mov rdi, 1
	mov rsi, solution
	mov rdx, 1
	syscall
	jmp _fin_puntito

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


