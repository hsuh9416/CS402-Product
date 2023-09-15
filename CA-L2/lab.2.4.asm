        .data 0x10000000       # Start from 0x10000000
        .globl var1
var1:   .word 87             # Inital value
        .globl var2
var2:   .word 08             # Inital value
        .extern
        .globl ext1
ext1:   .word 
        .extern
        .globl ext2
ext2:   .word 
        .text
        .globl main
main:   addu $s0, $ra, $0       # save $31 in $16

# restore now the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main