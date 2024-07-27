.data 
	numero: .word 32

.text
	li $v0, 2
	lwc1 $f12, numero
	syscall
  
