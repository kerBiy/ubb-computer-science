bits 32

global start        

extern exit, printf            
import exit msvcrt.dll 
import printf msvcrt.dll   

segment data use32 class=data
    string dd 1234A678h, 12345678h, 1AC3B47Dh, 0xFEDC9876
    len equ ($ - string) / 4
    
    max db 0
    ranks times (len + 1) db 0
    sum db 0
    
    print_format db "%x ", 0
    new_line db 10, 13, 0
    print_sum_format db "%d", 0
    
segment code use32 class=code
    function:
        ; [ESP + 0] - adresa de revenire
        ; [ESP + 4] - adresa sirului de dublucuvinte
        ; [ESP + 12] - lungimea sirului
        ; [ESP + 8] - adresa sirului ranks
        
        mov esi, [esp + 4]
        mov edi, [esp + 8]
        mov ecx, [esp + 12]
        
        cat_timp:
            xor ebx, ebx
            mov byte [max], 0
            
            repeta:
                mov al, [esi + ebx]
                cmp al, [max]
                jb mai_mic
                
                mov [max], al
                
                mai_mic:
                
                inc ebx
                cmp ebx, 4
                jne repeta
            
            mov al, [max]
            add [sum], al
            stosb
            add esi, 4
        
        loop cat_timp
        
        mov al, [sum]
        mov byte [sum], 0
        
        ret

    start:
        push dword len
        push dword ranks
        push dword string
        call function
        add esp, 4 * 3
        
        mov [sum], al
        
        mov ecx, len
        mov esi, ranks
        
        itereaza:
            push ecx
            
            movzx eax, byte [esi]
            
            push dword eax
            push dword print_format
            call [printf]
            add esp, 4 * 2
            
            inc esi
            
            pop ecx
        loop itereaza
        
        push dword new_line
        call [printf]
        add esp, 4
        
        movsx eax, byte [sum]
        push dword eax
        push dword print_sum_format
        call [printf]
        add esp, 4 * 2

        push dword 0     
        call [exit]       
