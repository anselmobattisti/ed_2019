#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int info;
	struct lista *prox;
}TLSE;

TLSE *inicializa(void)
{
	return NULL;
}

TLSE *insere_ini(TLSE *l, int x)
{

	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo -> info = x;
	novo -> prox = l;
	return novo;
}

void printa(TLSE *l)
{
	while(l)
	{
		printf("%d", l->info);
		l = l->prox;
		if(!l) printf("\n");
		else printf(" ");
	}
}

TLSE *insere_fim(TLSE *l, int x)
{
	if(!l) return insere_ini(l,x);
	TLSE *p = l;

	while(p ->prox) p = p->prox;

	p -> prox = insere_ini(p->prox, x);
	return l;
}

TLSE* inverte(TLSE *l)
{
	TLSE *aux = l;
	TLSE *saida = inicializa();
	int *vet = (int*)malloc(0);
	int i = 0;

	while(aux)
	{
		
		vet = (int*)realloc(vet,(i+1) * sizeof(int));
		vet[i++] = aux->info;
		aux = aux->prox;	
	}

	while(--i >= 0)
	{
		//printf("aqui1\n");
		saida = insere_fim(saida, vet[i]);
		//printf("aqui3\n");
	}

	free(vet);

	return saida;
}

int main()
{

	TLSE *lista1 = inicializa();
	TLSE *lista2;
	int i = 1;
	for(; i <= 10 ; i++) lista1 = insere_ini(lista1, i);

	printa(lista1);
	lista2 = inverte(lista1);
	printa(lista2);

	return 0;
}