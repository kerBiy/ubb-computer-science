bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; (d - c) + (b - a) - (b + b + b)
segment data use32 class=data 
    a db 1
	b dw 2
	c dd 5
	d dq 10
	; exp = 0

segment code use32 class=code 
start: 
	; ecx:ebx <- d - c
	mov ecx, [d]
	mov ebx, [d + 4]

	mov eax, [c]
	mov edx, 0

	sub ebx, eax
	sbb ecx, edx

	; reset de eax for the last step
	mov eax, 0

	; ax <- b - a	
	mov ax, [b]
	mov dl, [a]
	mov dh, 0
	sub ax, dx

	; dx <- b + b + b
	mov dx, [b]
	add dx, [b]
	add dx, [b]

	; ax <- (b - a) - (b + b + b)
	sub ax, dx

	; ecx:ebx <- (d - c) + (b - a) - (b + b + b)
	mov edx, 0
	add ebx, eax
	adc ecx, edx

	; edx:eax <- ecx:ebx
	push ecx
	push ebx
	pop eax
	pop edx

	push dword 0
	call [exit] 