.data
	myArray: .space 12
	arrayIniciado: .word 100:3

.text
	 addi $s0, $zero, 4
	 addi $s1, $zero, 10
	 addi $s2, $zero, 12
	 
	 # Indice
	 addi $t0, $zero, 0
	 
	 sw $s0, myArray($t0)
	 addi $t0, $t0, 4
	 
	 sw $s1, myArray($t0)
	 addi $t0, $t0, 4
	 
	 sw $s2, myArray($t0)

	 
	  
	   
