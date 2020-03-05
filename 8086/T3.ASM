data segment
        hi DB "Hello Hi$"
data ends
code segment
        assume cs:code, ds:data
start:
        lea si,hi
        mov ah,09h
        int 21h
        mov ah,4ch
        int 21h
        hlt
code ends
end start
