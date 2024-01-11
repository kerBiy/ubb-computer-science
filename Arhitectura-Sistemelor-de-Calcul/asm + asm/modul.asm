%ifndef _MODUL_ASM_
%define _MODUL_ASM_

binaryToDecimal: 
    pop esi
    mov edi, esi

    get_last_elem:
        cmp [esi + 1], 0
        je next

        inc esi
    jmp get_last_elem

    next:
        xor ebx, ebx
        mov edx, 1 ; put ale lui 2
        std

        repeta:
            loadsb ; AL = "1" sau '0'
            cmp al, 0
            je not_one

                ; if is 1
            add ebx, edx ; add two power

        not_one:
        shl edx

        cmp esi, edi
        je final

        jmp repeta
    
    final:
        mov eax, ebx
        ret

%endif