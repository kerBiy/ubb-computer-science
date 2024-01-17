bits 32
global start

extern exit, fopen, fclose, scanf, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll

; Se citesc nr in baza 10 de la tastatura pana la citirea nr 0. In fisier se scrie fiecare nr in baza 10, 16 si nr de biti de 1
segment data use32 class=data
    file_name db "4.txt", 0
    acces_mode db "w", 0
    file_descriptor dd -1

    number dd 0

    read_format db "%d", 0
    print_format db "%d = %xh si are %d biti de 1", 10, 13, 0

segment code use32 class=code
    start:
        push dword acces_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2

    main_loop:
        push dword number
        push dword read_foramt
        call [scanf]
        add esp, 4 * 2

        cmp dword [number], 0
        je final

        mov eax, [number]
        xor ebx, ebx
        mov ecx, 32

        how_many_ones:
            shl eax, 1
            adc ebx, 0
        loop how_many_ones

        push dword ebx
        push dword [number]
        push dword [number]
        push dword print_format
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4 * 5

        jmp main_loop

    final:
        push dword [file_descriptor]
        call [fclose]
        add esp, 4

    eroare:
        push dword 0
        call [exit]

