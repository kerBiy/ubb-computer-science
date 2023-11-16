bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile pare din S2 cu elementele de pe pozitiile impare din S1.
segment data use32 class=data 
    s1 db 'a', 'b', 'c', 'd', 'e', 'f'
    s2 db '1', '2', '3', '4', '5'
    len1 equ $-s
    len2 equ sir1-s
    d times (len1 + len2) db 0
segment code use32 class=code 
    start: 
        mov edi, 0 ; initializam iteratorul pe d

        mov ecx, len2 ; punem lungimea lui s2 in ecx
        mov esi, 0 ; initializam iteratorul pe s2
        jecxz Sfarsit

        RepetaLista2:
            mov al, [s2 + esi] ; punem s2[esi] in al
            mov [d + edi], al ; il punem in d
            add esi, 2 ; incrementam cu 2
            dec ecx ; facem ecs -= 2 pt ca mergem din 2 in 2 pasi

        loop RepetaLista2

        mov ecx, len1 ; punem lungimea lui s1 in ecx
        mov esi, 1 ; initializam iteratorul pe s1
        jecxz Sfarsit

        RepetaLista1:
            mov al, [s1 + esi] ; punem s2[esi] in al
            mov [d + edi], al ; il punem in d
            add esi, 2 ; incrementam cu 2
            dec ecx ; facem ecs -= 2 pt ca mergem din 2 in 2 pasi

        loop RepetaLista1

       
    Sfarsit:

        push dword 0
        call [exit] 