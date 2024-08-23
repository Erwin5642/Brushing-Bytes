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
		add $k0, $zero, $a0
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

	fib:
		beqz $a0, return_Zero
		beq $a0, 1, return_One

		sub $sp, $sp, 4
		sw $ra, 0($sp)
		
		sub $a0, $a0, 1
		add $v1, $zero, 0
		jal fib
		
		add $v0, $v1, $v0
		sub $v1, $v0, $v1

		lw $ra, 0($sp)
		add $sp, $sp, 4

		jr $ra

	fat:
		# Retorna 1 se n for zero
		beqz $a0, return_One
			
		# Salva o endereço do registro para salvar de onde a função veio 
		sub $sp, $sp, 4
		sw $ra, 0($sp)
		
		# fat(n - 1)
		sub $a0, $a0, 1
		jal fat
		# Retorna o valor n
		add $a0, $a0, 1
		
		# Da um pop na stack de endereços
		lw $ra, 0($sp)
		add $sp, $sp, 4
		
		# Multiplica n * fat(n - 1)
		mul $v0, $v0, $a0
		
		# Retorna para a chamada de função anterior: linha 76 caso foi chamada recursivamente ou para a main
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
		
	return_Zero:
		li $v0, 0
		jr $ra
		
	return_One:
		li $v0, 1
		jr $ra
		

	
