.data 

.text 
	main:
	li $v0, 5
	syscall
	
	add $a0, $zero, $v0
	jal fatorial
	
	li $v0, 10
	syscall
	
	fatorial:
	beqz $a0, one
		
sub $sp,$sp,4   #storing return address on stack
	sw  $ra, 0($sp)
	
	jr $ra
	
	one:
	addi $v0, $zero, 1
	jr $ra
	
	printWord:
	li $v0, 1
	syscall
	jr $ra