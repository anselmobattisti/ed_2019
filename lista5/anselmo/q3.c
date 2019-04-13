#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* troca_cabeca(TLSE*l, int n);
TLSE* desloca(TLSE*l, int n);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);

  imprime(l);

  l = desloca(l,0);
  printf("\nLista Descolada PAR:\n");
  imprime(l);

  l = desloca(l,0);
  printf("\nLista Descolada PAR:\n");
  imprime(l);

  l = desloca(l,1);
  printf("\nLista Descolada IMPAR:\n");
  imprime(l);

  l = desloca(l,1);
  printf("\nLista Descolada IMPAR:\n");
  imprime(l);
}

TLSE* desloca(TLSE *l, int n) {
  TLSE *p = l, *q = NULL, *ant = NULL;

  while (p) {
    if (p->prox)
      ant = p;
    p = p->prox;
    if (p)
      q = p;
  }

  // a lista ou não tem elemento ou tem apenas 1 elemento;
  if (!q) return l;

  if (n%2 == 0) {
    q->prox = l;
    l = l->prox;
    q->prox->prox = NULL;
  } else {
    q->prox = l;
    l = q;
    ant->prox = NULL;
  }
  return l;
}

TLSE* troca_cabeca(TLSE*l, int n) {

  TLSE* p = l, *q;

  /*
  Quero terminar a execução do while com
  q sendo o último elemento da lista
  */
  while (p) {
    q = p;
    p = p->prox;
  }

  if (n%2 == 1) {
    int tmp = q->info;
    q->info = l->info;
    l->info = tmp;
  } else {
    int tmp = l->info;
    l->info = q->info;
    q->info = tmp;
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