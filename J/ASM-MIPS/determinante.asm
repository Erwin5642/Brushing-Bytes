.data 
    matrix: .word 1 3  
            .word 2 1 
    .eqv size 2
    .eqv data_size 4
    .eqv space 32
    .eqv endl 10

.text
    main:
	lui $at, 0x00001001
	ori $a0, $at, 0
	addi $a1, $zero, size
	jal mostrarMatriz

	lui $at, 0x00001001
	ori $a0, $at, 0
	addi $a1, $zero, size

	jal determinante
	add $a0, $zero, $v0
	addi $v0, $zero, 1
	syscall

    # Encerra o programa
    addi $v0, $zero, 10
    syscall

    determinante:
    # argumentos: a0 = matrix, a1 = tam
    # retorno: v0 = det
    
    # Caso base
    addi $t0, $zero, 2
    beq $a1, $t0, matriz2x2

    jr $ra

    matriz2x2:
        lw $t0, 0($a0) 
        lw $t1, 12($a0)
        mul $v0, $t0, $t1
        lw $t0, 4($a0) 
        lw $t1, 8($a0)
        mul $t0, $t0, $t1
        sub $v0, $v0, $t0
    jr $ra

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
    