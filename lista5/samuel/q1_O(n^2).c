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

//resposta
void inverte (TLSE* l)
{
	if(!l || !l->prox) return;

	TLSE *atual = l,*aux;

	int nos = 0;

	while(atual)
	{
		atual = atual->prox;
		nos++;
	}
	atual = l;
	int i=0,j;
	for(; i < nos/2 ; i++)
	{
		j=0;
		aux = l;
		while((j++ < (nos-(i+1))) && aux->prox) aux = aux->prox;

		int temp = atual->info;
		atual->info = aux->info;
		aux->info = temp;
		
		atual = atual->prox;
	}
}


int main(void)
{
	TLSE *lista = inicializa();
	int i = 1;
	for(; i <= 10 ; i++) lista = insere_ini(lista, i);

	printa(lista);
	inverte(lista);
	printa(lista);
	

	return 0;
}