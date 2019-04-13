/*
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
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
void imprime(TLSE*l);
void inverte(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);
  //l = ins_ini(l, 5);
  inverte(l);
  imprime(l);
}

void inverte(TLSE*l) {
  if (!l)
    return;

  TLSE *atual, *ultimo, *p, *q;
  int total = 0;

  atual = l;
  p = l;

  while (atual->prox != NULL) {
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