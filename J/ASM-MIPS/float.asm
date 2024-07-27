.data 
	numero: .float 2.718 

.text
	li $v0, 2
	lwc1 $f12, numero
	syscall
  