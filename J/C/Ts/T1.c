#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */

#define sqrt2 1.41421

void desenharCirc(double  x, double y, double r, int rec){
	if(rec > 0){
		rec--; 
		double d = sqrt2 * r/4;
		desenharCirc(x + d, y + d, r/2, rec);
		desenharCirc(x + d, y - d, r/2, rec);
		desenharCirc(x - d, y - d, r/2, rec);
		desenharCirc(x - d, y + d, r/2, rec);
	}
	gfx_set_color(255, 255, 255);
	gfx_ellipse(x, y, r, r);
}

void desenhaQuad(double x, double y, double ratio, double rec){
	if(rec > 0){
		rec--;
		desenhaQuad(x, y-3*ratio/2, ratio/2, rec);
		desenhaQuad(x, y+3*ratio/2, ratio/2, rec);
		desenhaQuad(x+3*ratio/2, y, ratio/2, rec);
		desenhaQuad(x-3*ratio/2, y, ratio/2, rec);
	}
	gfx_set_color(255, 255, 255);
	gfx_rectangle(x-ratio, y-ratio, x + ratio, y + ratio);
	gfx_set_color(0, 0, 0);
	gfx_filled_rectangle(x-ratio+1, y-ratio+1, x+ratio-1, y+ratio-1);
}

int main()
{
	int escolha, recursividade;
	printf("Informe o fractal que deverá ser desenhado!\n1 - Circulo:\n2- Quadrado:\n");
	scanf("%d", &escolha);
	if(escolha == 1){
		printf("Fractal circulo escolhido!\n");
	}
	else{
		printf("Fractal quadrado escolhido!\n");
	}
	printf("Informe agora o nivel de recursividade desejado:\n");
	scanf("%d", &recursividade);
	gfx_init(600, 600, "Fractais");
	escolha == 1 ? desenharCirc(300, 300, 280, recursividade) : desenhaQuad(300, 300, 100, recursividade);
	gfx_paint();
	sleep(5);
	gfx_quit();

	return 0;
}
