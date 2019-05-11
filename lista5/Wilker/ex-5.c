#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* rto (TLSE* l, int elem);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 1);
  l = ins_ini(l, 3);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 4);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  TLSE *p = l; 

  printf("\nLista Original:\n");
  imprime(p);   

  printf("\nLista Sem o 2:\n");
  imprime(rto(p,2));
  return 0;
}

TLSE* rto (TLSE* l, int elem) {
    if(!l)return NULL;
    if(l->info == elem){
        TLSE *p = l;
        l = rto(l->prox, elem);
        free(p);
    }
    else
    {
        l->prox = rto(l->prox, elem);
    }
    return l;
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