.data
	euler: .double 2.71828182845
	zeroDouble: .double 0.0
.text
	ldc1 $f2, euler
	ldc1 $f0, zeroDouble
	
	li $v0, 3
	add.d $f12, $f2, $f0  
	syscall