section .text
	global _ft_tolower
	extern _ft_isupper

_ft_tolower:
	call _ft_isupper
	test rax, rax
	je false
	jmp true

false:
	mov rax, rdi
	ret

true:
	add rdi, 0x20
	mov rax, rdi
	ret