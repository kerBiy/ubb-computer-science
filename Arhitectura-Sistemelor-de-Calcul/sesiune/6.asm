bits 32

global start        

extern exit, printf             
import exit msvcrt.dll    
import printf msvcrt.dll

segment data use32 class=data
    src dd -1, 123456, 0xabcdeff, 0xabcdeff, 0xcbcdeff, 0xdbcdeff, 0111010101b
    len equ ($ - src) / 4
    dst times (len + 1) db 0
    
    secventa times (len + 1) dd 0
    count dd 0
    
    print_foramt db "%x ", 0
    new_line db 10, 13, 0
    first_index dd 0
    last_element dd 0
    
    sum_functie db 0

segment code use32 class=code
    functie:
        ; [ESP + 0] - adresa de revenire
        ; [ESP + 4] - sirul sursa
        ; [ESP + 8] - sirul destinatie
        ; [ESP + 12] - lungimea sirului sursa
        mov esi, [esp + 4]
        mov edi, [esp + 8]
        mov ecx, [esp + 12]
        
        itereaza_peste_elemente:
            lodsd ; incarcam dublucuvantul actual
            mov byte [sum_functie], 0
            
            sum_cifre_hexa:
                ; cifra inferioara
                mov bl, al
                and bl, 0Fh
                add [sum_functie], bl
                
                ; cifra superioara
                mov bl, al
                shr bl, 4
                add [sum_functie], bl
                
                ; next step
                shr eax, 8 ; mergem la urmatori 8 biti
                   
                cmp eax, 0
                jne sum_cifre_hexa
            
            mov al, [sum_functie]
            stosb ; punem suma in sirul destinatie
        loop itereaza_peste_elemente
        
        ret 4 * 3

    start:
        push dword len
        push dword dst
        push dword src
        call functie
        
        mov esi, 0 ; act as i
        mov ecx, len
        dec ecx
        
        loop1:
            push ecx
            
            ; setam ultimul element
            mov eax, [dst + esi]
            mov [last_element], eax
            
            mov dword [count], 1
            mov eax, [src + esi]
            mov [secventa], eax
            
            ; j = i + 1
            mov edi, esi
            add edi, 4
            
            mov ecx, len
            loop2:
                push ecx
                
                mov eax, [dst + edi] ; current element
                cmp dword [last_element], eax
                jae afisare
                
                ; punem in secventa kakaul
                mov edx, [count]
                
                mov eax, [src + edi]
                mov [secventa + 4 * edx], eax
                
                mov eax, [dst + edi]
                mov [last_element], eax
                
                add edi, 4
                add dword [count], 1
                
                pop ecx
            loop loop2
            
        afisare:
            cmp dword [count], 1
            je nu_afisa
            
            mov ebx, 0
            
            mov ecx, [count]
            afis:
                push ecx
                
                mov eax, [secventa + ebx] 
                inc ebx
                
                push eax
                push dword print_foramt
                call [printf]
                add esp, 4 * 2
                
                pop ecx
            loop afis
            
            push dword new_line
            call [printf]
            add esp, 4
            
            
        nu_afisa:
            pop ecx
            add esi, 4
        cmp ecx, 0
        jne loop1
        
        

        push dword 0     
        call [exit]       
