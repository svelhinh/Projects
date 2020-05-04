section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	xor rax, rax
	call _ft_isalpha
	test rax, rax
	jne false
	call _ft_isdigit

false:
	ret