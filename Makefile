metodos_numericos: source/*.c include/*.h
	gcc source/*.c -o metodos_numericos.o -Iinclude -lm