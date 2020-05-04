section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	cmp rdi, 0
	je null
	cmp rsi, 0
	je null
	xor rax, rax
	call _ft_strlen
	jmp begin_loop

begin_loop:
	cmp [rsi], byte 0
	je end_loop
	mov rax, [rsi]
	mov [rdi], rax
	inc rdi
	inc rsi
	jmp begin_loop

end_loop:
	mov [rdi], byte 0
	mov rax, rdi
	jmp return

null:
	mov rax, 0

return:
	ret