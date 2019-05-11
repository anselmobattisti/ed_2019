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
TLDE* Altera_Pos(TLDE* l, int n);

int main(void) {
  TLDE *l = inicializa();
  l = insere_inicio(l,10);
  l = insere_inicio(l,20);
  l = insere_inicio(l,30);
  l = insere_inicio(l,40);
  l = insere_inicio(l,50);

  l = Altera_Pos(l, 2);

  imprime(l);
  return 0;
}

TLDE* Altera_Pos(TLDE* l, int n) {
  if (!l || n==0) return l;
  int t = 1;
  TLDE *cauda = l;
  while (cauda->prox) {
    t++;
    cauda = cauda->prox;
  }

  if (n > t) return l;

  TLDE *aux = l;

  for (t = 0; t < n; t++) {
    aux = aux->prox;
  }

  aux->ant->prox = NULL;
  aux->ant = NULL;
  cauda->prox = l;
  l->ant = cauda;
  return aux;
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
  printf("\n");
}