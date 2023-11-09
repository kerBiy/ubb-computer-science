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
    c dw 1011_0110_0101_1010b
    d db 0
    ; d = 01101 + 11110 = 101011b = 2Bh = 43
    ; e = 01101b = Dh
    f db 0
    ; f = d - f = 2Bh - Dh = ?h

segment code use32 class=code 
    start: 
        mov bl, 0 ; aici voi pune bitii 0-4 a lui a
        mov dl, 0 ; aici voi pune bitii 5-9 a lui b

        mov ax, [a]
        and ax, 001Fh ; aplicam masca pt a btine bitii
        or bl, al ; punem bitii in rezultat

        mov ax, [b]
        and ax, 03E0h ; aplicam masca
        mov cl, 5 ; punem in cl 5 pt a aduce elem de pe 5 pe 0
        ror ax, cl ; rotim 5 pozitii la dreapta
        or dl, al ; punem bitii in rezultat

        add bl, dl ; adunam bitii pentru a afla valoarea din d
        mov [d], bl

        mov dl, 0 ; aici voi pune valoarea lui e
        mov ax, [c]
        and ax, 7C00h ; aplicam masca de bitii
        mov cl, 10 ; pentru a aduce bitii de pe 10 pe 0
        ror ax, cl ; rotim 10 poztii la dreapta
        or dl, al ; punem bitii in rezultat

        sub bl, dl ; scadem d - e
        mov [f], bl ; punem rezultatul in f

        push dword 0
        call [exit] 