.data 
    matrix: .word 1 3 5 
            .word 2 1 0
            .word 4 2 3
    .eqv size 3
    .eqv data_size 4
    .eqv space 32
    .eqv endl 10

.text
    main:
	lui $at, 0x00001001
	ori $a0, $at, 0
	addi $a1, $zero, size
	jal mostrarMatriz

    # Encerra o programa
    addi $v0, $zero, 10
    syscall

    determinante:
    # argumentos: a0 = matrix, a1 = tam
    # retorno: v0 = det
    
    # Caso base




    mostrarMatriz:
    # argumentos: a0 = matrix, a1 = tam
    add $t1, $zero, $zero # i = 0
    add $t0, $zero, $a0 # ponteiro para matriz

    for1:
        beq $t1, $a1, endfor1

        addi $t1, $t1, 1
        add $t2, $zero, $zero # j = 0
        for2:
            beq $t2, $a1, endfor2

            addi $t2, $t2, 1

            addi $v0, $zero, 1
            lw $a0, 0($t0)
            syscall

            addi $v0, $zero, 11

            if1:
                beq $t2, $a1, else1
                addi $a0, $zero, space
                j endif1
            else1:
                addi $a0, $zero, endl
            endif1:

            syscall

            addi $t0, $t0, data_size
            j for2
        endfor2:
        j for1
    endfor1:
	
	jr $ra
    