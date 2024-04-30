//Livro Szwarcfiter: 2.1, 2.4, 2.6 a 2.18, 2.20, 2.21

#include <stdio.h>
#include <stdlib.h>

//2.1: busca de um elemento na lista linear L
int buscaL(int *L, int n, int elem){
    int i;
    for(i =  0; i < n; i++){
        if(L[i] == elem){
            return i;
        }
    }
    return -1;
} 

//2.4: busca binária em lista linear L
int buscaBinL(int *L, int n, int x){
    int ini = 0, fim = n - 1, meio = (fim + ini)/2;
    while(ini <= fim){
        if(L[meio] == x){
            return meio;
        }
        if(meio < x){
            ini = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    return -1;
}


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
	if (inicio != NULL)
	{
		while((*inicio) != NULL)
		{
			if ((*inicio)->chave != val)
			{  
				inicio = &(*inicio)->prox;
			}
			else
			{
				aux = (*inicio)->prox;
				free(*inicio);
				(*inicio) = aux;
			}
		}
	}
}

void imprime(struct s_no *inicio)
{
	struct s_no *p = inicio;
	while (p != NULL)
	{
		printf("[%i]->", p->chave);
		p = p->prox;
	}
	if(p == NULL){
		printf("[NULL]");
	}
	printf("\n");
}

void desalocar(struct s_no **inicio)
{
	struct s_no *aux;
	if (inicio != NULL)
	{
		while((*inicio) != NULL)
		{
			aux = (*inicio)->prox;
			free((*inicio));
			(*inicio) = aux;
		}
	}
}

int main()
{
	struct s_no *L = NULL;
	insere(&L, 4);
	insere(&L, 3);
	insere(&L, 2);
	insere(&L, 1);
	insere(&L, 0);

	return 0;
}
