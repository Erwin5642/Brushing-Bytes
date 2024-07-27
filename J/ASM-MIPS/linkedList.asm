.data
	x: .float 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
	y: .float 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0
	previsao: .space 40
	size: .word 10
	alpha: .float 0.01
.text
	main:
	
	li $f20, 
	
	# Treinamento
	
		
		
	hipotese:
		lw $t0, size # i = 10
		li $f12, 0.0
		while1:
			beqz $t0, end1	
			
			
			
			
			
			j while1
		end1:	
		la $v0, previsao
		jr $ra
	custo:
	
	
	derivadaParcial:
	
