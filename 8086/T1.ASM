code segment
        assume cs:code
start:
       mov bx,0001h
       mov ah,00h
       int 21h
       mov bx,0002h
       hlt
code ends
end start
