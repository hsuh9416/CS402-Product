        .data
msg1:   .asciiz "Please enter the First integer number: "
msg2:   .asciiz "Please enter the Second integer number: "
msg3:   .asciiz "The largest number is: "
msg4:   .asciiz "\n"

        .text
        .globl main
main:    
        # Save return address
        add $sp, $sp, -16
        sw $ra, 16($sp)        
        
        # Read the first number
        li $v0, 4              
        la $a0, msg1            
        syscall             
        li $v0, 5               
        syscall                  
        sw $v0, 12($sp)

        # Read the second number   
        li $v0, 4              
        la $a0, msg2            
        syscall   
        li $v0, 5               
        syscall 
        sw $v0, 8($sp)

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
        lw $ra, 16($sp)         
        add $sp, $sp, 16
        jr $ra    

Largest:    
        # Pop and restore the numbers
        lw $t0, 12($sp)  
        lw $t1, 8($sp)
        
        # Number compare then return the largest
        bge $t0, $t1, First    
        j Second                
First:  
        sw $t0, 4($sp)          
        jr $ra                 
Second: 
        sw $t1, 4($sp)          
        jr $ra                  
