fibonacci:
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $a0, 4($sp)

    li $t3, 1
    bgt $a0, $t3, fib_recurse
    nop
    move $v0, $a0
    j fib_return

fib_recurse:
    addi $a0, $a0, -1
    jal fibonacci
    nop
    sw $v0, 0($sp)

    addi $a0, $a0, -1
    jal fibonacci
    nop
    lw $t4, 0($sp)
    add $v0, $v0, $t4

fib_return:
    lw $a0, 4($sp)
    lw $ra, 8($sp)
    addi $sp, $sp, 12
    jr $ra
