bits 32
global start        
extern exit  , printf, scanf
import exit msvcrt.dll    
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    cuvant dd 0
    format_citire db "%s"
    nume_fisier db "output.txt", 0
    mod_acces db "a", 0                    
    descriptor_fisier dd -1    
    
segment code use32 class=code
    start:
        ; apelam fopen pentru a crea fisierul
        ; functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2                ; eliberam parametrii de pe stiva

        mov [descriptor_fisier], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final

        repeta:
            ;citire o val pentru x
            push dword cuvant
            push dword format_citire
            call [scanf]
            add esp, 4*2
            
            mov al, [cuvant]
            
            ; verificam daca s-a introdus $ de la tastatura
            cmp al, '$'
            je close

            push dword cuvant
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*2

            jmp repeta
        
    close: 
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4*1

    final:
        push dword 0      
        call [exit]
