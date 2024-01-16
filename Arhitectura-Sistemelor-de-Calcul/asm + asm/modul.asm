%ifndef _MODUL_ASM_
%define _MODUL_ASM_

binaryToDecimal: 
    mov esi, [esp + 4] ; luam param de pe stiva
    mov edi, esi
    sub edi, 1 ; initializam edi cu ptr inainte de primul element

    get_last_elem:
        cmp byte [esi + 1], 0 ; conditia de oprire
        je next

        inc esi ; iteram pana la finalul sirului
    jmp get_last_elem

    next:
        xor ebx, ebx
        xor edx, edx
        mov edx, 1 ; in edx vom calcula puterile lui 2
        std ; inversam directia de iterare

        repeta:
            lodsb ; AL = '1' sau '0'
            cmp al, '0' ; vedem daca e '0'
            je not_one

            ; daca e 1:
            add ebx, edx ; add two power

        not_one:
            shl edx, 1 ; edx = edx * 2

            cmp esi, edi ; vedem daca am iterat peste toaote elementele
            je final

        jmp repeta
    
    final:
        mov eax, ebx ; returnam rezultatul in eax
        ret

%endif