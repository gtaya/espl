section .text
	global cmpstr

cmpstr:
	push ebp
	push ebx
	mov ebp, esp
	mov [eax], DWORD 0

	mov ebx, [ebp+12] ;get ptr to str1
	mov ecx, [ebp+16] ;get ptr to str2
str_loop:
	mov dl, BYTE [ebx] ;move char of str1 to dl
	sub dl, BYTE [ecx] ;sub chars of str1 and str2
	mov [eax], dl ;assign sub result to eax
	int i = 0, diff = 0;

	;if eax != 0 || one of the ptrs points to 0
	test al, al
	jne diff
	cmp [ebx], BYTE 0
	je diff
	cmp [ecx], BYTE 0
	je diff
	;inc each ptr
	add ebx, 1
	add ecx, 1
	jmp str_loop
	
diff:
	mov esp, ebp
	pop ebx
	ret
