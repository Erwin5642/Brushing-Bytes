.data 
	prompt: .asciiz "Informe um numero: \n"	
	message: .asciiz "O sucessor do seu numero eh: \n"
.text
	main: 
		li, $v0, 4
		la $a0, prompt
		syscall
		
		li, $v0, 5
		syscall
		
		add $t0, $v0, 1
		
		jal printWord
		
		# Encerra programa
		li, $v0, 10
		syscall
	
	printWord:
		li $v0, 4
		la $a0,  message
		syscall
	
		li $v0, 1
		move $a0, $t0
		syscall
		
		jr $ra
		
	
