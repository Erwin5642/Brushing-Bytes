.data

.text
	main:
	
	li $a0, 14
	
	jal clearBitZero
	
	add $a0, $zero, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
	clearBitZero:
	andi $v0, $a0, -2
	
	jr $ra
	
