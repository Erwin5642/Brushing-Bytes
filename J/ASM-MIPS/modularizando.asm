.data
	newLine: .asciiz "\n"
	
.text
	main:
		addi $s0, $zero, 13
		
		jal printWord
		
		jal increaseMyRegister
		
		#Encerra programa
		li $v0, 10
		syscall
	
	increaseMyRegister:
		# Salva o valor para onde voltar na main e os valores da main
		addi $sp, $sp, -8
		sw $s0, 0($sp)
		sw $ra, 4($sp)
		
		addi $s0, $zero, 17
		
		# Mostrar valor
		jal printWord
		
		# Volta com os valores originais do registrador de endereço e de s0
		lw $s0, 0($sp)
		lw $ra, 4($sp)
		addi, $sp, $sp, 8
		
		 jr $ra
		  
	printWord:
		li $v0, 1
		move $a0, $s0
		syscall
		
		li $v0, 4
		la $a0, newLine
		syscall
		
		jr $ra
		
		
	
			
	

