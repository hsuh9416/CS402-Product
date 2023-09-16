        .data 0x10010000
var1:   .word 0x55              # var1 is a word (32 bit) with the ...
                                # initial value 0x55
var2:   .word 0xaa

        .text
        .globl main
main:   addu $s0, $ra, $0       #save $31 in $16

        li $t0, 7               # X = 7
        move $t1, $t0           # register copy(not move): t0 -> t1
        la $t2, var2            # load address 
        lw $t3, var2            # load word
        sw $t2, var1            # store word

# restore now the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main