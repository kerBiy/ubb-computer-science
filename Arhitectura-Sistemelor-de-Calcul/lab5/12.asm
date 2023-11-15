bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll

; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile pare din S2 cu elementele de pe pozitiile impare din S1.
segment data use32 class=data 
    s1 db 'a', 'b', 'c', 'd', 'e', 'f'
    len1 equ $-s
    s2 db '1', '2', '3', '4', '5'
    len2 equ len1-s
    d times len1 db 0
segment code use32 class=code 
    start: 
       
    Sfarsit:

        push dword 0
        call [exit] 