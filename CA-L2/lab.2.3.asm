        .data 0x10000000       # Start from 0x10000000
        .globl var1
var1:   .word 0x01             # Inital value
        .globl var2
var2:   .word 0x02             # Inital value
        .globl var3
var3:   .word 0x03             # Inital value
        .globl var4
var4:   .word 0x04             # Inital value
        .globl first
first:  .byte 0x48              # First letter of first name: 'H'
        .globl last
last:   .byte 0x53              # First letter of last name: 'S'

        .text
        .globl main
main:   addu $s0, $ra, $0       # save $31 in $16

        lw $t2, var1            # load initial word of var1      
        lw $t3, var2            # load initial word of var2      
        lw $t4, var3            # load initial word of var3      
        lw $t5, var4            # load initial word of var4

# breakpoint to 0x00400048 => Step 8
        sw $t5, var1            # store initial word of var4 as var1
        sw $t4, var2            # store initial word of var3 as var2
        sw $t3, var3            # store initial word of var2 as var3
        sw $t2, var4            # store initial word of val1 as var4

# restore now the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main