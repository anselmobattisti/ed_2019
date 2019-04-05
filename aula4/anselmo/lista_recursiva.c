/*

  Exemplo com lista encadeada com implementações recursivas

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* ins_fim_rec(TLSE *l, int x);
TLSE* ins_ord_rec(TLSE *l, int x);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  l = ins_ini(l, 10);
  l = ins_fim_rec(l, 14);
  l = ins_fim_rec(l, 20);
  l = ins_ord_rec(l, 15);
  imprime(l);
}

TLSE* ins_fim_rec(TLSE *l, int x) {
  if (!l) {
    return ins_ini(l,x);
  }
  l->prox = ins_fim_rec(l->prox, x);
  return l;
}

TLSE* ins_ord_rec(TLSE *l, int x) {
  if (!l || l->info >= x) {
    return ins_ini(l,x);
  }
  l->prox = ins_fim_rec(l->prox, x);
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