section .text
	global _ft_isascii

_ft_isascii:
	xor rax, rax
	cmp rdi, 0x0
	jl false
	cmp rdi, 0x7f
	jg false
	jmp true

false:
	ret

true:
	inc rax
	ret