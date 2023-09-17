                .data
                .globl my_array
my_array:       .space 10
initial_value:  .word 0x08
                .text
main:   lw $t0, initial_value   # j = initial_value
        li $t1, 0               # i =  0
        li $t2, 10              # MAX = 10
        li $t3, 4               # multiply 4
Loop:   bge $t1, $t2, Exit      # if (i >= 10) goto Exit
        mul $t4, $t3, $t1       # diff = 4 * i
        sw $t0, my_array($t4)   # my_array = j
        addi $t1, $t1, 1        # i++;
        addi $t0, $t0, 1        # j++;
        j Loop
Exit:   li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit