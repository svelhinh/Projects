%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define WRITE				4
%define STDOUT				1
%define BUFFER_SIZE			10

section .bss
	file_buffer resb BUFFER_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	cmp edi, -1
	je _read_stdin
	cmp edi, 0
	jl return
	jmp _other_fd

_read_stdin:
	xor rdi, rdi

_fd_zero:
	mov rax, MACH_SYSCALL(READ)
	mov rsi, file_buffer
	mov rdx, BUFFER_SIZE
	syscall

	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	push rdi
	mov rdi, STDOUT
	mov rsi, file_buffer
	syscall
	pop rdi

	jmp _fd_zero

_other_fd:
	mov rax, MACH_SYSCALL(READ)
	mov rsi, file_buffer
	mov rdx, BUFFER_SIZE
	syscall

	cmp rax, 0
	je return

	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	push rdi
	mov rdi, STDOUT
	mov rsi, file_buffer
	syscall
	pop rdi

	jmp _other_fd

return:
	leave
	ret