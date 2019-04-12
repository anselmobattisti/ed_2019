#include <stdio.h>
#include <stdlib.h>

typedef struct tlse {
  int info;
  struct tlse* prox;
}TLSE;

TLSE* inicializa();
TLSE* insere(TLSE *l, int x);
TLSE* busca(TLSE *l, int x);
TLSE* retira(TLSE *l, int x);
void imprime(TLSE *l);
void libera(TLSE *l);
void ordena(TLSE *l);

int main(void) {

  TLSE *l;
  l = inicializa();

  l = insere(l, 10);
  l = insere(l, 20);
  l = insere(l, 30);
  l = insere(l, 5);
  l = insere(l, 35);
  l = insere(l, 25);

  l = retira(l, 20);

  ordena(l);

  //libera(l);
  //free(l);

  imprime(l);

  //imprime(busca(l,10));

  return 0;
}

void ordena(TLSE *l) {
  TLSE *p;
  for (p = l; p; p = p->prox) {
    TLSE *q, *menor = p;

    for (q = p->prox; q; q = q->prox) {
      if (menor->info > q->info) {
        menor = q;
      }
    }

    if (menor != p) {
      int tmp = p->info;
      p->info = menor->info;
      menor->info = tmp;
    }
  }
}

TLSE* retira(TLSE *l, int x) {

  TLSE *p = l, *ant = NULL;

  while (p && p->info != x) {
    ant = p;
    p = p->prox;
  }
  // não achou o elemento na lista
  if (p == NULL) {
    return l;
  }

  if (!ant) {
    l = l->prox;
  } else {
    ant->prox = p->prox;
  }

  free(p);
  return l;
}

void libera(TLSE *l) {
  TLSE *p = l, *q;
  while (p) {
    q = p;
    p = p->prox;
    free(q);
  }
}

TLSE* inicializa() {
  return NULL;
}

TLSE* busca(TLSE *l, int x) {
  // aqui a variável l é uma cópia ou seja, podemos
  // mudar o valor dela SEM perder a referência para a
  // cabeça da lista.
  while (l && l->info != x) {
    l = l->prox;
  }
  return l;
}

TLSE* insere(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = l;
  return novo;
}

void imprime(TLSE *l) {
  printf("\n");
  while (l) {
    printf("%d - ", l->info);
    l = l->prox;
  }
  printf("\n");
}