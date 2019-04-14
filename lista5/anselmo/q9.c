/*
Q9) Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas
listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte:
TLSE* junta_listas (TLSE* l1, TLSE* l2).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_fim(TLSE *l, int x);
TLSE* junta_lista(TLSE *l1, TLSE *l2);
void imprime(TLSE*l);

int main(void) {
  TLSE *l1 = inicializa();
  TLSE *l2 = inicializa();

  l1 = ins_fim(l1, 1);
  l1 = ins_fim(l1, 2);
  l2 = ins_fim(l2, 3);
  l2 = ins_fim(l2, 4);
  l2 = ins_fim(l2, 5);

  printf("\nListas concatenadas:\n");
  imprime(junta_lista(l1,l2));

}

TLSE* junta_lista(TLSE *l1, TLSE *l2){
  TLSE *p = l1;
  while (p->prox) {
    p = p->prox;
  }
  p->prox = l2;
  return l1;
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


TLSE* ins_fim(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = NULL;

  if (!l) {
    return novo;
  }

  TLSE *p = l;
  while (p->prox) {
    p = p->prox;
  }

  p->prox = novo;

  return l;
}

TLSE* inicializa()  {
  return NULL;
}