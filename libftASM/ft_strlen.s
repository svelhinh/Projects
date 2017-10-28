section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	jmp begin_loop

begin_loop:
	cmp [rdi], byte 0
	je end_loop
	inc rdi
	inc rax
	jmp begin_loop

end_loop:
	ret