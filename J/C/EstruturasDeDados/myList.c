#include <stdio.h>
#include <stdlib.h>

struct s_no
{
	int chave;
	struct s_no *prox;
};

void insere(struct s_no **inicio, int val)
{
	struct s_no *p = malloc(sizeof(struct s_no));
	p->chave = val;
	p->prox = *inicio;
	*inicio = p;
}

int main()
{
	struct s_no *L = NULL;
	struct s_no *p;
	
	insere(&L, 4);
	insere(&L, 3);
	insere(&L, 2);
	insere(&L, 1);
	insere(&L, 0);
		
	p = L;
	while( p != NULL )
	{
		printf("[%i]->", p->chave);
		p = p->prox;
	}	
	
	printf("\n");
	
	return 0;
}