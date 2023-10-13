	global asmFloatInnerProd
	section .text

asmFloatInnerProd:
	xorpd	xmm0,	xmm0
	xorpd	xmm1,	xmm1
	xorpd	xmm2,	xmm2
	cmp	rdx,	0
	je	done
next:
	movss	xmm0,	[rdi]
	movss	xmm1,	[rsi]
	mulss	xmm0,	xmm1
	addss	xmm2,	xmm0
	add	rdi,	4
	add	rsi,	4
	sub	rdx,	1
	jnz	next	
done:
	movss	[rcx],	xmm2
	ret

	