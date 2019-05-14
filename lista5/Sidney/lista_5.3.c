#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct lista{
	int info;
	struct lista *prox;
}TLSE;


TLSE* desloca (TLSE* l, int n);
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
	
	

	printf("Lista Deslocada \n");
	TLSE* invertida = desloca(l,1);
	imprime(invertida);

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
  TLSE* ant = NULL;
  TLSE* ult = NULL;

	TLSE* inv = (TLSE*) malloc(sizeof(TLSE));
	inv->info = l->info;
	inv->prox = NULL;
	int c = n;
  while(c>0){
    for(TLSE* p = l->prox;p!= NULL;p = p->prox){
		  if(p->prox != NULL){
        //ant = p;
        ult = p->prox;
        insere(inv,p->info)	;
      }       
    }	    
	      
    insereInicio(inv, ult->info);
    c--;
  }

	return inv;
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
  printf("\n");
}
