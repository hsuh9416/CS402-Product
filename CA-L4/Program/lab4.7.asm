        .data
msgD:   .asciiz "Please enter the two non-negative integers!\n"
msg1:   .asciiz "[Enter]The first non-negative integer: "
msg2:   .asciiz "[Enter]The second non-negative integer: "
mgsE:   .asciiz "You have entered a negative integer! Please try again.\n"
msgR:   .asciiz "Result of Ackermann operation = "
ln:     .asciiz "\n"    # Line break
        .globl cnt            
cnt:    .word 0         # Counter for recursive calls
        .text
        .globl main
main:   
        # Save return address
        add $sp, $sp, -4      # Reserve the space for stack (current: -4)
        sw $ra, 4($sp)        # Store the return address at -(4~0)

        # Set recursive call counter
        lw $t4, cnt            # init counter

        # Promt the direction message
        li $v0, 4              
        la $a0, msgD            
        syscall                

        # Promt the direction message for first integer
        li $v0, 4              
        la $a0, msg1            
        syscall      

        # Read the first integer       
        li $v0, 5               
        syscall                 
        
        # Check the negativity
        bltz $v0, Error       # if ($v0 < 0) goto Error  
        addu $t0, $v0, $0     # else load $v0 to $t0

        # Promt the direction message for Second integer
        li $v0, 4              
        la $a0, msg2            
        syscall     

        # Read the second integer           
        li $v0, 5              
        syscall  

        # Check the negativity
        bltz $v0, Error       # if ($v0 < 0) goto Error
        addu $t1, $v0, $0     # else load $v0 to $t1
        
        # Start Ackermann
        jal Ackermann
        nop

        # Promt the message for result       
        li $v0, 4              
        la $a0, msgR            
        syscall

        # Promt the Ackermann operation result 
        li $v0, 1              
        move $a0, $t3                     
        syscall

        # Promt the line break   
        li $v0, 4              
        la $a0, ln            
        syscall
       
        # Save the call counter
        sw $t4, cnt            # cnt <- $t4

        # Restore address and stack point then exit
        lw $ra, 4($sp)          # Retrieve the return address    
        add $sp, $sp, 4         # Restore the stack point (Resource release) (current: 0)
        jr $ra                  # Return from main
Error:                          # Warning & Loop again
        # Promt the error message
        li $v0, 4              
        la $a0, mgsE            
        syscall

        jal main                # Restart loop
Ackermann:                      
        # Initialize and save the address
        add $sp, $sp, -12       # Reserve the space for stack (current: -16)
        sw $ra, 12($sp)         # Store the return address at -(8-4)    
        sw $s0, 8($sp)          # Store the temporal first integer at -(12-8)   
        sw $s1, 4($sp)          # Store the temporal second integer at -(16-12)

        addi $t4, $t4, 1        # Increase the counter: cnt <- cnt + 1

        # Condition check for if x = 0 then y+1
        bne $t0, $0, Branch1    # if( $t0 != 0) goto Branch1
        add $t3, $t1, 1         # if( $t0 == 0) $t3 <- $t1 + 1 (result <- y + 1)

        j Complete              # Goto Complete               
Branch1:                            # For x != 0
        # Condition check for else if y = 0 then A(x-1, 1)
        bne $t1, $0, Branch2    # if( $t1 != 0) goto Branch2
        sub $t0, $t0, 1         # $t0 <- $t0 - 1 (x <- x-1)
        add $t1, $0, 1          # $t1 <- 0 + 1   (y <- 1)
        jal Ackermann           # Ackermann($t0, $t1) = A($t0 - 1, 1) (result <- A(x-1, 1))

        j Complete
Branch2:                        # For y != 0
        # Condition check for else A(x-1, A(x, y-1))
        sub $t1, $t1, 1         # $t1 <- $s1 - 1 (y <- y-1)
        move $s0, $t0           # $s0 <- $t0 (copy x to preserve the value)
        jal Ackermann           # Ackermann($t0, $t1) = A(x, y-1) (result <- A(x, y - 1))

        sub $t0, $s0, 1         # $t0 <- $s1 - 1 (x <- x -1) (use preserved x in $s0)
        move $t1, $t3           # $t1 <- A($t0, $t1 - 1) (y <- result = A(x, y - 1))
        jal Ackermann           # Ackermann($t0, $t1) = A($t0 - 1, A($t0, $t1 - 1)) (result <- A(x-1, A(x, y-1)))
Complete:
        # Restore address, variables and stack point then return
        lw $ra, 12($sp)         # Retrieve the return address    
        lw $s0, 8($sp)          # Retrieve the temporal first integer
        lw $s1, 4($sp)          # Retrieve the temporal second integer
        add $sp, $sp, 12        # Restore the stack point (Resource release) (current: -4)
        jr $ra                 # return by the saved address