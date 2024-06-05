aval2:
	gcc -o aval2 aval2.c -I$(PWD)/gfx -L$(PWD)/gfx -lm -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic

debug:
	gcc -o aval2 aval2.c -g -I$(PWD)/gfx -L$(PWD)/gfx -lm -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic
	gdb ./aval2

clean:
	rm aval2
