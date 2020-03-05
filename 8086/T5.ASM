code segment
        assume cs:code
start:
        mov ah,06h
        mov dl,41h
        int 21h
        mov dl,09h
        int 21h
        mov dl,42h
        int 21h
        mov dl,0FFh; acts as input
        int 21h
        mov ah,al
        hlt
code ends
end start
