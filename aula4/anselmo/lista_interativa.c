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
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  l = ins_ini(l, 10);
  l = ins_fim(l, 14);
  l = ins_fim(l, 20);
  l = ins_ord(l, 15);
  imprime(l);
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