        .data
msg1:   .asciiz "Please enter the First integer number: "
msg2:   .asciiz "Please enter the Second integer number: "
msg3:   .asciiz "The largest number is: "
msg4:   .asciiz "\n"

        .text
        .globl main
main:    
        # Save return address
        move $s0, $ra      
        
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
        move $a0, $s1
        syscall
        li $v0, 4              
        la $a0, msg4            
        syscall

        # Restore return address and return from the main
        move $ra, $s0         
        jr $ra          

Largest:             
        # Number compare then return the largest
        bge $t0, $t1, First
        j Second                 
First:  
        move $s1, $t0
        jr $ra                  
Second: 
        move $s1, $t1
        jr $ra                   
