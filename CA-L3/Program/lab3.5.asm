                .data
msg1:           .asciiz "Please enter the first integer number: "
msg2:           .asciiz "Please enter the second integer number: "
msg_far:        .asciiz "I'm far away\n"
msg_near:       .asciiz "I'm nearby\n" 

                .text
main:   li $v0, 4               # print string
        la $a0, msg1            # load msg1 to $a0 for print
        syscall                 # execute
        
        li $v0, 5               # read user input - int
        syscall                 # execute
        
        addu $t0, $v0, $0       # load first number to $t0

        li $v0, 4               # print string 
        la $a0, msg2            # load msg2 to $a0 for print
        syscall                 # execute

        li $v0, 5               # read user input - int
        syscall                 # execute

        addu $t1, $v0, $0       # load second number to $t1

        bne $t0, $t1, Near      # if ($t0 != $t1) goto Near 
        # beq $0, $0, Far       # command occurs error with wrong address
        j Far                   # unconditionally jumps to the Far label
        
Near:   li $v0, 4               # print string 
        la $a0, msg_near        # load msg_near to $a0 for print
        syscall                 # execute     
        
        j Exit                  # uncontitionally jumps to the exit label

        .space 32768            # Add 32 KiB of space to make 'Far' label as far away

Far:    li $v0, 4               # print sprint
        la $a0, msg_far         # load msg_far to $a0 for print
        syscall     

Exit:   li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit