.data
	n1: .word 15
	n2: .word -10
.text
	lw $t0, n1($zero)
	lw $t1, n2($zero)
	
	add $t2, $t0, $t1 
	
	li $v0, 1
	add $a0, $zero, $t2
	syscall