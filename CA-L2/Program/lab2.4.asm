        .data                           # Start from 0x10010000
        .globl var1                     # $gp diff: -0x7fd0
var1:   .word 0x02                      # Inital value: 2
        .globl var2                     # $gp diff: -0x7ffc
var2:   .word 0x05                      # Inital value: 5
        .extern ext1 4                  # $gp diff: -0x7ff8
ext1:   .word 0x08                      # Inital value: 8
        .extern ext2 4                  # $gp diff: -0x7ff4
ext2:   .word 0x05                      # Inital value: 5
        .text
        .globl main
main:   addu $s0, $ra, $0               # save return address
# load initial word of vars
        lw $t0, var1                    # Load data to $t0
        lw $t1, var2                    # Laod data to $t1
# store words from vars to exts
        sw $t1, ext1            # Store the data of var2($t1) to the address of ext1 
        sw $t0, ext2            # Store the data of var1($t0) to the address of ext2 
# restore the return address in $ra and return from main
        addu $ra, $0, $s0       # load the return address
        jr $ra                  # return from main