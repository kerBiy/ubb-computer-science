bits 32 
global start 

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data 
    sir dd 1234A678h, 12785634h, 1A4D3C25h
    len equ ($ - sir) / 4

    new_sir times len dw 0
    sum dd 0
    
    print_format db "%d", 0

segment code use32 class=code 
    start: 
        mov esi, sir
        mov edi, new_sir

        mov ecx, len
        main_loop:
            lodsd
            mov bl, ah

            shr eax, 16

            mov al, bl
            stosw
        loop main_loop

        mov esi, new_sir
        mov ecx, len
        xor ebx, ebx

        second_loop:
            lodsw
            nr_biti:
                shl ax, 1
                adc ebx, 0

                cmp ax, 0
                je next
            jmp nr_biti
            next:
        loop second_loop
        
        mov [sum], ebx
        
        push dword [sum]
        push dword print_format
        call [printf]
        add esp, 4 * 2

        push dword 0
        call [exit] 