T1:
	gcc -o T1 T1.c -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic

T2:
	gcc -o T2 T2.c -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic

debug1:
	gcc -o T1 T1.c -g -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic
	gdb ./T1

debug2:
	gcc -o T2 T2.c -g -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic
	gdb ./T2

clean1:
	rm T1

clean2:
	rm T2
