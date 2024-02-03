bits 32 
global start 

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

; A string of doublewords is given. From each of these doublewords form a new word by taking the higher byte of the higher word and the higher byte of the lower word. All these new obtained words will be stored in a word string. Then compute the number of bits of value 1 from the new formed word string and print it on the screen in base 10. Explain the algorithm, justify and comment accordingly the source code.

; Example: If the string of doublewards is:
; sir dd 1234A678h, 12783634h, 1A4D3C25h,
; then the string of words containing the higher byte of the higher word and the higher byte of the lower word for each doubleword is: 12A6h, 1256h, 1A3Ch and the number of bits 1 from all the words of this string is. 6+6+7=19. The number 19 will be printed on the screen.
segment data use32 class=data 
    sir dd 1234A678h, 12783634h, 1A4D3C25h
    len equ $ - sir

    new_sir times len dw 0
    sum db 0

segment code use32 class=code 
    start: 
        mov esi sir
        mov edi new_sir

        mov ecx, len
        main_loop:
            lodsd
            mov bl, ah

            shr eax, 16

            mov al, bl
            stosw
        loop main_loop

        mov esi new_sir
        mov ecx, len
        xor ebx, ebx

        second_loop:
            lodsw
            nr_biti:
                shl ax, 1
                adc ebx

                cmp ax, 0
                je final
            jmp nr_biti
        loop second_loop
        
        final:
            push ebx
            push dword print_format
            call [printf]
            add esp, 4 * 2

        push dword 0
        call [exit] 