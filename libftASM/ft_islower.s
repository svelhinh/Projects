section .text
	global _ft_islower

_ft_islower:
	xor rax, rax
	cmp rdi, 0x61
	jl false
	cmp rdi, 0x7a
	jg false
	jmp true

false:
	ret

true:
	inc rax
	ret