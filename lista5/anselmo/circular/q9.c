/*
LISTA CIRCULAR

Q9) Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas
listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte:
TLSE* junta_listas (TLSE* l1, TLSE* l2).

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLC;

TLC* inicializa();
TLC* ins_ini(TLC *l, int x);
void imprime(TLC*l);
TLC* junta_lista(TLC *l1, TLC *l2);

int main(void) {
  TLC *l1 = inicializa();
  TLC *l2 = inicializa();

  l1 = ins_ini(l1, 10);
  l1 = ins_ini(l1, 1);
  l1 = ins_ini(l1, 2);
  l2 = ins_ini(l2, 3);
  l2 = ins_ini(l2, 4);
  l2 = ins_ini(l2, 5);

  printf("\nListas concatenadas:\n");
  imprime(junta_lista(l1,l2));
}

TLC* junta_lista(TLC *l1, TLC *l2){

  TLC *p = l1, *aux1 = NULL;

  while (p->prox != l1) {
    p = p->prox;
  }

  // aponta o fim de l1 para o começo de l2
  p->prox = l2;

  p = l2;
  while (p->prox != l2) {
    p = p->prox;
  }

  // aponta o fim de l2 para o começo de l1
  p->prox = l1;

  return l1;
}

void imprime(TLC*l) {
  printf("\nLista");
  printf("\n-----\n");
  if (l) {
    TLC *p = l;
    do {
      printf("%d -> ", p->info);
      p = p->prox;
    } while (p != l);
  }
  printf("INICIO \n-----\n");
}

TLC* ins_ini(TLC *l, int x) {
  TLC *novo = (TLC*) malloc(sizeof(TLC));
  novo->info = x;
  if (!l) {
    novo->prox = novo;
    return novo;
  } else {
    novo->prox = l->prox;
    l->prox = novo;
    return l;
  }
}

TLC* inicializa()  {
  return NULL;
}