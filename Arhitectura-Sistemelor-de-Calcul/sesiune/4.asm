bits 32

global start        

extern exit              
import exit msvcrt.dll    

segment data use32 class=data
    sir dq 1110111b, 100000000h, 0ABCD0002E7FCh, 5
    len equ ($ - sir) / 8
    rez times (len + 1) dd 0
    
    copy_ax dw 0
    copy_dx dw 0
    copy_ecx dd 0
    
    count db 0
    sum db 0

segment code use32 class=code
    start:
        mov esi, sir
        mov edi, rez
        mov ecx, len
        
        repeta:
            lodsd ; punem doubleul inferior
            
            mov [copy_ax], ax
            mov [copy_dx], dx
            mov [copy_ecx], ecx
            
            jmp verifica
            
            gata_verificarea:
            
            cmp byte [count], 2
            jb nu_este
            
            ; este bun
            mov ax, [copy_ax]
            mov dx, [copy_dx]
            stosd
            
            nu_este:
            
            mov ecx, [copy_ecx]
            lodsd ; trecem peste
            add byte [count], 1
            
        loop repeta
        
        
    verifica:
        mov ecx, 16
        mov byte [sum], 0
        mov byte [count], 0
        
        cat_timp1:
            shr ax, 1
            mov bh, byte [sum]
            adc byte [sum], 0
            
            cmp bh, [sum]
            je nu_continuu
            jmp este_continuu
            
            nu_continuu: mov byte [sum], 0
            
            este_continuu:
            
            cmp byte [sum], 3
            jne nu_am_gasit
            
            ; am gasit
            mov byte [sum], 0
            add byte [count], 1
            
            nu_am_gasit:
            
        loop cat_timp1
        
        cat_timp2:
            shr dx, 1
            mov bh, byte [sum]
            adc byte [sum], 0
            
            cmp bh, [sum]
            je nu_continuu_2
            jmp este_continuu_2
            
            nu_continuu_2: mov byte [sum], 0
            
            este_continuu_2:
            
            cmp byte [sum], 3
            jne nu_am_gasit_2
            
            ; am gasit
            mov byte [sum], 0
            add byte [count], 1
            
            nu_am_gasit_2:
            
        loop cat_timp2
        jmp gata_verificarea
    
    final:
        push dword 0     
        call [exit]       
