#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* inverte(TLSE*l);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  TLSE *n = inicializa();

  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);
  //l = ins_ini(l, 5);
  n = inverte(l);
  printf("\nLista L:\n");
  imprime(l);
  printf("\nLista N:\n");
  imprime(n);
}

TLSE* inverte(TLSE*l) {
  TLSE* nl = inicializa();

  while (l) {
    // versão longa
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = l->info;
    novo->prox = nl;
    nl = novo;
    l = l->prox;
  }

  imprime(nl);

  return nl;
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