#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* busca(TLSE* l, int x);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  l = ins_ini(l, 10);
  l = ins_ini(l, 14);
  l = ins_ini(l, 20);
  l = ins_ini(l, 21);

  imprime(l);
  l = busca(l, 20);
  imprime(l);
  l = busca(l, 14);
  imprime(l);
}

TLSE* busca(TLSE* l, int x) {
  if (!l) return NULL;

  TLSE *a = l, *ant = NULL;

  while (a) {
    if(a->info == x) {
      break;
    }
    ant = a;
    a = a->prox;
  }

  if (a && ant != NULL){
    if(a->prox == NULL) {
      ant->prox = NULL;
    } else {
      ant->prox = a->prox;
    }
    a->prox = l;
  }
  return a;
}

void imprime(TLSE*l) {
  printf("\nLista\n");
  if (l) {
    TLSE *p = l;
    while (p) {
      printf("%d - ", p->info);
      p = p->prox;
    }
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