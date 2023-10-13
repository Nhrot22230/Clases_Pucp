global varianza_asm

varianza_asm:
	xor r9, r9  ; i = 0
	xorpd xmm0, xmm0  ; suma = 0
	xorpd xmm1, xmm1  ; media = 0
	xorpd xmm2, xmm2  ; temp
_for_i:
	addss xmm0, [rdi + 4*r9]
	inc r9
	cmp r9, rsi
	jne _for_i

_calcular_media:
	cvtsi2ss xmm1, r9   ; media = r9
	divss xmm0, xmm1    ; suma = suma / media
	movss xmm1, xmm0    ; media = suma

	xor r9, r9     		; i = 0
	xorpd xmm0, xmm0 		; suma = 0
_for_i_varianza:
	movss xmm2, [rdi + 4*r9]
	subss xmm2, xmm1    ; xmm2 = xmm2 - xmm1
	mulss xmm2, xmm2    ; xmm2 = xmm2 * xmm2

	addss xmm0, xmm2     ; xmm0 = xmm0 + xmm2
	inc r9
	cmp r9, rsi
	jne _for_i_varianza

	cvtsi2ss xmm1, r9   ; media = r9
	divss xmm0, xmm1    ; suma = suma / media

	ret
