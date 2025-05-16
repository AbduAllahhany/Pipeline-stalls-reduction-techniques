        .text
        .globl main

main:
        # Replace 'li $t0, 5' with 'addiu $8, $0, 5'  ($t0 = $8)
        addiu   $8, $0, 5      # $t0 = 5
        addiu   $9, $0, 10     # $t1 = 10

        beq     $8, $9, equal
        bne     $8, $9, notequal

equal:
        addiu   $10, $0, 1     # $t2 = 1
        j       done

notequal:
        addiu   $10, $0, 0     # $t2 = 0
        j       done

done:
        sll     $0, $0, 0      # nop (safe exit)
