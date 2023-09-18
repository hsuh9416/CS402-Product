                .data
msg1:           .asciiz "Please enter the fisrt integer number: "
msg2:           .asciiz "Please enter the second integer number: "
msg_far:        .asciiz "I'm far away\n"
msg_near:       .asciiz "I'm nearby\n" 

                .text
main:   li $v0, 4               # system call for print_string 
        la $a0, msg1            # a0 = the massage loaded from msg1
        syscall             
        
        li $v0, 5               # system call for read_int => read user input
        syscall                 
        
        addu $t0, $v0, $0       # t0 = v0 = first_number

        li $v0, 4               # system call for print_string 
        la $a0, msg2            # a0 = the massage loaded from msg2
        syscall             

        li $v0, 5               # system call for read_int => read user input
        syscall  

        addu $t1, $v0, $0       # t1 = v0 = second_number

        bne $t0, $t1, Near
        # beq $0, $0, Far       # This command occurs error with wrong address.
        j Far                   # To reach out to Far properly, Unconditionally jumps to the Far label
        
Near:   li $v0, 4               # system call for print_string 
        la $a0, msg_near        # a0 = the massage loaded from msg_near
        syscall     
        j Exit
        .space 32768            # Add 32 KB of space to make 'Far' label far away
Far:    li $v0, 4               # system call for print_string 
        la $a0, msg_far         # a0 = the massage loaded from msg_far
        syscall     

Exit:   li $v0, 10              # Set code 10(exit)
        syscall                 # Syscall to exit