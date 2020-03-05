data segment
        message db "Enter character : $"
        x db ?
data ends
code segment
        assume cs:code, ds:data
start:
        mov ax,data
        mov ds,ax
        lea dx,message
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        mov x,al
        mov ah,4Ch
        int 21h
        hlt
code ends
end start

