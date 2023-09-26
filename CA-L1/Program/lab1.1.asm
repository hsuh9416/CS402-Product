        .data 0x10000000        # msg1 will be saved to this address.
msg1:   .asciiz "Please enter an integer number: "

        .text                   # Switches to the text section, where the program's executable code is located.
        .globl main             # Declares the main label as a global symbol, indicating that it's the entry point of the program.

main:   addu $s0, $ra, $0       # S0 = ra => Save the return address to $s0
        li $v0, 4               # system call for print_string 
        la $a0, msg1            # a0 = the massage loaded from msg1
        syscall             

        li $v0, 5               # system call for read_int => read user input
        syscall                 

        addu $t0, $v0, $0       # t0 = v0 = 5 => load read input. e.i. t0 = $(USER_DEFINE)
        sll $t0, $t0, 7         # t0 = t0 >> 7

        li $v0, 1               # system call for print_int
        addu $a0, $t0, $0       # a0 = t0 = the value loaded from t0
        syscall

        addu $ra, $0, $s0       # ra = s0
        jr $ra                  # return to $s0 => Exiting main