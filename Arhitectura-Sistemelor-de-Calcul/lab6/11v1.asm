bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se da un sir A de dublucuvinte. Construiti doua siruri de octeti  
;  - B1: contine ca elemente partea superioara a cuvintelor superioare din A
;  - B2: contine ca elemente partea inferioara a cuvintelor inferioare din A
segment data use32 class=data 
    sir  dw  10abcb0h, 051ad2h, 74120ca1h
	len equ ($ - sir) / 4 ; lungimea sirului
    b1 times len db 0 ; 01, 00, 74
    b2 times len db 0 ; b0, d2, a1

segment code use32 class=code 
    start: 
        mov ecx, len ; punem lungimea in ecx
        mov esi, 0 ; initializam iteratorul pe s
        mov edi, 0 ; intiializam iteratorul pe b1 si b2
        
        jecxz Sfarsit ; metoda anti-prost

        Repeta: 
            mov eax, [sir + esi] ; punem s[esi] in eax
            mov [b2 + edi], al ; partea inf a cuv inf

            shr eax, 24 ; rotim pana la partea sup din cuv sup
            mov [b1 + edi], al ; si il punem in b1
           
            inc edi
            add esi, 4 ; incrementam pentru a trece la uramtorul element

        loop Repeta

    Sfarsit:

        push dword 0
        call [exit] 