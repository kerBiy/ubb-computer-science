bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; (a + b) / (2 - b*b + b/c) - x
segment data use32 class=data 
    a dd 1
	b db 2
	c db 5
	x dq 10
	; exp = ?

segment code use32 class=code 
start: 
	; (a + b)
	mov al, [b]
    cbw
    cwde
	add eax, [a]

	; mutam eax pe stiva (pt al lua in DX:AX)
	push eax

	; b * b
	mov bl, [b]
	mul bl
	mov bx, ax

	; b / c
	mov al, [b]
	cbw
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
	cwde
	cdq

	; (a + b) / (2 - b*b + b/c) - x
	sub eax, [x]
	sbb edx, [x + 4]

	push dword 0
	call [exit] 