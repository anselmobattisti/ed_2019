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
	TLSE *aux = l;
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
		l->info = vet[i];
		l = l->prox;
	}
	free(vet);
}


int main(void)
{
	TLSE *lista = inicializa();
	int i = 1;
	for(; i <= 10 ; i++) lista = insere_ini(lista, i);

	printa(lista);
	inverte(lista);
	printa(lista);
	inverte2(lista);
	printa(lista);
	return 0;
}