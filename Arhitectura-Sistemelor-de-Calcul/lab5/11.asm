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
        mov ecx, len // punem lungimea in ecx
        mov esi, 0 // initializam iteratorul pe s
        mov ebx, 0 // initializam iteratorul pe d1
        mov edx, 0 // initializam iteratorul pe d2

        jecxz Sfarsit // metoda anti-prost

        Repeta:
            mov al, [s+esi] // punem s[esi] in al
            mov ah, 0 // ax <- al

            push ax // il retinem pe stiva pt a il folosi mai incolo

            mov bl, 2
            div bl // impartim numarul la 2

            cmp ah, 0 // verificam restul impartirii
            je par: // daca e zero tratam cazul par

            // daca numarul este impar
            pop byte [d2 + edx]
            inc edx
            
            jmp final

        par:
            // daca numarul este par
            pop byte [d1 + ebx]
            inc ebx

        final:
            inc esi

        loop Repeta

    Sfarsit:

        push dword 0
        call [exit] 