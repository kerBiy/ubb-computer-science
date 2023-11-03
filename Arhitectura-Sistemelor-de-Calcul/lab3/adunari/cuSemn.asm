bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; d - (a + b + c) - (a + a)
segment data use32 class=data 
    a db 1
	b dw 2
	c dd 5
	d dq 10
	; exp = 0

segment code use32 class=code 
start: 
	; ax <- a + b
	mov al, [a]
	cbw
	mov bx, [b]
	add ax, bx

	; eax <- a + b + c
	cwde
	add eax, [c]

	; ebx <- eax
	push eax
	pop ebx

	; al <- a + a
	mov al, [a]
	add al, [a]

	; eax <- (a + b + c) - (a + a)
	cbw
	cwde
	sub ebx, eax

	push ebx
	pop eax

	; ecx:ebx <- d - (a + b + c) - (a + a)
	mov ebx, [d]
	mov ecx, [d + 4]

	cdq
	sub ebx, eax
	sbb ecx, edx

	; edx:eax <- ecx:ebx
	push ecx
	push ebx
	pop eax
	pop edx

	push dword 0
	call [exit] 