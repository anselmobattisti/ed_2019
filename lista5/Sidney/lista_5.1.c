#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
int info;
struct lista *prox;
}TLSE;

 void inverte (TLSE* l);
 void imprime(TLSE* l);
 void insere(TLSE* l, int v);
 void insere_inicio(TLSE* l, int v);


int main(void) {
  TLSE* lista = (TLSE*)malloc(sizeof(TLSE));
  lista->info = 1;
  insere_inicio(lista, 3);
  insere_inicio(lista, 4);

  printf("Lista Inicial \n");
  imprime(lista);

  inverte(lista);

  printf("Lista Invertida \n");
  imprime(lista);

  return 0;
}

void inverte (TLSE* l){
  TLSE* inv = (TLSE*)malloc(sizeof(TLSE));
 
  for(TLSE* p=l;p!=NULL;p=p->prox){
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo->info = inv->info;
            novo->prox = inv->prox;

            inv->info = p->info;
            inv->prox = p->prox;       
   }  
}


void insere_inicio(TLSE* l, int v){


  TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
  novo->info = l->info;
  novo->prox = l->prox;

  l->info = v;
  l->prox = novo;
  
   
}

void insere(TLSE* l, int v){
  TLSE* ult = NULL;
  TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
  novo->info = v;
  for(TLSE* p=l;p!=NULL;p=p->prox){
        ult = p;
   }
   ult->prox = novo;
}

 void imprime(TLSE* l){
   for(TLSE* p=l;p!=NULL;p=p->prox){
        printf("info = %d \n",p->info);
   }
 }
