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

 
 TLSE* desloca (TLSE* l, int n)
 {
 	TLSE *atual = l;
 	if(!l || !l->prox) return l;
 	
 	if(n&1)
 	{
 		int ant = atual->info;
 		atual = atual->prox;
 		
 		while(atual->prox)
	 	{
	 		int aux = ant;
	 		ant = atual->info;
	 		atual->info = aux;
	 		atual = atual -> prox;	
	 	}
	 	l->info = atual->info;
	 	atual->info = ant;
 	}
 	else
 	{
 		int primeiro = l -> info;
 		while(atual -> prox)
 		{
 			atual->info = atual->prox->info;
 			atual = atual->prox;
 		}
 		atual->info = primeiro;
 	}
 	return l;
 }

//5 1 2 3 4
//2 3 4 5 1
int main(void)
{
	TLSE *lista = inicializa();
	int i = 10;
	for(; i >= 1 ; i--) lista = insere_ini(lista, i);

	printa(lista);
	lista = desloca(lista, 5);
	printa(lista); 
	lista = desloca(lista, 2);
	printa(lista); 
	lista = desloca(lista, 101);
	printa(lista); 



	return 0;
}