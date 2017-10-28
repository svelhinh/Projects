section .text
	global _ft_bzero

_ft_bzero:
	cmp rdi, 0
	je return

_loop:
	cmp rsi, 0
	je return
	mov [rdi], byte 0
	inc rdi
	dec rsi
	jmp _ft_bzero

return:
	ret