        .data
msg1:   .asciiz "Please enter the non-negative integer: "
msg2:   .asciiz "The result of Factorial is:"
msg3:   .asciiz "\n" 
err1:   .asciiz "You entered the negative number, please try again. \n"

        .text
        .globl main
main:  
        # Save return address
        add $sp, $sp, -4
        sw $ra, 4($sp)      
        
        # Read the number
        li $v0, 4              
        la $a0, msg1            
        syscall             
        li $v0, 5               
        syscall     
 

        bltz $v0, Error         # if ($v0 < 0) goto Error => Warning & Loop again      
        
        move $t0, $v0           # Else store value to the $t0
        li $t1, 1               # Initialize the result variable
        jal Factorial           # Start Factorial
        nop                     # execute this after 'Factorial' returns

        # Print output
        li $v0, 4              
        la $a0, msg2            
        syscall
        li $v0, 1              
        move $a0, $t1            
        syscall
        li $v0, 4              
        la $a0, msg3            
        syscall

        lw $ra, 4($sp)
        add $sp, $sp, 4         # shrink the stack by one word
        jr $ra                  # return from main
Error:  
        li $v0, 4              
        la $a0, err1            
        syscall

        jal main        
Factorial:     
        add $sp, $sp, -4
        sw $ra, 4($sp)   
        blez $t0, Base         # if ($t0 <= 0) => goto Base
        mul $t1, $t1, $t0 
        sub $t0, $t0, 1         # $t0 - 1     
        jal Factorial
        lw $ra, 4($sp)
        add $sp, $sp, 4         # shrink the stack by one word      
        jr $ra
Base: 
        lw $ra, 4($sp)
        add $sp, $sp, 4         # shrink the stack by one word
        jr $ra