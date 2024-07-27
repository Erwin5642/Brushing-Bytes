.data 

.text
	# Usando mul e registradores determinados
	addi $s0, $zero, -10
	addi $s1, $zero, 5
	
	mul $t0, $s0, $s1
	
	li $v0, 1
	add $a0, $zero, $t0
	syscall

	# Usando mult e o registrador Low 
	addi $s0, $s0, 2500
	mult $s0, $s1
	
	mflo $t1
	
	add $a0, $zero, $t1
	syscall
	
	# Usando sll para multiplicar por potencias de dois 
	addi $s0, $zero, 4
	sll $t0, $s0, 3
	
	add $a0, $zero, $t0
	syscall
	
	
	
	
	