section .text
	global _ft_memcpy

_ft_memcpy:
	cmp rdi, 0
	je return
	cmp rsi, 0
	je return

_loop:
	mov rax, rdi
	cmp rdx, 0
	je return
	mov rcx, rdx
	mov rax, rsi
	mov r8, rdi
	cld
	rep movsb
	mov rax, r8

return:
	ret