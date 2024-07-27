.data

.text
	addi $t0, $zero, 35
	addi $t1, $zero, 4
	
	# Divisão inteira sem resto
	div $s0, $t0, $t1
	
	li $v0, 1
	add $a0, $zero, $s0
	syscall
	
	# Divisão usando registradores High (resto) e Low (quociente)
	div $t0, $t1
	
	mflo $a0
	syscall
	mfhi $a0
	syscall
