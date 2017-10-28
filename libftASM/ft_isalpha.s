section .text
	global _ft_isalpha
	extern _ft_isupper
	extern _ft_islower

_ft_isalpha:
	xor rax, rax
	call _ft_islower
	test rax, rax
	jne false
	call _ft_isupper

false:
	ret