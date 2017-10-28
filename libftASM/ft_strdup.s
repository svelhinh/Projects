section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	cmp rdi, 0
	je null

_begin:
	push rbp
	mov rbp, rsp
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	push rdi
	call _malloc
	mov rdi, rax
	pop rdx
	pop rsi
	call _ft_memcpy
	leave
	jmp return

null:
	mov rax, rdi

return:
	ret