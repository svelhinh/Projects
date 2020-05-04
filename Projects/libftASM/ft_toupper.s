section .text
	global _ft_toupper
	extern _ft_islower

_ft_toupper:
	call _ft_islower
	test rax, rax
	je false
	jmp true

false:
	mov rax, rdi
	ret

true:
	sub rdi, 0x20
	mov rax, rdi
	ret