.data 
	n1: .float 21.25
	n2: .float 4.75
	n3: .double 9.55
	n4: .double 3.40
.text 
	lwc1 $f4, n1
	lwc1 $f6, n2

	add.s $f12, $f4, $f6
	
	ldc1 $f8, n3 
	ldc1 $f10, n4
	
	add.d $f12, $f8 $f10
	

	

	
	