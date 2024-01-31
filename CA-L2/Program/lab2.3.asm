        .data 0x10000000        # Start from 0x10000000
        .globl var1
var1:   .word 0x02              # Inital value: 2
        .globl var2
var2:   .word 0x05              # Inital value: 5
        .globl var3
var3:   .word 0x08              # Inital value: 8
        .globl var4
var4:   .word 0x05              # Inital value: 5
        .globl first
first:  .byte 'h'              # First letter of first name: 'h'
        .globl last
last:   .byte 's'              # First letter of last name: 's'
        .text
        .globl main
main:   addu $s0, $ra, $0       # save return address
# load address of basis
        lui $t0, 0x1000         # load upper address of basis
        ori $t0, $t0, 0x0000    # load lower address of basis
# load initial word of vars by relative location of each variables.
        lw $t1, 0($t0)          # $t1 <- Store a value of var1 to $t1     
        lw $t2, 4($t0)          # $t2 <- Store a value of var2 to $t2     
        lw $t3, 8($t0)          # $t3 <- Store a value of var3 to $t3      
        lw $t4, 12($t0)         # $t4 <- Store a value of var4 to $t4 
        lb $t5, 16($t0)         # $t5 <- Store a value of first to $t5 
        lb $t6, 17($t0)         # $t6 <- Store a value of last to $t6 
# swap values between vars
        sw $t4, 0($t0)            # Address of var1 <- Save the $t3's value to var1
        sw $t3, 4($t0)            # Address of var2 <- Save the $t3's value to var1
        sw $t2, 8($t0)            # Address of var3 <- Save the $t3's value to var1
        sw $t1, 12($t0)           # Address of var4 <- Save the $t3's value to var1
# restore the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main
        ori $v0, $0, 10         # SET code 10
        syscall                 # Syscall to exit
