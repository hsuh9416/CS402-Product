        .data 0x10000000    # Start from 0x100000000
        .globl var1
var1:   .word 0x87          # First two digits of SSN
        .globl  var2
var2:   .word 0x08          # Next two digits of SSN
        .extern ext1 4
        .extern ext2 4
        .text
        .globl main
main:
# load initial word of vars
        lw $t0, var1   # $t0 = Memory[var1]
        lw $t1, var2   # $t1 = Memory[var2]
# store words from vars to exts
        sw $t1, ext1   # Memory[$t1]  = Memory[var2] = ext1
        sw $t0, ext2   # Memory[$t0]  = Memory[var1] = ext2
# Exit
        li $v0, 10          # Set code 10(exit)
        syscall             # Syscall to exit