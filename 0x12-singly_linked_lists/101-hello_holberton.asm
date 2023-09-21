section .data
	message db 'Hello, Holberton', 0x0A, 0

section .text
	global main

	extern printf

main:
	sub rsp, 8      ; allocate space for two 4-byte arguments on the stack
	lea rdi, [message]  ; load address of message into rdi, first argument for printf
	xor eax, eax    ; zero out eax register
	call printf     ; call printf function
	add rsp, 8      ; deallocate stack space

	xor eax, eax    ; zero out eax register
	ret             ; return from main function
