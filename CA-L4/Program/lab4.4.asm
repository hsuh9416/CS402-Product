        .data
msg1:   .asciiz "Please enter the First integer number: "
msg2:   .asciiz "Please enter the Second integer number: "
msg3:   .asciiz "The largest number is: "
msg4:   .asciiz "\n"

        .text
        .globl main
main:    
        # Save return address
        add $sp, $sp, -4        # sp 0 -> -4
        sw $ra, 4($sp)        
        
        # Read the first number
        li $v0, 4              
        la $a0, msg1            
        syscall             
        li $v0, 5               
        syscall     
        add $sp, $sp, -4        # sp -4 -> -8             
        sw $v0, 4($sp)

        # Read the second number   
        li $v0, 4              
        la $a0, msg2            
        syscall   
        li $v0, 5               
        syscall 
        add $sp, $sp, -4        # sp -8 -> -12   
        sw $v0, 4($sp)

        # Call 'Largest'
        jal Largest             
        nop

        # Print out the result
        li $v0, 4              
        la $a0, msg3            
        syscall
        li $v0, 1            
        lw $a0, 4($sp)
        syscall
        li $v0, 4              
        la $a0, msg4            
        syscall

        # Restore return address and return from the main
        lw $ra, 8($sp)         
        add $sp, $sp, 8        # sp -8 -> 0
        jr $ra    

Largest:    
        # Pop and restore the numbers
        lw $t1, 4($sp)
        lw $t0, 8($sp)  
        add $sp, $sp, 4        # sp -12 -> -8 (Reseved one stack for the result value)
        
        
        # Number compare then return the largest
        bge $t0, $t1, First    
        j Second                
First:  
        sw $t0, 4($sp)          
        jr $ra                 
Second: 
        sw $t1, 4($sp)          
        jr $ra                  
