        .data
msg1:   .asciiz "Please enter the First integer number: "
msg2:   .asciiz "Please enter the Second integer number: "
msg3:   .asciiz "The largest number is: "
msg4:   .asciiz "\n"

        .text
        .globl main
main:    
        # Save return address
        add $sp, $sp, -4
        sw $ra, 4($sp)        
        
        # Read the first number
        li $v0, 4              
        la $a0, msg1            
        syscall             
        li $v0, 5               
        syscall                 
        move $t0, $v0

        # Read the second number  
        li $v0, 4              
        la $a0, msg2            
        syscall    
        li $v0, 5               
        syscall 
        move $t1, $v0

        # Call 'Largest'
        jal Largest             
        nop

        # Print out the result
        li $v0, 4              
        la $a0, msg3            
        syscall
        li $v0, 1                
        move $a0, $s0
        syscall
        li $v0, 4              
        la $a0, msg4            
        syscall

        # Restore return address and return from the main
        lw $ra, 4($sp)         
        add $sp, $sp, 4
        jr $ra          

Largest:             
        # Number compare then return the largest
        bge $t0, $t1, First
        j Second                 
First:  
        move $s0, $t0
        jr $ra                  
Second: 
        move $s0, $t1
        jr $ra                   
