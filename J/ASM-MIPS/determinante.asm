.data 
    matrix: .float 1 3 5 
            .float 2 1 0
            .float 4 2 3
    .eqv size 3
    endl: .asciiz "\n"

.text
    main:
    





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
    add $t0, $zero, 
    li $
    while1:
        beq $t0, $a1, end1
        addi $v0, $zero, 1
        syscall


        j while1
    end1:

    






