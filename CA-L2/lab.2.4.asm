        .data 0x10000000                # Start from 0x10000000
        .globl var1                     # $gp diff: -0x7fd0
var1:   .word 0x87                      # First two digits of SSN
        .globl var2                     # $gp diff: -0x7ffc
var2:   .word 0x08                      # Next two digits of SSN
        .extern ext1 4                  # $gp diff: -0x7ff8
ext1:   .word 0
        .extern ext2 4                  # $gp diff: -0x7ff4
ext2:   .word 0
        .text
main:  
# load initial word of vars
        lw $t0, -0x7fd0($gp)            # $t0 = Memory[var1]
        lw $t1, -0x7ffc($gp)            # $t1 = Memory[var2]
# store words from vars to exts
        sw $t1, -0x7ff8($gp)            # Memory[$t1]  = Memory[var2] = ext1
        sw $t0, -0x7ff4($gp)            # Memory[$t0]  = Memory[var1] = ext2
# Exit
        li $v0, 10                      # Set code 10(exit)
        syscall                         # Syscall to exit