bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se dau un octet A si un cuvant B. Sa se obtina un octet C care are pe bitii 0-3 bitii 2-5 ai lui A, iar pe bitii 4-7 bitii 6-9 ai lui B

segment data use32 class=data 
    a db 10111011b
    b dw 1001010110101100b
    c db 0
    ; c <- 11100110b

segment code use32 class=code 
    start: 
        mov bl, 0 ; in registrul bx vom calcula rezultatul

        ; izolam bitii 2-5 ai lui a
        mov al, [a]
        and al, 00111100b
        mov cl, 2
        ror al, cl ; rotim 2 pozitii spre dreapta
        or bl, al ; punem bitii in rezultat

        ; izolam bitii 6-9 ai lui b
        mov ax, [b]
        and ax, 0000001111000000b
        ror ax, cl ; rotim 2 pozitii spre dreapta
        or bl, al ; punem bitii in rezultat

        mov [c], bl

        push dword 0
        call [exit] 