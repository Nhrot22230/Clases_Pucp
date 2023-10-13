section .data
	arr_1 dq 0,0,0,0,0
	arr_2 dq 4 DUP(0)
section .text
	global _start

_start:
	mov rax, 60
	mov rdi, 0
	syscall