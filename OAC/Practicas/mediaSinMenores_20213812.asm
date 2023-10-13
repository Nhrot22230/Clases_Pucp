section .data
	;Mensajes
    firstMsg db "Ingrese la cantidad de menores a quitar: " 
	lenf equ $ - firstMsg
	secondMsg db "La media calculada es: " 
	lens equ $ - secondMsg
    ;Variables
    arreglo dq 5, 3, 4, 8, 9, 7
    lenArr dq 6
    numMenores dq 0
    ;Auxiliares
	solution dq 0
    char dq 10 ;ASCII del cambio de linea
    lectura dq 0
    
section .text          ;Code Segment
    global _start

_start:
    mov rax, 1
	mov rdi, 1
	mov rsi, firstMsg
	mov rdx, lenf
	syscall

    mov rax, 0
	mov rdi, 0
	mov rsi, numMenores
	mov rdx, 1
	syscall

	mov rax, [numMenores]
	sub rax, 48
	mov [numMenores], rax

    mov rax, 0
	mov rdi, 0
	mov rsi, char
	mov rdx, 1
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, secondMsg
	mov rdx, lens
	syscall

inicio:
    ; Limpiar los registros a utilizar
    xor rax,rax
    xor rbx,rbx
    xor rcx,rcx
    xor rdx,rdx

    ;********************
    ; INICIO DEL CÓDIGO
    ;********************
    
    ;recorrer arreglo
   	mov r9, 0        ; for i = 0; i<n - 1: i++
_bucle_for_i:
	inc r9
    mov r8, r9       ; for j = i + 1; j<n; j++
    dec r9
	_bucle_for_j:   
		mov rbx, [arreglo + 8*r9]   ;arr[i]
		mov rcx, [arreglo + 8*r8]   ;arr[j]
		cmp rbx, rcx				; if arr[i] > arr[j]
		jg _cambiar

	_luego_de_cambiar:
		inc r8
		mov rax, [lenArr]
		cmp r8, rax
		jl _bucle_for_j

	mov rax, [lenArr]
	dec rax
	inc r9
	cmp r9, rax
	jl _bucle_for_i

_saltar_n_numeros:
	mov r9, [numMenores]
	mov r8, [lenArr] ;contador de numeros
	cmp r9, r8       ; if numMenores >= lenArr return 0;
	jge final_alt

	sub r8, r9  ; cantidad de numeros 
_calcular_media_bucle_i:
	mov rbx, [arreglo + 8*r9] ; arr[i+n]
	add [solution], rbx
	inc r9
	mov rax, [lenArr]
	cmp r9, rax
	jl _calcular_media_bucle_i

	mov rax, [solution]
	xor rdx, rdx
	mov rbx, r8
	div rbx

	mov [solution], rax

_asignacion_3:
	mov r9, 0
	mov rax, [solution]
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

jmp final

final_alt:
	mov rcx, 48
	mov [lectura], rcx
	
	mov rax, 1
	mov rdi, 1
	mov rsi, lectura
	mov rdx, 1
	syscall

	jmp final

_cambiar:
	mov [arreglo + 8*r9], rcx
	mov [arreglo + 8*r8], rbx
	jmp _luego_de_cambiar

final:
    mov rax, 1
	mov rdi, 1
	mov rsi, char
	mov rdx, 1
	syscall

    mov rax, 60
	mov rdi, 0
	syscall