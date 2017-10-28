section .text
	global _ft_isdigit

_ft_isdigit:
	xor rax, rax
	cmp rdi, 0x30
	jl false
	cmp rdi, 0x39
	jg false
	jmp true

false:
	ret

true:
	inc rax
	ret