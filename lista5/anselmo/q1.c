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
TLSE* inverte(TLSE*l);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  l = ins_ini(l, 5);
  l = ins_ini(l, 4);
  l = ins_ini(l, 3);
  l = ins_ini(l, 2);
  l = ins_ini(l, 1);
  l = inverte(l);
  imprime(l);
}

TLSE* inverte(TLSE*l) {
  if ((!l) || (l->prox == NULL))
    return NULL;

  int n = 0;
  TLSE *ultimo = (TLSE*) malloc(sizeof(TLSE));
  TLSE *ant, *p;

  p = l;

  while (p->prox) {
    n++;
    ant = p;
    p = p->prox;
  }

  ultimo = p;
  ultimo->prox = ant;

  while (n > 1) {
    n--;
    p = l;
    while (p->prox != ant) {
      p = p->prox;
    }
    ant->prox = p;
    ant = p;
    //printf("\n%d -> %d\n",n, ant->info);
  }

  l->prox = NULL;

  return ultimo;
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