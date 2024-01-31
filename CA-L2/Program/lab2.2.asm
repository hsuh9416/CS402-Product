        .data 0x10000000       # Start from 0x10000000
        .globl var1
var1:   .word 0x01             # Inital value
        .globl var2
var2:   .word 0x02             # Inital value
        .globl var3
var3:   .word 0x03             # Inital value
        .globl var4
var4:   .word 0x04             # Inital value
# Byte stores from the lower digit to higher digit.
# That is, 0x12105348 instead of 0x48531012
# Regarding this fact, lui/ori will prevent to stack backword and store the data as its order.
        .globl first
first:  .byte 0x48              # First letter of first name: 'H'
        .globl last
last:   .byte 0x53              # First letter of last name: 'S'
# first2:  .byte 0x10              # First letter of first name: 'H'
# last2:   .byte 0x12              # First letter of last name: 'S'
        .text
        .globl main
main:   addu $s0, $ra, $0       # save return address
# load initial word of vars
        lw $t0, var1            # $t0 <- Store a value of var1 to $t0    
        lw $t1, var2            # $t1 <- Store a value of var2 to $t1         
        lw $t2, var3            # $t2 <- Store a value of var3 to $t2      
        lw $t3, var4            # $t3 <- Store a value of var4 to $t3 
        lb $t4, first           # $t4 <- Store a value of first to $t4 
        lb $t5, last            # $t5 <- Store a value of last to $t5 
#        lb $t6, first2          # $t4 <- Store a value of first2 to $t6 
#       lb $t7, last2           # $t5 <- Store a value of last2 to $t7 
# swap values between vars
        sw $t3, var1            # Address of var1 <- Save the $t3's value to var1
        sw $t2, var2            # Address of var2 <- Save the $t3's value to var1
        sw $t1, var3            # Address of var3 <- Save the $t3's value to var1
        sw $t0, var4            # Address of var4 <- Save the $t3's value to var1
# restore the return address in $ra and return from main
        addu $ra, $0, $s0       # load the return address
        jr $ra                  # return from main