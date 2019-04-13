/*
Q5) Considerando a definição de lista de Q1, escreva uma função em C que remova
todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é
o seguinte: TLSE* rto (TLSE* l, int elem).*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* rto (TLSE* l, int elem);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 1);
  l = ins_ini(l, 3);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 4);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);

  printf("\nLista Original:\n");
  imprime(l);

  printf("\nLista Sem o 2:\n");
  imprime(rto(l,2));
}

TLSE* rto (TLSE* l, int elem) {
  if (!l) return l;

  TLSE *p = l, *ant = NULL, *aux = NULL;

  while (p) {

    if (p->info == elem) {
      aux = p;
      if (ant) {
        ant->prox = p->prox;
      } else {
        l = l->prox;
      }
    } else {
      ant = p;
    }

    p = p->prox;
    if (aux) {
      free(aux);
      aux = NULL;
    }
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