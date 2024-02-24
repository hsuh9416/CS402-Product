        .data
msg1:   .asciiz "Please enter the fisrt non-negative integer: "
msg2:   .asciiz "Please enter the second non-negative integer: "
msg3:   .asciiz "Result = "
msg4:   .asciiz "Total number of recursive calls = "
ln:     .asciiz "\n" 
err1:   .asciiz "You entered the negative number, please try again. \n"
        .text
        .globl main
main:   
        # Save return address
        add $sp, $sp, -4
        sw $ra, 4($sp)    

        # Set recursive call counter
        li $t4, -1            # $t4 <- -1 (Exclude the primary call)

        # Read the first number
        li $v0, 4              
        la $a0, msg1            
        syscall             
        li $v0, 5               
        syscall                 
        
        bltz $v0, Error         # if ($v0 < 0) goto Error  
        addu $t0, $v0, $0       # t0 = first_number

        # Read the second number
        li $v0, 4              
        la $a0, msg2           
        syscall             
        li $v0, 5              
        syscall  

        bltz $v0, Error         # if ($v0 < 0) goto Error
        addu $t1, $v0, $0       # t1 = second_number
        
        # Start Ackermann
        jal Ackermann
        nop

        # Print output          
        li $v0, 4              
        la $a0, msg3            
        syscall
        li $v0, 1              
        move $a0, $t3                     
        syscall
        li $v0, 4              
        la $a0, ln            
        syscall
       
        # Print the number of recursive calls
        li $v0, 4              
        la $a0, msg4            
        syscall
        li $v0, 1              
        move $a0, $t4                     
        syscall
        li $v0, 4              
        la $a0, ln            
        syscall

        # Restore address and stack point then exit
        lw $ra, 4($sp)
        add $sp, $sp, 4
        jr $ra                  # Return from main
Error:                          # Warning & Loop again
        li $v0, 4              
        la $a0, err1            
        syscall

        jal main                # Loop again
Ackermann:                      # Breakpoint 0x004000cc  
        # Initialize and save the address
        add $sp, $sp, -12
        sw $ra, 12($sp)         # Return Address    
        sw $s0, 8($sp)          # Temp var 1
        sw $s1, 4($sp)          # Temp var 2

        addu $t4, $t4, 1        # Count the number of recursive calls

        # (X != 0) ? Goto Branch1 : Return Y + 1
        bne $t0, $0, Branch1    # if( $t0 != 0) goto Branch1
        add $t3, $t1, 1         # else $t3 <- $t1 + 1

        j Complete              # Goto Complete               
Branch1:                        # For X != 0
        # (Y != 0) ? Goto Branch2 : Return Ackermann(X-1, 1) 
        bne $t1, $0, Branch2    # if( $t1 != 0) goto Branch2
        sub $t0, $t0, 1         # $t0 <- $t0 - 1 
        add $t1, $0, 1          # $t1 <- 0 + 1   
        jal Ackermann           # Ackermann($t0, $t1) = A($t0 - 1, 1)

        j Complete
Branch2:                        # For Y != 0, Ackermann(X-1, Ackermann(X, Y-1)) 
        sub $t1, $t1, 1         # $t1 <- $s1 - 1
        move $s0, $t0           # $s0 <- $t0 (copy X)
        jal Ackermann           # Ackermann($t0, $t1) = A($t0, $t1 - 1)

        sub $t0, $s0, 1         # $t0 <- $s1 - 1 (Set X -1)
        move $t1, $t3           # $t1 <- A($t0, $t1 - 1)
        jal Ackermann           # Ackermann($t0, $t1) = A($t0 - 1, A($t0, $t1 - 1))

Complete:
        # Restore address, variables and stack point then return
        lw $ra, 12($sp)         # Return Address    
        lw $s0, 8($sp)          # Temp var 1
        lw $s1, 4($sp)          # Temp var 2
        add $sp, $sp, 12         # Restore the stack point
        jal $ra                 # return