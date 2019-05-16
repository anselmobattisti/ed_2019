/*

  Exemplo com lista encadeada com implementações interativas

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* ins_fim(TLSE *l, int x);
TLSE* ins_ord(TLSE *l, int x);
TLSE* diferenca(TLSE* l1, TLSE* l2);
void imprime(TLSE*l);

int main(void) {
  TLSE *l1 = inicializa();
  l1 = ins_ini(l1, 10);
  l1 = ins_fim(l1, 14);
  l1 = ins_fim(l1, 20);
  l1 = ins_fim(l1, 15);

  TLSE *l2 = inicializa();
  l2 = ins_fim(l2, 20);
  l2 = ins_fim(l2, 15);
  l2 = ins_fim(l2, 5);

  TLSE *l3 = diferenca(l1, l2);
  imprime(l3);

  TLSE *l4 = diferenca(l2, l1);
  imprime(l4);

  for (int i = 0; i++; i<50){
    printf("%d",i);
  }
}

TLSE* diferenca(TLSE* l1, TLSE* l2) {

  if (!l1) return NULL;
  if (!l2) return l1;

  TLSE *l3 = inicializa();

  TLSE *p = l1, *q = NULL;

  while(p) {
    int d = 1;
    q = l2;
    while (q) {
      if (q->info == p->info) {
        d = 0;
        break;
      }
      q = q->prox;
    }
    if (d) {
      l3 = ins_fim(l3,p->info);
    }
    p = p->prox;
  }

  return l3;
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

TLSE* ins_fim(TLSE *l, int x) {
  if (!l) {
    return ins_ini(l,x);
  } else {
    TLSE *p = l;
    while(p->prox) {
      p = p->prox;
    }
    p->prox = ins_ini(p->prox,x);
    return l;
  }
}

TLSE* ins_ord(TLSE *l, int x) {
  if (!l) {
    return ins_ini(l,x);
  } else {
    TLSE *ant = NULL;
    TLSE *p = l;
    while(p && p->info < x) {
      ant = p;
      p = p->prox;
    }

    TLSE *novo = inicializa();
    novo = ins_ini(novo,x);
    novo->prox = p;
    ant->prox = novo;
    return l;
  }
}

TLSE* inicializa()  {
  return NULL;
}