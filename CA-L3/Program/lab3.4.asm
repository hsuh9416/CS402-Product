                .data
                .globl my_array
my_array:       .space 40       # total space: 4 X 10 = 40 
initial_value:  .word 0x08      # initial value 8
                .text
main:   lw $t0, initial_value   # j = initial_value = 8
        li $t1, 0               # i =  0
        li $t2, 10              # MAX = 10
        li $t3, 4               # multiply 4
Loop:   bge $t1, $t2, Exit      # if (i >= 10) goto Exit
        mul $t4, $t3, $t1       # diff from basis = 4 * i
        sw $t0, my_array($t4)   # my_array[i] = j
        addi $t1, $t1, 1        # i <- i + 1
        addi $t0, $t0, 1        # j <- j + 1
        j Loops
Exit:   li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit