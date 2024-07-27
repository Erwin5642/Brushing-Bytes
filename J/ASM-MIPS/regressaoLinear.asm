.data
	x: .float 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
	y: .float 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37
	previsao: .space 40
	alpha: .float 0.001
	zero: .float 0.0
	one: .float 1.0
	bias: .float 0.0
	peso: .float 0.0
	endl: .asciiz "\n"
	.eqv ARRAY_SIZE 12
	.eqv DATA_SIZE 4
	.eqv EPOCHS 10000
	array_size_f: .float ARRAY_SIZE
.text
	main:
		lwc1 $f30, zero # cria zero 
		lwc1 $f20, bias # vies
		lwc1 $f22, peso # peso
		lwc1 $f24, alpha #alfa
	
		# Treinamento
		addi $s0, $zero, 10
		treinamento:
			beqz $s0, fimTreinamento
		
			la $a0, x
			la $a1, previsao
			add.s $f12, $f30, $f20
			add.s $f14, $f30, $f22
			jal hipotese
				
			la $a0, y
			la $a1, previsao
			jal derivadaParcialBias
			mul.s $f4, $f24, $f0
			sub.s $f20, $f20, $f4
				 
			la $a0, y
			la $a1, previsao
			la $a2, x
			jal derivadaParcialPeso
			mul.s $f4, $f24, $f0
			sub.s $f22, $f22, $f4 
		  
			# Avanca o iterador
			sub $s0, $s0, 1
			
			add.s $f12, $f30, $f20
			jal printFloat
		
			add.s $f12, $f30, $f22
			jal printFloat
			
			j treinamento
		fimTreinamento:
		
		# Encerra programa 
		li $v0, 10
		syscall	
	
	hipotese:
		# h(a0 = x, a1 = previsao, f12 = bias, f14 = peso) 
		li $t0, ARRAY_SIZE # i = 10
		
		while1:
			beqz $t0, end1
		
			# f4 = x[i], f4 = x[i] * peso, f4 = x[i] * peso + bias	
			lwc1 $f4, 0($a0) 
			mul.s $f4, $f4, $f14
			add.s $f4, $f4, $f12
			
			# y[i] = f4
			swc1 $f4, 0($a1)
			
			# Avança a iteração
			addiu $a0, $a0, DATA_SIZE
			addiu $a1, $a1, DATA_SIZE
			sub $t0, $t0, 1
									
			j while1
		end1:	
		# Restora os parametros
		la $a0, x
		la $a1, previsao
		jr $ra
		
	derivadaParcialBias:
		# derivadaParcialBias(a0 = y, a1 = previsao) 
		add.s $f0, $f30, $f30 # soma = 0
		addi $t0, $zero, ARRAY_SIZE # i = 10
	
		while2:
			beqz $t0, end2
			lwc1 $f4, 0($a0)
			lwc1 $f6, 0($a1)
			
			sub.s $f4, $f6, $f4 #  previsao - y 
			add.s $f0, $f0, $f4  # sum = sum + (previsao - y)
			
			# Avança a iteração
			addiu $a0, $a0, DATA_SIZE
			addiu $a1, $a1, DATA_SIZE
			sub $t0, $t0, 1
			
			j while2
		end2:
		
		lwc1 $f4, one
		lwc1 $f6, array_size_f
		div.s $f4, $f4, $f6
		mul.s $f0, $f0, $f4
		
		# Restora os parametros
		la $a0, y
		la $a1, previsao
		
		jr $ra
	
	derivadaParcialPeso:
	# derivadaParcialBias(a0 = y, a1 = previsao, a2 = x) 
		add.s $f0, $f30, $f30 # soma = 0
		addi $t0, $zero, ARRAY_SIZE # i = 10
		
		while3:
			beqz $t0, end3
			lwc1 $f4, 0($a0)
			lwc1 $f6, 0($a1)
			
			sub.s $f4, $f6, $f4 #  previsao - y 
			
			lwc1 $f6, 0($a2)
			mul.s $f4, $f4, $f6 # (previsao - y) * x
			add.s $f0, $f0, $f4  # sum = sum + (previsao - y) * x
			
			# Avança a iteração
			addiu $a0, $a0, DATA_SIZE
			addiu $a1, $a1, DATA_SIZE
			addiu $a2, $a2, DATA_SIZE
			sub $t0, $t0, 1
			
			j while3
		end3:
		
		lwc1 $f4, one
		lwc1 $f6, array_size_f
		div.s $f4, $f4, $f6
		mul.s $f0, $f0, $f4
		
		# Restora os parametros
		la $a0, y
		la $a1, previsao
		la $a2, x
		
		jr $ra
	
		printFloat:
			li $v0, 2
			syscall
			li $v0, 4
			la $a0, endl
			syscall
			jr $ra
				
	
