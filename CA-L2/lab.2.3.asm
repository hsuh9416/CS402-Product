        .data 0x10000000        # Start from 0x10000000
        .globl var1
var1:   .word 0x01              # Inital value
        .globl var2
var2:   .word 0x02              # Inital value
        .globl var3
var3:   .word 0x03              # Inital value
        .globl var4
var4:   .word 0x04              # Inital value
        .globl first
first:  .byte 0x48              # First letter of first name: 'H'
        .globl last
last:   .byte 0x53              # First letter of last name: 'S'
        .text
        .globl main
main:   
# load address of basis
        lui $t0, 0x1000         # load upper address
        ori $t0, $t0, 0x0000    # load lower address
# load initial word of vars
        lw $t1, 0($t0)          # var1      
        lw $t2, 4($t0)          # var2      
        lw $t3, 8($t0)          # var3      
        lw $t4, 12($t0)         # var4
        lb $t5, 16($t0)         # first
        lb $t6, 17($t0)         # last
# swap values between vars
        sw $t4, 0($t0)          # var4 <- var1
        sw $t3, 4($t0)          # var3 <- var2
        sw $t2, 8($t0)         # var2 <- var3
        sw $t1, 12($t0)         # val1 <- var4
# Exit - End of the program
        ori $v0, $0, 10         # SET code 10
        syscall                 # Syscall to exit
