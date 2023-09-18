        .data
        .globl var1
var1:   .word 0x0008   
        .text
main:   lw $a0, var1            # $t1 <- $a0
        li $a1, 100             # $a1 <- 100
        move $t0, $a0           # i is in $a0, $t0 <-$a0
Loop:   blt $a1, $t0, Exit      # if ($a1 < $t0) goto Exit
        addi $a0, $a0, 1        # $a0 <- $a0 + 1
        addi $t0, $t0, 1        # $t0  <- $t0 + 1
        j Loop
Exit:   sw $a0, var1            # var1 <- $a0
        li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit