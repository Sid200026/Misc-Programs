code segment
        assume cs:code
start:
        mov ah,02h
        mov dl,'r'
        int 21h
        mov dl,'o'
        int 21h
        mov dl,0Ah
        int 21h
        mov dl,'s'
        int 21h
        mov dl,79h
        int 21h
        hlt
code ends
end start
