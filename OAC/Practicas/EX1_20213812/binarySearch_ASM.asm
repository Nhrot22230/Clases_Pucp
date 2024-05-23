; 10
; 2 4 6 8 10 12 14 16 18 20
; 1 3 5 7  9 11 13 15 17 19

global binarySearch_ASM
section .text

binarySearch_ASM:
	; rdi -> arrNums
	; rsi -> numA
	; rdx -> numB
	; rcx -> cant_elem

	mov r9, 0  ; left = 0
	mov r8, rcx ; right = cant_elem - 1
	dec r8
	xor rbx, rbx

	mov r10, 0  ; med

_primer_binarySearch:
	mov r10, r9	; med  = left
	add r10, r8    ; med  = med + right
	shr r10, 1

	mov rax, rsi
	mov ebx, [rdi + 4*r10]

	cmp rax, rbx  ; numA > arr[r10]
	
	je _fin_primer_binarySearch

	jg _disminuir_primer_izquierda

	jmp _disminuir_primer_derecha

_dsp_disminuir_primer:
	cmp r9, r8
	jle _primer_binarySearch

	jmp _fin_primer_binarySearch

_disminuir_primer_izquierda:
	add r10, 1		; med + 1
	mov r9, r10	; left = med + 1
	jmp _dsp_disminuir_primer 

_disminuir_primer_derecha:
	dec r10			; med - 1
	mov r8, r10	; left = med - 1
	jmp _dsp_disminuir_primer

_fin_primer_binarySearch:
	mov r9, 0 			; r10 tiene el index de numA
	mov r8, rcx
	dec r8
	xor rbx, rbx
	jmp _segundo_binarySearch

_segundo_binarySearch:
	mov r14, r9	; med  = left
	add r14, r8    ; med  = med + right
	shr r14, 1

	mov rax, rdx
	mov ebx, [rdi + 4*r14]

	cmp rax, rbx  ; numA > arr[r14]
	
	je _fin_segundo_binarySearch

	jg _disminuir_segundo_izquierda

	jmp _disminuir_segundo_derecha

_dsp_disminuir_segundo:
	cmp r9, r8
	jle _segundo_binarySearch

	jmp _fin_segundo_binarySearch

_disminuir_segundo_izquierda:
	add r14, 1		; med + 1
	mov r9, r14	; left = med + 1
	jmp _dsp_disminuir_segundo

_disminuir_segundo_derecha:
	dec r14			; med - 1
	mov r8, r14	; left = med - 1
	jmp _dsp_disminuir_segundo


_fin_segundo_binarySearch:
	; r14 tiene el index de numB
	cmp r10, r14
	jg _cambiar_valores
_dsp_de_cambiar_valores:
	mov r8, r10
	mov r9, r14
	mov rax, 1


_for_i_r8:
	mov r10d, [rdi + 4*r8]
	mul r10
	inc r8
	cmp r8, r9
	jle _for_i_r8

; rax = r8 *...* r9

mov r9, 0
jmp _sumaDigitos

_cambiar_valores:
	mov rax, r10
	mov r10, r14
	mov r14, rax

	xor rax, rax
	jmp _dsp_de_cambiar_valores

_sumaDigitos:
	mov rbx, 10
	xor rdx, rdx	; rax = 960 | rbx = 10 | rdx = 0
	div rbx  		; rax = rax/10 -> rdx = rax%10
	add r9, rdx

	cmp rax, 0
	jne _sumaDigitos


_final:
	mov rax, r9
	ret

