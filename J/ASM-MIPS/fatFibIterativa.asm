.data
	endl: .asciiz "\n"
	message1: .asciiz "Insira um valor para calcular o fatorial e o numero de fibonacci:\n"
	message2: .asciiz "O fatorial do seu numero eh:\n"
	message3: .asciiz "O numero de fibonacci do seu numero eh:\n"
.text
	main:
		# showMessage("Insira uma valor...")
		la $a0, message1
		jal showMessage
		
		jal readWord
		# s0 = readWord()
		add $s0, $zero, $v0

		# Passa o valor no lido para ser parametro da função fibonacci 		
		# fib(a0 = s0)
		add $a0, $zero, $s0
		jal fib
		# s1 = fib(a0 = s0)
		add $s1, $zero, $v0
		
		# showMessage("O numero de fibonacci...")
		la $a0, message3
		jal showMessage		

		# printWord(a0 = s1)
		add $a0, $zero, $s1
		jal printWord
		
		# Passa o valor lido para ser parametro na funcao fatorial 
		# fat(a0 = s0)
		add $a0, $zero, $s0
		jal fat
		
		# s2 = fat(a0 = s0)
		add $s2, $zero, $v0
		
		la $a0, message2
		jal showMessage
		
		add $a0, $zero, $s2
		jal printWord
		
	# Encerra o programa
	li $v0, 10
	syscall
	
	# Funcao 
	fib:
		li $v0, 1
		li $t0, 1
		while1: 
			sgt $t1, $a0, 1
			beqz $t1, end1
				add $v0, $v0, $t0
				sub $t0, $v0, $t0
				sub $a0, $a0, 1
			j while1
		end1:
	
		jr $ra
	
	# Funcao fatorial
	fat:
		li $v0, 1
		while2:
			beq $a0, 1, end2
		
			mul $v0, $v0, $a0
		
			sub $a0, $a0, 1
			j while2
		end2:
	
		jr $ra
	
	printWord:
		# Exibe o valor em $a0
		li $v0, 1
		syscall
		# Adiciona uma quebra de linha 
		li $v0, 4
		la $a0, endl
		syscall
	
		jr $ra
	
	readWord:
		li $v0, 5
		syscall
			
		jr $ra
	
	showMessage:
		li $v0, 4
		syscall
		
		jr $ra
	