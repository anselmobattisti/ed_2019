/*

Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
função é o seguinte: TLSE* desloca (TLSE* l, int n).*/



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
TLSE* desloca (TLSE* l, int n);

int main(void){

	
	TLSE* l = (TLSE*)malloc(sizeof(TLSE));
	l->info = 1;
	l->prox = NULL;
	insere(l,2);
	insere(l,3);
	insere(l,4);
	insere(l,5);
	insere(l,6);
	insere(l,7);
	insere(l,8);
	insere(l,9);
	insere(l,10);

	printf("Lista Original \n");
	imprime(l);
	
	

	printf("Lista Deslocada \n");
	TLSE* deslocada = desloca(l,2);
	imprime(deslocada);

	TLSE* p = l;
	while(p!=NULL){
		TLSE* t = p->prox;
		free(p);
		p = t;
	}
	free(l);
	
	return 0;
}

TLSE* desloca (TLSE* l, int n){
	TLSE* deslocada = (TLSE*) malloc(sizeof(TLSE));
	deslocada->info = l->info;
	deslocada->prox = NULL;

	for(TLSE* p = l->prox;p!= NULL;p = p->prox){
		insere(deslocada,p->info);			
	}
	
	TLSE* ant = NULL;
	TLSE* ult = NULL;
	
	
	if(n%2!=0){
		while(n>0){
			for(TLSE* p = deslocada;p!= NULL;p=p->prox){
				if(p->prox == NULL){
					ult = p;
				}else{
					ant =p;
				}					
			}
			insereInicio(deslocada,ult->info);
			ant->prox = NULL;
			n--;
		}
	}else{
		while(n>0){
			
			ant = deslocada;
			insere(deslocada,ant->info);
			deslocada = ant->prox;
			
			n--;
		}
	}
	

	return deslocada;
}


void inverte(TLSE* L){
	TLSE* inv = (TLSE*) malloc(sizeof(TLSE));
	inv->info = L->info;
	inv->prox = NULL;
		
	
	
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

		
