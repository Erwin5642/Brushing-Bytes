.data
	matrix: .word 3, 4
		.word 1, 5

	size: .word 2 
	.eqv _INT_SIZE 4
.text

	showMatrix:
		la $a0, matrix
		li $t0, 0
		subi $sp, $sp, 8
		sw $ra, 4($sp)
		
		while:
			beq $t0, 4, end
			sw $a0, 0($sp)
			
			lw $a0, 0($a0)
			jal showWord
			
			lw $a0, 0($sp) 
			addi $a0, $a0, 4
			addi $t0, $t0, 1
			
			j while
		end:
		
		li $v0, 10
		syscall
		
	showWord:
		li $v0, 1
		syscall 
		
		jr $ra		
	
	
	