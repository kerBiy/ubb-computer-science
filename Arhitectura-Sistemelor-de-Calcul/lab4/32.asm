bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

;Se dau cuvintele A, B si C. Sa se obtina octetul D ca suma a numerelor reprezentate de:
;biţii de pe poziţiile 0-4 ai lui A
;biţii de pe poziţiile 5-9 ai lui B
;Octetul E este numarul reprezentat de bitii 10-14 ai lui C. Sa se obtina octetul F ca rezultatul scaderii D-E.

segment data use32 class=data 
    a dw 1001_0010_1010_1101b 
    b dw 0100_0111_1100_0100b
    c dw 1111_0110_0101_1010b
    d db 0
    ; d = 01101 + 11110 = 101011b = 2Bh = 43
    ; e = 
    f db 0

segment code use32 class=code 
    start: 
        mov bl, 0
        mov dl, 0

        mov ax, [a]
        and ax, 001Fh
        or bl, al
        mov ax, [b]
        and ax, 03E0h
        or dl, al

        add bl, dl
        mov [d], bl

        push dword 0
        call [exit] 