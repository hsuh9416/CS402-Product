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
 
        bltz $v0, Error         # if ($v0 < 0) goto Error    
        
        move $t0, $v0           # Else store value to the $t0

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

        # Restore address and stack point then exit
        lw $ra, 4($sp)
        add $sp, $sp, 4
        jr $ra                  # Return from main
Error:                          # Warning & Loop again
        li $v0, 4              
        la $a0, err1            
        syscall

        jal main                # Restart loop
Factorial:                      # Recursive Factorial function
        subu $sp, $sp, 4
        sw $ra, 4($sp)          # save the return address on stack
        
        beqz $t0, terminate     # test for termination
        
        subu $sp, $sp, 4        # do not terminate yet
        sw $t0, 4($sp)          # save the parameter
        
        sub $t0, $t0, 1         # will call with a smaller argument
        
        jal Factorial           # Recursion

# after the termination condition is reached these lines will be executed
        lw $t0, 4($sp)          # the argument I have saved on stack
        mul $t1, $t1, $t0       # do the multiplication
        
        lw $ra, 8($sp)          # prepare to return
        addu $sp, $sp, 8        # I’ve popped 2 words (an address and
        jr $ra                  # .. an argument)
terminate:                      # breakpoint: 0x004000a4
        li $t1, 1               # 0! = 1 is the return value
        lw $ra, 4($sp)          # get the return address
        addu $sp, $sp, 4        # adjust the stack pointer

        jr $ra                  # return