/*
LISTA CIRCULAR
Q1) Considerando as seguintes declarações de lista encadeada:
typedef struct lista{
int info;
struct lista *prox;
}TLSE;
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLSE* l);
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
void inverte(TLC*l);

int main(void) {
  TLC *l = inicializa();
  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);
  l = ins_ini(l, 5);

  inverte(l);
  imprime(l);
}

void inverte(TLC*l) {
  if (!l)
    return;

  TLC *atual, *ultimo, *p, *q;
  int total = 0;

  atual = l;
  p = l;

  while (atual->prox != p) {
    total++;
    atual = atual->prox;
  }

  ultimo = atual;
  atual = l;

  for (int i = 1; i <= (int)total/2; i++) {
    p = atual;
    q = p;
    while (p != ultimo) {
      q = p;
      p = p->prox;
    }

    int tmp = atual->info;
    atual->info = ultimo->info;
    ultimo->info = tmp;
    ultimo = q;
    atual = atual->prox;
  }
}

void imprime(TLC*l) {
  printf("\nLista");
  printf("\n-----\n");
  if (l) {
    TLC *p = l;
    do {
      printf("info: %d -> prox: %d \n", p->info, p->prox->info);
      p = p->prox;
    } while (p != l);
  }
  printf("-----\n");
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