bits 32 
global start 

; Se citeste de la tastatura un sir de mai multe numere in baza 2. Sa se afiseze aceste numere in baza 16.

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

%include "modul.asm"

segment data use32 class=data 
    ; read_msg_n "Introduceti numarul de numere in baza 2: ", 0
    ; format_n "%d", 0
    binary_number times 100 db 0
    n db 2

    read_msg "Introduceti numarul in baza 2: ", 0
    format_binary "%s", 0

    output_msg "Numarul in baza 16: %x", 10, 13, 0

segment code use32 class=code 
    start: 
        mov ecx, [n]
        cld

        main_loop:
            push dword read_msg
            call [printf]
            add esp, 4

            push dword binary_number
            push dword format_binary
            call [scanf]
            add esp, 4*2

            push dword binary_number
            call binaryToDecimal

            push eax
            push dword output_msg
            call [printf]
            add esp, 4*2


        loop main_loop
        

        push dword 0
        call [exit] 