bits 32 
global  start 

extern  exit, fopen, scanf, fprintf, fclose
import  exit msvcrt.dll
import  fopen msvcrt.dll
import  scanf msvcrt.dll
import  fprintf msvcrt.dll
import  fclose msvcrt.dll

; Sa se citeasca de la tastatura un nr n, apoi sa se citeasca mai multe cuvinte, pana cand se citeste #. Se se scrie intr-un fisier cuvintele care au cel putin n vocale.
segment data use32 class=data 
    nume_fisier db "nush.txt", 0
    descriptor_fisier dd 0
    mod_acces db "a", 0

    n dd 0
    cuvant times 20 db 0

    format_citire_n db "%d", 0
    format_citire db "%s", 0
    format_afisare db "%s ", 0

segment code use32 class=code 
    start: 
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2

        cmp eax, 0
        je eroare
        mov [descriptor_fisier], eax
        
        push dword n
        push dword format_citire_n
        call [scanf]
        add esp, 4 * 2

        main_loop:
            push dword cuvant
            push dword format_citire
            call [scanf]
            add esp, 4 * 2
            
            cmp byte [cuvant], "#"
            je final

            mov esi, cuvant
            xor ebx, ebx

            repeta:
                lodsb

                cmp al, 'a'
                je vocala
                cmp al, 'e'
                je vocala
                cmp al, 'i'
                je vocala
                cmp al, 'o'
                je vocala
                cmp al, 'u'
                je vocala

                dec ebx
            vocala:
                inc ebx
            jmp repeta

            cmp ebx, [n]
            jb nu_afisa

            push dword cuvant
            push dword format_afisare
            push dword descriptor_fiseier
            call [fprintf]
            add esp, 4 * 3

            nu_afisa:
        jmp main_loop

    final: 
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
    eroare:
        push dword 0
        call [exit] 