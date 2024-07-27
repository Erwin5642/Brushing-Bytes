.data 


.text
	main:
		addi $a1, $zero, 15
		addi $a2, $zero, 3
		jal produto
		
		add $a1, $zero, $v1 
		jal displayWord
		#Encerra o programa
		li $v0, 10
		syscall
	produto:
		mul $v1, $a1, $a2
		jr $ra
	
	displayWord:
		li $v0, 1
		add $a0, $zero, $a1
		syscall
		jr $ra
		