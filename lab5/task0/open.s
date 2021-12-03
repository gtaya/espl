section .text
	global open

open:
	push ebp
	mov ebp, esp
	sub esp, 4		;leave space for local var on stack
	pushad			;save some more caller state
	mov eax, 5		;eax = sys_open
   	mov ebx, [ebp+8]	;ebx = filename
   	mov ecx, 0		;for read only access
	int 0x80		;transfer control to OS
	mov [ebp-4], eax	;save return value
	popad			;restore caller state
	mov eax, [ebp-4]	;place return value where caller can see it
	add esp, 4		;restore caller state
	pop ebp			;restore caller state
	ret
