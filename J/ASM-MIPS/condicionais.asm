.data 
	message: .asciiz "Os numeros sao iguais"
	message1: .asciiz "O primeiro numero e menor que o segundo"	 
.text
	main:
	addi $t0, $zero, 4
	addi $t1, $zero, 5
	
	beq $t0, $t1 numbersEqual
	
	# slt $t2, $t0, $t1
	# bne $t2, $zero, numberLess
	
	blt $t1, $t2, numberLess 
	
	 # Encerra o programa
	 li $v0, 10
	 syscall
	 
	 numbersEqual: 
	 li $v0, 4
	 la $a0, message
	 syscall
	 
	 numberLess:
	 li $v0, 4
	 la $a0, message1
	 syscall
	  
