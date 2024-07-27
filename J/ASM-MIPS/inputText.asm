.data 
	prompt: .asciiz "Insira uma frase:\n"
	userInput: .space 20
.text
	main:
	#  mostra uma mensagem
	li, $v0, 4
	la $a0, prompt
	syscall
	
	# le a partir da entrada um texto com no máximo 20 bytes 
	li, $v0, 8
	la $a0, userInput
	la $a1, 20
	syscall
	
	# 
	li $v0, 4
	la $a0, userInput
	syscall
	
	# Encerra o programa
	li $v0, 10
	syscall


