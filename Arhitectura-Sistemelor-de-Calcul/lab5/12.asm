bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile pare din S2 cu elementele de pe pozitiile impare din S1.
segment data use32 class=data 
    s1 db 'a', 'b', 'c', 'd', 'e', 'f'
    len1 equ $ - s
    s2 db '1', '2', '3', '4', '5'
    len2 equ 5
    d times len1 + len2 db 0
segment code use32 class=code 
    start: 
        mov edi, 0 ; initializam iteratorul pe d

        mov ecx, len2 ; punem lungimea lui s2 in ecx
        mov esi, 0 ; initializam iteratorul pe s2
        jecxz Sfarsit

        RepetaLista2:
            mov eax, esi ; punem index ul in eax pt al prelucra
            mov bl, 2
            div bl ; impartim index ul la 2 pentru ai observa paritatea

            cmp ah, 0 ; comparam restul cu 0
            jne continua2  ; daca nu este egal (nu e par) continuam

            mov dl, [s2 + esi] ; punem s2[esi] in dl
            mov [d + edi], dl ; il punem in d
            inc edi
        
        continua2:
            inc esi

        loop RepetaLista2

        mov ecx, len1 ; punem lungimea lui s1 in ecx
        mov esi, 0 ; initializam iteratorul pe s1
        jecxz Sfarsit

        RepetaLista1:
            mov eax, esi ; punem index ul in eax pt al prelucra
            mov bl, 2
            div bl ; impartim index ul la 2 pentru ai observa paritatea

            cmp ah, 0 ; comparam restul cu 0
            je continua1 ; daca este egal (e par) continuam

            mov dl, [s1 + esi] ; punem s1[esi] in dl
            mov [d + edi], dl ; il punem in d
            inc edi
        
        continua1:
            inc esi

        loop RepetaLista1

       
    Sfarsit:

        push dword 0
        call [exit] 