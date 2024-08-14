.data
	vetor: .space 32
	.eqv space 32
.text 
	main:

	lui $at, 0x00001001
	or $a0, $at, $zero

	addi $a1, $zero, 8
	jal lerVetor
	
	jal mostrarVetor
	
	#encerra programa
	addi $v0, $zero, 10
	syscall
	
	bubbleSort:
	
	add $t0, $a0, $zero
	add $t1, $zero, $zero
	
	for1:
		
	
		for2:
		
		
		
		endFor2:
	
	
	endFor1:
	
	
	
	lerVetor:
			add $t0, $a0, $zero 
			add $t1, $zero, $zero
			while1:

			beq $t1, $a1, end1
		
			addi $v0, $zero, 5
			syscall
			sw $v0, 0($t0) 
		
			addi $t0, $t0, 4
			addi $t1, $t1, 1
		
			j while1
	
		end1:
		
		jr $ra
		
	mostrarVetor:
		add $t0, $a0, $zero
		add $t1, $zero, $zero
		add $t2, $a0, $zero
		while2:
			beq $t1, $a1, end2
			
			lw $a0, 0($t0)
			addi $v0, $zero, 1
			syscall
			
			addi $a0, $zero, space
			addi $v0, $zero, 11
			syscall
		
			addi $t0, $t0, 4
			addi $t1, $t1, 1
		
			j while2
		
		end2:
		add $a0, $t2, $zero
		jr $ra
