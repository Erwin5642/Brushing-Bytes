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

void deleta(struct s_no **inicio, int val)
{
	struct s_no *aux;
	if ((*inicio) != NULL)
	{
		if ((*inicio)->chave != val)
		{
			deleta(&(*inicio)->prox, val);
		}
		else
		{
			aux = (*inicio)->prox;
			free(*inicio);
			(*inicio) = aux;
		}
	}
}

void imprime(struct s_no *inicio){
	struct s_no *p = inicio;
	while (p != NULL)
	{
		printf("[%i]->", p->chave);
		p = p->prox;
	}
	printf("\n");
}

int main()
{
	struct s_no *L = NULL;
	insere(&L, 4);
	insere(&L, 3);
	insere(&L, 2);
	insere(&L, 1);
	insere(&L, 0);

	imprime(L);

	deleta(&L, 2);

	imprime(L);

	deleta(&L, 2);

	imprime(L);

	deleta(&L, 1);

	imprime(L);

	deleta(&L, 0);

	imprime(L);

	deleta(&L, 4);

	imprime(L);

	deleta(&L, 3);

	imprime(L);

	deleta(&L, 3);

	imprime(L);

	return 0;
}