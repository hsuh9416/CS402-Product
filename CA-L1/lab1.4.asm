        .data 0x10000000        # msg1 will be saved to this address.
msg1:   .asciiz "Please enter a double number: "
output: .double 0.0
        .text                   # Switches to the text section, where the program's executable code is located.
        .globl main             # Declares the main label as a global symbol, indicating that it's the entry point of the program.

main:   addu $s0, $ra, $0       # S0 = ra => Save the return address to $s0
        li $v0, 4               # system call for print_string 
        la $a0, msg1            # a0 = the massage loaded from msg1
        syscall             

        li $v0, 6               # system call for read_double => read user input
        syscall                 

        s.d $f0, output        # Store input data to output  

        li $v0, 3               # system call for print_double
        l.d $f12, output        # $f12 = output = $f0
        syscall

        addu $ra, $0, $s0       # ra = s0
        jr $ra                  # return to $s0 => Exiting main