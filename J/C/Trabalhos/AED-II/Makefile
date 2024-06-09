T2:
	gcc -o T2 T2.c -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic

debug:
	gcc -o T1 T1.c -g -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic
	gdb ./T1

clean:
	rm T2
