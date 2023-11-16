bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se da un sir de octeti S. Sa se obtina sirul D1 ce contine toate numerele pare din S si sirul D2 ce contine toate numerele impare din S.
segment data use32 class=data 
    s db 1, 5, 3, 8, 2, 9
    len equ $-s
    d1 times len db 0
    d2 times len db 0
segment code use32 class=code 
    start: 
        mov ecx, len ; punem lungimea in ecx
        mov esi, 0 ; initializam iteratorul pe s
        mov edi, 0 ; initializam iteratorul pe d1
        mov edx, 0 ; initializam iteratorul pe d2

        jecxz Sfarsit ; metoda anti-prost

        Repeta:
            mov al, [s + esi] ; punem s[esi] in al
            mov ah, 0 ; ax <- al

            push ax ; il retinem pe stiva pt a il folosi mai incolo

            mov bl, 2
            div bl ; impartim numarul la 2

            cmp ah, 0 ; verificam restul impartirii
            je par ; daca e zero tratam cazul par

            ; daca numarul este impar
            pop ax ; il reluam de pe stiva
            mov [d2 + edx], al ; punem in al doilea sir elementul impar
            inc edx
            
            jmp continua

        par:
            ; daca numarul este par
            pop ax ; il reluam de pe stiva
            mov [d1 + edi], al ; punem in primul sir elementul par
            inc edi

        continua:
            inc esi ; incrementam pentru a trece la uramtorul element

        loop Repeta

    Sfarsit:

        push dword 0
        call [exit] 