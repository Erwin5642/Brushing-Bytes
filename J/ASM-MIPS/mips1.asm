.data
	vetor: .space 32
	endl: .byte 32
.text 
	main:
	
	#encerra programa
	addi $v0, $zero, 10
	syscall
	
	jal lerVetor
	
	jal mostrarVetor
	
	lerVetor:
			add $t0, $a0, $zero 
			add $t1, $a1, $zero
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
		add $t1, $a1, $zero
		add $t2, $a0, $zero
		while2:
			beq $t1, $a1, end1
			
			lw $a0, 0($t0)
			addi $v0, $zero, 1
			syscall
			
			addi $v0, $zero, 11
			syscall
		
			addi $t0, $t0, 4
			addi $t1, $t1, 1
		
			j while1
		
		end2:
		add $a0, $t2, $zero
		jr $ra