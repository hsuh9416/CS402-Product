        .data
        .globl var1
var1:   .word 0x0008   
        .text
main:   lw $a0, var1            # $t1 <- $a0
        li $a1, 100             # $a1 <- 100
Loop:   ble $a1, $a0, Exit      # if ($a1 <= $a0) goto Exit
        addi $a0, $a0, 1        # $a0 <- $a0 + 1
        j Loop
Exit:   sw $a0, var1            # var1 <- $a0
        li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit
