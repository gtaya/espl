section .text
	global cmpstr

cmpstr:
	push ebp
	push ebx
	mov ebp, esp
	mov ecx, -1	;initiate str index

str_loop:
	add ecx, 1		;increment index
	mov eax, ecx
	mov ebx, ecx	
	add eax, [ebp+12]	;get ptr to char1
	movzx eax, BYTE [eax]	;replace ptr with char1 val
	add ebx, [ebp+16]	;get ptr to char2 
	movzx ebx, BYTE [ebx]	;replace ptr with char2 val
	
	test al, al	;check if str1 reached its' end
	je diff
	test bl, bl	;check if str2 reached its' end
	je diff

	cmp eax, ebx	;compare char1 and char2
	jne diff	;if ZF is not set, we found a difference
	jmp str_loop	;else, continue to the next chars	
	
diff:
	sub eax, ebx	;subtract char1 - char2 and store diff in eax
	jmp exit

exit:
	mov esp, ebp
	pop ebx
	pop ebp
	ret

