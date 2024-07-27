.data 
	message: .asciiz "Como assim voce nao sabe?\n"
	
.text
	main:	
		jal display
		
		addi $s0, $zero, 5
		
		li, $v0, 1
		add $a0, $zero, $s0
		syscall
		
		# Encerra o programa
		li $v0, 10
		syscall
		
	display:
		li $v0, 4
		la $a0, message
		syscall
		
		jr $ra
		