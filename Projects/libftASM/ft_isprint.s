section .text
	global _ft_isprint

_ft_isprint:
	xor rax, rax
	cmp rdi, 0x20
	jl false
	cmp rdi, 0x7f
	jg false
	jmp true

false:
	ret

true:
	inc rax
	ret