section .data
	msj_entrada_x db "Inserte coord x: ", 0
	msj_entrada_y db "Inserte coord y: ", 0
	len_entrada equ $ - msj_entrada_y

	

section .txt
	global _start


_start:

	mov rax, 60
	mov rdi, 0
	syscall