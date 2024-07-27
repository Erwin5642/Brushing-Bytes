.data 
	n1: .float 21.25
	n2: .float 4.75
	n3: .double 9.55
	n4: .double 3.40
	zero: .float 0.0
	one: .float 1.0
.text 
	lwc1 $f4, n1
	lwc1 $f6, n2
	lwc1 $f8, zero
	lwc1 $f10, one
	while:
		c.lt.s $f6, $f8 
		bc1f end
		
		add.s $f6, $f6, $f10
		
		j while	
	end:
	
		

	
	