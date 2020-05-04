section .text
	global _ft_isupper

_ft_isupper:
	xor rax, rax
	cmp rdi, 0x41
	jl false
	cmp rdi, 0x5a
	jg false
	jmp true

false:
	ret

true:
	inc rax
	ret