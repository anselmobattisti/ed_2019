#include <stdio.h>
#include <stdlib.h>

typedef struct tlde {
  int info;
  struct tlde *prox, *ant;
}TLDE;

void imprime(TLDE* l);
TLDE* inicializa();
TLDE* insere_inicio(TLDE* l, int x);
TLDE* insere_fim(TLDE* l, int x);
TLDE* busca(TLDE* l, int x);
TLDE* libera(TLDE* l);

int main(void) {
  TLDE *l = inicializa();
  l = insere_inicio(l,10);
  l = insere_inicio(l,20);
  l = insere_inicio(l,30);
  l = insere_fim(l,5);
  //libera(l);

  imprime(l);
  return 0;
}

TLDE* inicializa() {
  return NULL;
}

TLDE* libera(TLDE* l) {
  TLDE *p = l, *q;
  while (p) {
    q = p;
    p = p->prox;
    free(q);
  }
  free(l);
}

TLDE* busca(TLDE* l, int x) {
  TLDE* p = l;

  while (p && p->info!= x) {
    p = p->prox;
  }

  return p;
}

TLDE* insere_fim(TLDE* l, int x) {
  if (!l) insere_inicio(l,x);

  TLDE *p = l;

  while (p->prox) p = p->prox;

  TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
  novo->info = x;
  p->prox = novo;
  novo->ant = p;
  novo->prox = NULL;

  return l;
}

TLDE* insere_inicio(TLDE* l, int x) {

  TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
  novo->info = x;
  novo->ant = NULL;
  novo->prox = l;
  if (l) {
    l->ant = novo;
  }

  return novo;
}

void imprime(TLDE *l) {
  if (!l) return;
  printf("\n");
  while(l) {
    printf("%d ",l->info);
    l = l->prox;
  }
}