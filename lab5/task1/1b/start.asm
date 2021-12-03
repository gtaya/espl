section .bss
	s1 resb 20		;destination

section .text
	
global _start
global read
global write
global open
global close
global strlen
global utoa_s

extern main
_start:
	;getting cmd arguments
	mov eax, [esp]		;argc
	mov ebx, esp		;argv @esp+4
	add ebx, 4

	push ebx
	push eax
	
	call main
    	mov ebx, eax
	mov eax, 1
	int 0x80

read:	
	push ebp
	mov ebp, esp
	sub esp, 4		;leave space for local var on stack
	pushad			;save some more caller state
	mov eax, 3		;eax = sys_read
   	mov ebx, [ebp+8]	;ebx = fildes
   	mov ecx, [ebp+12]	;ecx = pointer to input buffer
   	mov edx, [ebp+16]	;edx = buffer size, max. count of bytes to receive
	int 0x80		;transfer control to OS
	mov [ebp-4], eax	;save return value
	popad			;restore caller state
	mov eax, [ebp-4]	;place return value where caller can see it
	add esp, 4		;restore caller state
	pop ebp			;restore caller state
	ret

write:
	push ebp
	mov ebp, esp
	sub esp, 4		;leave space for local var on stack
	pushad			;save some more caller state
	mov eax, 4		;eax = sys_write
   	mov ebx, [ebp+8]	;ebx = fildes
   	mov ecx, [ebp+12]	;pointer to output buffer
   	mov edx, [ebp+16]	;count of bytes to send
	int 0x80		;transfer control to OS
	mov [ebp-4], eax	;save return value
	popad			;restore caller state
	mov eax, [ebp-4]	;place return value where caller can see it
	add esp, 4		;restore caller state
	pop ebp			;restore caller state
	ret

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
close:
	push ebp
	mov ebp, esp
	sub esp, 4		;leave space for local var on stack
	pushad			;save some more caller state
	mov eax, 6		;eax = sys_close
   	mov ebx, [ebp+8]	;ebx = fildes
	int 0x80		;transfer control to OS
	mov [ebp-4], eax	;save return value
	popad			;restore caller state
	mov eax, [ebp-4]	;place return value where caller can see it
	add esp, 4		;restore caller state
	pop ebp			;restore caller state
	ret

strlen:
	push	ebp
	push	ebx
	mov	ebp, esp
	mov eax, -1
.loop:
	add eax, 1
	mov ebx, eax
	add ebx, [ebp+12]
	movzx	ebx, BYTE [ebx]
	test bl,bl
	jne .loop
	mov esp, ebp
	pop ebx
	pop ebp
	ret

utoa_s:
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]
	mov edi, s1		;move pointer to destintation buffer to edi
	mov ecx, 10		;devide by 10
	xor ebx, ebx		;clear ebx, use as counter for stack pushes

push_chars:
	xor edx, edx		;clear edx
	div ecx			;devide edx by ecx, result in eax, remainder in edx
	add edx, 0x30		;convert int => ascii
	push edx		;push result to stack
	add ebx, 1		;increment my stack push counter
	test eax, eax
	jnz push_chars		;if eax not 0, repeat

pop_chars:
	pop eax			;pop result from stack into eax
	stosb			;store contents of eax in at the address of num which is in EDI
	sub ebx, 1		;decrement my stack push counter
	cmp ebx, 0		;check if stack push counter is 0
	jg pop_chars		;not 0 repeat
	mov eax, 0x0a
	stosb			;add line feed

	mov eax, [edi]	
	mov esp, ebp
	pop ebp
	ret
