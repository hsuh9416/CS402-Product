        .data                           # Start from default(0x10010000)
        .globl var1                     
var1:   .word 0x02                      # Inital value: 2
        .globl var2                     
var2:   .word 0x05                      # Inital value: 5
        .data 0x10000000                # Start from different address(0x10000000)
        .extern ext1 4                  # $gp diff: -0x7ff8
ext1:   .word 0x08                      # Inital value: 8
        .extern ext2 4                  # $gp diff: -0x7ff4
ext2:   .word 0x05                      # Inital value: 5
        .text
        .globl main
main:   addu $s0, $ra, $0               # save return address
# load the data
        lw $t0, var1                    # Load the data from var1 to $t0
        lw $t1, var2                    # Load the data from var2 to $t1
# copy from vars to exts
        sw $t1, ext1                    # Load the data from $t1(var2) to ext1
        sw $t0, ext2                    # Load the data from $t0(var1) to ext2
# restore the return address in $ra and return from main
        addu $ra, $0, $s0       # load the return address
        jr $ra                  # return from main
