bits 32 
global start 

extern exit 
import exit msvcrt.dll

; Citim un n de la tastatura, apoi n dublucuvinte, Se cere sa se stocheze in memorie toate n dublucuvintele, apoi sa se formeze un nou sir de octeti, in care stocam suma cifrelor pare din fiecare dublucuvant citit
segment data use32 class=data 
    n dd 0

    len equ 100
    input_list times (len + 1) dd 0
    
    double_word dd 0
    ten dd 10

    output_list times (len + 1) db 0

    read_format "%d", 0
    print_format "%d", 0

segment code use32 class=code 
    start: 
        push dword n
        push dword read_format
        call [scanf]
        add esp, 4 * 2

        mov edi, input_list
        mov ecx, [n]

        get_input:
            push ecx

            push dword double_word
            push dword read_format
            call [scanf]
            add esp, 4 * 2

            mov eax, [double_word]
            stosd

            pop ecx
        loop get_input
        
        mov esi, input_list
        mov edi, output_list
        mov ecx, [n]

        main_loop:
            push ecx
            lodsd
            xor ebx, ebx

            while_loop:
                xor edx, edx
                div dword [zece]

                test edx, 1
                jnz not_even

                add ebx, edx
            not_even:
                cmp eax, 0
                je next

            jmp while_loop

            next: 
           
            mov eax, ebx
            stosb

            push dword ebx
            push dword print_format
            call [printf]
            add esp, 4 * 2

            pop ecx
        loop main_loop

        push dword 0
        call [exit] 