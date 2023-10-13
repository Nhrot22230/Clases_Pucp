global limite_lineal_asm

limite_lineal_asm:
	xorpd xmm0, xmm0
	xorpd xmm1, xmm1
	mov r9, 1

	cvtsi2sd xmm0, r9
	cvtsi2sd xmm1, rdi
	divsd xmm0, xmm1

	cvtsi2sd xmm1, r9
	addsd xmm0, xmm1 	; xmm0 = (1 + 1/n)
	movsd xmm1, xmm0	; xmm1 = xmm0

_loop:
	mulsd xmm0, xmm1

	dec rdi
	cmp rdi, 0
	jne _loop

	ret