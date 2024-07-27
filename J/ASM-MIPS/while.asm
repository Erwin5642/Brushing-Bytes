.data 
	endl: .asciiz "\n"
.text 
	main:
	addi $t0, $zero, 0
	
	while:
		slti $t7, $t0, 10
		beqz $t7, end
		
		addi $t0, $t0, 1
		jal printWord	
		j while
	end:
	
	
	# Encerra programa
	li $v0, 10
	syscall
	
	printWord:
	li $v0, 1
	add $a0, $t0, $zero
	syscall
	
	li $v0,4
	la $a0, endl
	syscall
	 
	jr $ra
	