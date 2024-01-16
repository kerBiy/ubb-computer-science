bits 32 
global  start 

extern  exit, fopen, fscanf, printf, fclose, feof
import  exit msvcrt.dll
import  fopen msvcrt.dll
import  fclose msvcrt.dll
import  fscanf msvcrt.dll
import  printf msvcrt.dll
imort  feof msvcrt.dll

; Un fisier contine cifre in baza 16 separate prin spatiu. Sa se afiseze fiecare cifra citita si numarul ei de biti de 1.
segment data use32 class=data 
    digit db 0

    file_name db "input.txt", 0
    acces_mode db "r", 0
    file_descriptor dd 0

    read_format db "%c", 0
    print_format db "%c -> %d", 0

segment code use32 class=code 
    start: 
        push dword acces_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2

        cmp eax, 0
        je eroare
        mov [file_descriptor], eax

    main_loop:
        push dword digit
        push dword read_format
        push dword file_descriptor
        call [fsacnf]
        add esp, 4 * 3

        push dword file_descriptor
        call [feof]
        add esp, 4

        cmp eax, 0
        je final

        cmp byte [digit], '0'
        jb not_digit
        cmp byte [digit], '9'
        ja not_digit
            
        mov eax, 0
        mov al, [digit]
        sub al, '0'
        jmp counting

        not_digit:
            mov eax, 0
            mov al, [digit]
            sub al, 'a'
            add al, 10

        counting:
            xor ebx, ebx
            mov ecx, 32

            mini_loop:
                shl eax, 1
                adc ebx, 0
            loop mini_loop

            push ebx
            push dword digit
            push dword print_format
            call [printf]
            add esp, 4 * 3

        jmp main_loop

    final:
        push dword file_descriptor
        call [fclose]
        add esp, 4
        
    eroare:
        push dword 0
        call [exit] 