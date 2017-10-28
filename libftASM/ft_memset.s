section .text
	global _ft_memset

_ft_memset:
	cmp rdi, 0
	je return

_loop:
	cmp rdx, 0
	je return
	mov [rdi], sil
	inc rdi
	dec rdx
	jmp _ft_memset

return:
	mov rax, rdi
	ret