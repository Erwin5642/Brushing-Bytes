.data 
	array: .space 16
	zero: .float 0.0
.text 
	main:
		
		la $s0, array
		li $s1, 4
		while2:
			beqz $s1, end2  
			li $v0, 5
			syscall
			sw $v0, 0($s0)						
			addi $s0, $s0, 4
			subi $s1, $s1, 1
			j while2
		end2:
		
		la $a0, array
		li $a1, 4
		jal mean
		add $a0, $zero, $v0
		
		li $v0, 1
		syscall
		
		li $v0, 10
		syscall

	mean:
		addi $v0, $zero, 0
		add $t0, $zero, $a1
		
		while1:
			beqz $t0, end1
			lw $t1, 0($a0)
			add $v0, $v0, $t1
			addi $a0, $a0, 4
			subi $t0, $t0, 1
			j while1
		end1:
		div $v0, $v0, $a1

		jr $ra
		