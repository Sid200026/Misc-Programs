; data segment
;        x db ?
; data ends
code segment
        assume cs:code
start:
;        mov ax,data
;        mov ds,ax
        mov ah,01h
        int 21h
        hlt
code ends
end start
