bits 32 
global start 

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

; Fisier cu mesaj ascuns. Codificat cu 2 poz mai la dreapta
segment data use32 class=data 
    file_name db "r1.txt", 0
    acces_mode db "r", 0
    file_descriptor dd -1

    len equ 100
    code times (len + 1) db 0
    text times (len + 1) db 0

segment code use32 class=code 
    start: 
        push dword acces_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2

        cmp eax, 0
        je eroare
        mov [file_descriptor], eax

        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword code
        call [fread]
        add esp, 4 * 4

        cld
        mov esi, code
        mov edi, text

    main_loop:
        lodsb
        
        cmp al, "a"
        jb store
        cmp al, "z"
        ja store

        cmp al, "a"
        je este_a
        cmp al, "b"
        je este_b

        sub al, 4
        jmp store
    
    este_a:
        mov al, "y"
        jmp store
    este_b:
        mov al, "z"

    store:    
        stosb
            
        cmp byte [esi], 0
        je final

        jmp main_loop

    final: 
        push dword text
        push dword format
        call [printf]
        add esp, 4 * 2

        push dword [file_descriptor]
        call [fclose]
        add esp, 4

    eroare:
        push dword 0
        call [exit] 