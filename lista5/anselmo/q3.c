/*
Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
função é o seguinte: TLSE* desloca (TLSE* l, int n).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
TLSE* troca_cabeca(TLSE*l, int n);
TLSE* desloca(TLSE*l, int n);
void imprime(TLSE*l);
void ultimo_anterior(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);

  imprime(l);

  l = desloca(l,0);
  printf("\nLista Descolada PAR:\n");
  imprime(l);

  l = desloca(l,0);
  printf("\nLista Descolada PAR:\n");
  imprime(l);

  l = desloca(l,1);
  printf("\nLista Descolada IMPAR:\n");
  imprime(l);

  l = desloca(l,1);
  printf("\nLista Descolada IMPAR:\n");
  imprime(l);
}

void ultimo_anterior(TLSE*l) {
  TLSE *p = l, *ant = NULL;

  while (p->prox) {
    ant = p;
    p = p->prox;
  }

  printf("\n - Anterior: %d\n",ant->info);
  printf("\n - Último: %d\n",p->info);
}

TLSE* desloca(TLSE *l, int n) {
  TLSE *p = l, *ant = NULL;

  // Se p existir ao final do while
  // ele será o último elemento da lista
  while (p->prox) {
    ant = p;
    p = p->prox;
  }

  // a lista ou não tem elemento ou tem apenas 1 elemento;
  if (!p || !p->prox) return l;

  p->prox = l;
  if (n%2 == 0) {
    l = l->prox;
    p->prox->prox = NULL;
  } else {
    l = p;
    ant->prox = NULL;
  }
  return l;
}

TLSE* troca_cabeca(TLSE*l, int n) {

  TLSE* p = l, *q;

  /*
  Quero terminar a execução do while com
  q sendo o último elemento da lista
  */
  while (p) {
    q = p;
    p = p->prox;
  }

  if (n%2 == 1) {
    int tmp = q->info;
    q->info = l->info;
    l->info = tmp;
  } else {
    int tmp = l->info;
    l->info = q->info;
    q->info = tmp;
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