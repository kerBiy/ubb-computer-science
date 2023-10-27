bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

segment data use32 class=data 
    a dd 125
	b db 2
	c dw 15
	d db 200
	e dq 80

; (d - c) + (b - a) - (b + b + b)
segment code use32 class=code 
start: 
	
	
	push dword 0
	call [exit] 