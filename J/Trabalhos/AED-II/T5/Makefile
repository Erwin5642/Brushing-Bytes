V_SIZE_ALL = "10" "100" "1000" "10000" "100000" 
V_SIZE_COMPLEX = "500000" "5000000" "50000000"
ORD_TYPES = "a" "c" "d"

T5:
	gcc -o T5_Ordena T5_Ordena.c -Wall -Wextra -pedantic -fsplit-stack

cleanGeraAll: cleanGeraIn cleanGeraOrd cleanGeraOut

cleanGeraOut:
	@echo "Removendo arquivos de saida"
	@for size in $(V_SIZE_ALL); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type.out; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type.out; \
		done; \
	done

cleanGeraOrd:
	@echo "Removendo arquivos ordenados"
	@for size in $(V_SIZE_ALL); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type.ord; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type.ord; \
		done; \
	done

cleanGeraIn:
	@echo "Removendo arquivos não ordenados"
	@for size in $(V_SIZE_ALL); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		for type in $(ORD_TYPES); do \
			rm $$size.$$type; \
		done; \
	done

geraTestes: gera-in-out
	@for size in $(V_SIZE_ALL); do \
		echo "Criando arquivo com tamanho $$size"; \
		./gera-in-out $$size a; \
		./gera-in-out $$size c; \
		./gera-in-out $$size d; \
		echo ""; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		echo "Criando arquivo com tamanho $$size"; \
		./gera-in-out $$size a; \
		./gera-in-out $$size c; \
		./gera-in-out $$size d; \
		echo ""; \
	done

testaBubbleSortBasico: T5_Ordena
	@echo "Testing basic bubble sort"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 1 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done

testaBubbleSortMelhorado: T5_Ordena
	@echo "Testing improved bubble sort"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 2 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done

testaInsertionSort: T5_Ordena
	@echo "Testing insertion sort"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 3 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done

testaMergeSort:
	@echo "Testing merge sort"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 4 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 4 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done


testaQuickSortRand:
	@echo "Testing quick sort random pivot"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 6 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 6 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done

testaQuickSortEnd:
	@echo "Testing quick sort with last element pivot"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 5 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 5 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done


testaQuickSortMed:
	@echo "Testing quick sort with median of 3 pivot"
	@for size in $(V_SIZE_ALL); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 7 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done
	@for size in $(V_SIZE_COMPLEX); do \
		echo "$$size"; \
		for type in $(ORD_TYPES); do \
			echo "Testing type: $$type"; \
			./T5_Ordena 7 $$size.$$type $$size.$$type.ord; \
			if diff $$size.$$type.out $$size.$$type.ord > /dev/null; then \
				echo "$$size $$type OK"; \
			else \
				echo "$$size $$type WRONG"; \
			fi; \
		done; \
	done