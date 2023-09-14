        .data 0x10010000
var1:   .word 0x01             # Inital value
var2:   .word 0x02             # Inital value
var3:   .word 0x03             # Inital value
var4:   .word 0x04             # Inital value
first:  .byte 'H'              # First letter of first name: 'H'
last:   .byte 'S'              # First letter of last name: 'S'

        .text
        .globl main
main:   addu $s0, $ra, $0       # save $31 in $16
        
        la $t0, var1            # load address of var1  
        la $t1, var2            # load address of var2    
        la $t2, var3            # load address of var3    
        la $t3, var4            # load address of var4   
         
        lw $t4, 0($t0)          # load initial word of var1      
        lw $t5, 0($t1)          # load initial word of var2      
        lw $t6, 0($t2)          # load initial word of var3      
        lw $t7, 0($t3)          # load initial word of var4
# breakpoint to 0x00400064
        sw $t4, 0($t3)          # store initial word of var4 to var1
        sw $t5, 0($t2)          # store initial word of var3 to var2
        sw $t6, 0($t1)          # store initial word of var2 to var3
        sw $t7, 0($t0)          # store initial word of val1 to var4

# restore now the return address in $ra and return from main
        addu $ra, $0, $s0       # return address back in $31
        jr $ra                  # return from main