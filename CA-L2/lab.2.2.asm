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
# load initial word of vars
        lw $t0, var1            # $t0 = Memory[var1]     
        lw $t1, var2            # $t1 = Memory[var2]     
        lw $t2, var3            # $t2 = Memory[var3]      
        lw $t3, var4            # $t3 = Memory[var4] 
        lb $t4, first           # $t4 = Memory[first]
        lb $t5, last            # $t5 = Memory[last]
# swap values between vars
        sw $t3, var1            # Memory[var1] = $t3 = Memory[var4]
        sw $t2, var2            # Memory[var2] = $t2 = Memory[var3]
        sw $t1, var3            # Memory[var3] = $t1 = Memory[var2]
        sw $t0, var4            # Memory[var4] = $t0 = Memory[var1]
# restore now the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main