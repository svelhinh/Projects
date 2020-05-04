%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4
%define NL                  10

section .data
    new_line db NL

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rsi, rdi
	call _ft_strlen
	mov rdx, rax
	mov rdi, STDOUT
    mov rax, MACH_SYSCALL(WRITE)
    syscall
	lea rsi, [rel new_line]
	mov rdx, 1
    mov rax, MACH_SYSCALL(WRITE)
    syscall
	leave
	ret