#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* i_p (TLSE* l);
void imprime(TLSE*l);
TLSE* insere_fim(TLSE* l, int info);
TLSE* insere_inicio(TLSE* l, int info);

int main(void) {
  TLSE *l = inicializa();
  TLSE *p = inicializa();

  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 1);
  l = ins_ini(l, 3);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 4);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  
  printf("\nLista Original:\n");
  imprime(l);   

  p=i_p(l);

  printf("\nLista original agora par:\n");
  imprime(l);

  printf("\nLista impar:\n");
  imprime(p);

  return 0;
}

TLSE* i_p (TLSE* l){
    if(!l)return NULL;
    TLSE*i, *p, *aux=l;
    while(aux){
      if(aux->info %2 == 0){
        insere_fim(p,aux->info);
      }else{
        insere_fim(i,aux->info);
      }
      aux=aux->prox;
    }
    aux = i;
    while(aux->prox){
      aux=aux->prox;
    }
    aux-> prox = p;
    return i;
}


void imprime(TLSE*l) {
  printf("\nLista\n");
  if (l) {
    TLSE *p = l;
    while (p->prox) {
      printf("%d - ", p->info);
      p = p->prox;
    }
    // imprime o últiom elemento da lista
    printf("%d - ", p->info);
  }
  printf("\n\n");
}

TLSE* ins_ini(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = l;
  return novo;
}

TLSE* inicializa()  {
  return NULL;
}


TLSE* insere_fim(TLSE* l, int info) {
	if(!l) return ins_ini(l, info);

	TLSE* p = l;
	while(p->prox) p = p->prox;
	
	TLSE* node = (TLSE*) malloc(sizeof(TLSE));
	node->info = info;
	node->prox = NULL;

	p->prox = node;
	return l;
}