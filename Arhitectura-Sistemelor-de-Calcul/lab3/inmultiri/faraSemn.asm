bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; (a + b) / (2 - b*b + b/c) - x
segment data use32 class=data 
    a dd 12
	b db 1
	c db 1
	x dq 5
	; exp = 1

segment code use32 class=code 
start: 
	; (a + b)
	mov eax, 0
	mov al, [b]
	add eax, [a]

	; mutam eax pe stiva (pt al lua in DX:AX)
	push eax

	; b * b
	mov bl, [b]
	mul bl
	mov bx, ax

	; b / c
	mov al, [b]
	mov ah, 0
	mov cl, [c]
	div cl
	add ax, 2

	; (2 - b*b + b/c)
	sub ax, bx
	mov bx, ax

	pop dx
	pop ax

	; (a + b) / (2 - b*b + b/c)
	div bx
	mov bx, ax
	mov eax, 0
	mov ax, bx
	mov edx, 0

	; (a + b) / (2 - b*b + b/c) - x
	sub eax, [x]
	sbb edx, [x + 4]

	push dword 0
	call [exit] 