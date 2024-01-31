        .data 0x10010000        # 0($1)
var1:   .word 0x55              # var1 is a word (32 bit).
                                # initial value 0x55 at 0($1)
var2:   .word 0xaa              # initial value 0xaa at 4($1)
        .text
        .globl main
main:   addu $s0, $ra, $0       # save return address

        li $t0, 7               # X = 7
        move $t1, $t0           # register copy(not real move!): t0 -> t1
        la $t2, var2            # load address to resiger (resiger, address)
        lw $t3, var2            # load word to register (resiger, data)
        sw $t2, var1            # store word from resiger to the address (data, address)

# restore the return address in $ra and return from main
        addu $ra, $0, $s0       # load the return address
        jr $ra                  # return from main