global limite_asm

limite_asm:
	xorpd xmm0, xmm0
	xorpd xmm1, xmm1
	mov r9, 1

	cvtsi2sd xmm0, r9
	cvtsi2sd xmm1, rdi
	divsd xmm0, xmm1

	cvtsi2sd xmm1, r9
	addsd xmm0, xmm1 	; xmm0 = (1 + 1/n)
	cvtsi2sd xmm1, r9	; xmm1 = 1

_loop:
	mov rax, rdi		; rax <- n
  	and rax, 1			; n & 1
	cmp rax, 0
	jne _multiplicar

_fin_multiplicar:
	mulsd xmm0, xmm0	; x = x * x
	shr rdi, 1   		; n = n/2
	cmp rdi, 0
	jne _loop

	movsd xmm0, xmm1
	ret

_multiplicar:
	mulsd xmm1, xmm0   	; res = rex*x
	jmp _fin_multiplicar