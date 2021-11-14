%define X 'B'
%define STR string2

section .rodata
    print_format db '"%c" appears in "%s" %d times', 10, 0
    string1 db 'ABBA', 0
    string2 db 'BBA', 0
    string3 db 'BB', 0
    string4 db '', 0
section .bss
    strlen: resd 1
section .text
    global _start
    extern printf
	
_start:
    call get_STR_Length
    mov [strlen], eax
    push dword strlen ; push length as third argument
    call count_chars    ; run code for counting char in the string
    print:    
    sub  esp, 4 ; allocate stack space for printf result
    push eax; argument 4 to printf
    push STR; argument 3 to printf
    push X; argument 2 to printf
    push print_format ; argument 1 to printf
    call printf

exit:
    mov ebx, 0
    mov eax, 1
    int 80h

get_STR_Length:
	push	ebp
	mov	ebp,	esp	; setup a stack frame
	mov	eax,	STR	; store address of STR into eax 
	jmp	get_STR_Length_loop2
	get_STR_Length_loop:
	add	eax,	1	; next character
	get_STR_Length_loop2:
	cmp	[eax],	byte 0		; is char at 0
	jnz	get_STR_Length_loop
	sub	eax, STR		; get STR length
	mov esp, ebp
	pop ebp			; restore the stack back to how it was
	ret			; returns from func with length in eax



count_chars:
    push ebp
    mov ebp, esp
    sub esp, 4 ; allocate 4 bytes for counting occurences 
    ;compare currbyte to X - if same count ++ , currindex ++,
    ; compare currbyte to 0, if same  jump to end
    mov ecx, STR ; copy string start into ecx
    mov edx, [ebp+8] ; copy length into edx
    mov [ebp-4], dword 0 ;put 0 in counter
    iter_STR:    
    cmp [ecx], byte X ; compare curr byte to X
    jnz continue
    add [ebp-4], dword 1 ;add 1 to counter
    continue:
    sub [edx], dword 1 ;decrease length of word left
    add ecx, 1 ; advance str byte by one
    cmp [edx], dword 0 ;check if word has ended
    jg iter_STR
    mov eax, [ebp-4]
    mov esp, ebp
    pop ebp         ; restore the stack back to how it was
    ret   	    ; return with num of chars in eax	
