bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se da dublucuvantul A. Sa se obtina numarul intreg n reprezentat de bitii 14-17 ai lui A. Sa se obtina apoi in B dublucuvantul rezultat prin rotirea spre stanga a lui A cu n pozitii. Sa se obtina apoi octet C astfel:
; - bitii 0-5 ai lui C coincid cu bitii 1-6 ai lui B
; - bitii 6-7 ai lui C coincid cu bitii 17-18 ai lui B

segment data use32 class=data 
    a dd 10100010_11111001_00110100_10111110b ; A2F9_34BEh
    c db 0
    ; n = 0010b = 2
    ; b = 10001011_11100100_11010010_11111010b
    ; c <- 00010101b

segment code use32 class=code 
    start: 
        mov bl, 0 ; in registrul bx vom calcula rezultatul

        ; izolam bitii 14-17 ai lui a
        mov eax, [a]
        mov cl, 14
        ror eax, cl ; rotim 14 pozitii spre dreapta
        
        ; punem in cl valoarea bitilor 14-17 a lui a
        and eax, 0000000Fh
        mov cl, al

        ; aflam b ul prin rotirea lui a la stanga de 2 ori
        mov eax, [a]
        rol eax, cl

        push eax ; il punem pe b pe stiva 

        ; izolam bitii 1-6 ai lui b
        and eax, 0000007Eh
        mov cl, 1
        ror eax, cl ; rotim 1 pozitie spre dreapta
        or bl, al ; punem bitii in rezultat

        ; izolam bitii 17-18 a lui b
        pop eax ; il recuperam pe b
        and eax, 00060000h
        mov cl, 11 ; vrem ca bitii 17-18 sa ajunga pe 6-7
        ror eax, cl ; rotim 11 pozitii spre dreapta
        or bl, al ; punem bitii in rezultat

        mov [c], bl

        push dword 0
        call [exit] 