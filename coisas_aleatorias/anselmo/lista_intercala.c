#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* ins_fim(TLSE *l, int x);

void imprime(TLSE*l);
void intercala(TLSE*l1, TLSE*l2);
TLSE* intercala_2(TLSE*l1, TLSE*l2);

int main(void) {
  TLSE *l1 = inicializa();
  l1 = ins_fim(l1, 40);
  l1 = ins_fim(l1, 30);
  l1 = ins_fim(l1, 20);
  l1 = ins_fim(l1, 10);

  TLSE *l2 = inicializa();
  l2 = ins_fim(l2, 41);

  TLSE *l3 = intercala_2(l1,l2);

  imprime(l3);
}

TLSE* intercala_2(TLSE*l1, TLSE*l2) {
  if (!l1) return l2;
  if (!l2) return l1;

  TLSE *l3 = inicializa();
  TLSE *a1 = l1, *a2 = l2;
  while (a1) {
    l3 = ins_fim(l3,a1->info);
    a1 = a1->prox;
    if (a2) {
      l3 = ins_fim(l3,a2->info);
      a2 = a2->prox;
    }
  }

  while(a2) {
    l3 = ins_fim(l3, a2->info);
    a2 = a2->prox;
  }

  return l3;
}

void intercala(TLSE*l1, TLSE*l2) {
  if (!l1) return;
  if (!l2) return;

  TLSE *a1 = l1, *a2 = l2, *aux;

  while (a2) {
    if (a1->prox) {
      aux = a2;
      a2 = a2->prox;
      aux->prox = a1->prox;
      a1->prox = aux;
      a1 = a1->prox->prox;
    } else {
      a1->prox = a2;
      break;
    }
  }
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


TLSE* inicializa()  {
  return NULL;
  //return (TLSE*) malloc(sizeof(TLSE));
}