bits 32
global start

extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

; Se da un fisier cu mai multe propozitii. Sa se afiseze propozitiile nr de cuv, primul cuvant invers, nr de litere primul cuv.
segment data use32 class=data
    file_name db "5.txt", 0
    acces_mode db "r", 0
    file_descriptor dd -1

    len equ 100
    text times (len + 1) db 0

    prop_counter dd 0
    word_counter dd 0
    letter_counter dd 0

    propozitie times (len + 1) db 0
    first_word times 20 db 0
    reversed_word times 20 db 0
    
    format db "Propozitia %d: %s Nr cuvinte: %d, Primul cuvant %s are %d litere", 13, 10, 0


segment code use32 class=code
    start:
        push dword acces_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2

        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4 * 4

    main_loop:
        mov esi, text
        mov edi, propozitie
        xor ebx, ebx

    prop:
        lodsb
        stosb

        cmp al, " "
        jne jos

        inc ebx
    jos:
        cmp al, "."
        je next

        jmp prop

    next:
        mov eax, [prop_counter]
        inc eax
        mov [prop_counter], eax

        inc ebx
        mov [word_counter], ebx

        push esi
        push edi

        mov esi, propozitie
        mov edi, first_word
        xor ebx, ebx

        primul_cuvant:
            lodsb
            stosb

            cmp al, " "
            je gasit

            inc ebx
        jmp primul_cuvant

    gasit:
        mov [letter_counter], ebx

        mov esi, first_word
        mov edi, reversed_word

        mov ecx, [letter_counter]
        reverse:
            std
            lodsb

            cld
            stosb
        loop reverse

    gata:
        push dword [letter_counter]
        push dword reversed_word
        push dword [word_counter]
        push dword propozitie
        push dword [prop_counter]
        push dword format
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4 * 7

        pop edi
        pop esi

        jmp main_loop

    final:
        push dword [file_descriptor]
        call [fclose]
        add esp, 4

    eroare:
        push dword 0
        call [exit]