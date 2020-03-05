data segment
        output  db 20h
                db 10 dup('$')
        opdata db "Output is :$"
data ends
code segment
        assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        mov ah,0Ah
        mov dx, offset output
        int 21h
        lea dx,opdata
        mov ah,09h
        int 21h
        lea dx,output
        mov ah,09h
        int 21h
        mov ah,4Ch
        int 21h
        hlt
code ends
end start
