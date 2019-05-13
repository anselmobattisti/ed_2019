#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct lista{
	int info;
	struct lista *prox;
}TLSE;

void inverte(TLSE* L);
void insere(TLSE* L, int v);
void imprime(TLSE* L);
void insereInicio(TLSE* L, int v);

int main(void){

	
	TLSE* l = (TLSE*)malloc(sizeof(TLSE));
	l->info = 3;
	l->prox = NULL;
	insere(l,4);
	insere(l,5);

	printf("Lista Original \n");
	imprime(l);
	
	printf("Lista Insere Inicio \n");
	insereInicio(l,7);
	imprime(l);

	printf("Lista Invertida \n");
	inverte(l);
	imprime(l);

	TLSE* p = l;
	while(p!=NULL){
		TLSE* t = p->prox;
		free(p);
		p = t;
	}
	free(l);
	
	return 0;
}

void inverte(TLSE* L){
	TLSE* inv = (TLSE*) malloc(sizeof(TLSE));
	inv->info = L->info;
	inv->prox = NULL;
		
	for(TLSE* p = L->prox;p!= NULL;p = p->prox){
		insereInicio(inv,p->info);
		
	}
	
	L->info = inv->info;
	L->prox = inv->prox;		
}

void insere(TLSE* L, int v){
	TLSE* ant = NULL;
	

	TLSE* novo = (TLSE*) malloc(sizeof(TLSE));
	novo->info = v;
		

	for(TLSE* p = L;p!= NULL;p = p->prox){
		ant = p;
	}
	ant->prox = novo;	
	
}

void insereInicio(TLSE* L, int v){
	TLSE* novo = (TLSE*) malloc(sizeof(TLSE));	
	novo->info = L->info;
	novo->prox = L->prox;
	
	L->info = v;	
	L->prox = novo;

	
}

void imprime(TLSE* L){
	for(TLSE* p = L;p!= NULL;p = p->prox){
		printf("info = %d \n", p->info);
	}
}
        
