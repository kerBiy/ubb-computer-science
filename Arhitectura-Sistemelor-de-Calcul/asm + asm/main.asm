bits 32 
global start 

; Se citeste de la tastatura un sir de mai multe numere in baza 2. Sa se afiseze aceste numere in baza 16.

%include "modul.asm"

import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

extern exit, printf, scanf

segment data use32 class=data 
    binary_number times 100 db 0

    read_msg db "Introduceti numarul in baza 2: ", 0
    format_binary db "%s", 0

    output_msg db "Numarul in baza 16: %x", 10, 13, 0

segment code use32 class=code 
    start: 

        repeta_din_nou:
          
            push dword read_msg ; mesajul de citire
            call [printf]
            add esp, 4

            push dword binary_number ; introducem numarul in baza 2 ca un string de '1' si '0'
            push dword format_binary
            call [scanf]
            add esp, 4*2
               
            push dword binary_number ; convertim numarul din binar in decimal
            call binaryToDecimal
            
            cmp byte [binary_number], 'x' ; conditia de iesire din while (cand apasam x)
            je sfarsit

            push eax
            push dword output_msg ; afisam numarul decimal in baza 16
            call [printf]
            add esp, 4*2

        jmp repeta_din_nou
        
        sfarsit:

            push dword 0
            call [exit] 