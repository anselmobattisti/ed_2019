#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* desloca(TLSE* l, int n);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);
  l = ins_ini(l, 5);
  l = ins_ini(l, 6);
  l = ins_ini(l, 7);
  l = ins_ini(l, 8);
  l = ins_ini(l, 9);
  

  printf("\nLista Original:\n");
  imprime(l);   
  l=desloca(l,2);
  printf("\nLista Deslocada a direita por 1 pois n é par:\n");
  imprime(l);
  l=desloca(l,1);
  printf("\nLista Deslocada a esquerda por 1 pois n é ímpar:\n");
  imprime(l);
  return 0;
}

TLSE* desloca(TLSE* l, int n) {
    if(!l)return NULL;
    if(n%2 != 0){
        TLSE *p = l;
        while(p->prox) p=p->prox;
        p->prox=l;
        while(l->prox!=p) l=l->prox;
        l->prox =NULL;
        return p;
    }
    else
    {
        TLSE *p = l;
        while(p->prox) p=p->prox;
        p->prox=l;
        l=l->prox;
        p->prox->prox=NULL;
        return l;
    }
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