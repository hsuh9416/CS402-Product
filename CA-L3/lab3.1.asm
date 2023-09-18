        .data
        .globl var1
var1:   .word 0x0008   
        .globl var2           
var2:   .word 0x0007
        .globl var3
var3:   .word -0x07E7
        .text
main:   lw $t0, var1            # $t0 <- Memory[var1]
        lw $t1, var2            # $t1 <- Memory[var2]
        lw $t2, var3            # $t2 <- Memory[var3]
        beq $t0, $t1, If        # if (var1 == var2) goto If:
        beq $0, $0, Else        # else goto Else:
If:     sw $t2, var1            # $t0 = Memory[var1] <- $t2 = Memory[var3]
        sw $t2, var2            # $t1 = Memory[var2] <- $t2 = Memory[var3]
Else:   sw $t1, var1            # $t0 = Memory[var1] <- $t1 = Memory[var2]
        sw $t0, var2            # $t1 = Memory[var2] <- $t0 = Memory[var1]
Exit:
        li $v0, 10                      # Set code 10(exit)
        syscall                         # Syscall to exit