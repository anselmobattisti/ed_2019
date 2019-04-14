/*
LISTA CIRCULAR

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
}TLC;

TLC* inicializa();
TLC* ins_ini(TLC *l, int x);
void imprime(TLC*l);
TLC* desloca(TLC*l, int n);

int main(void) {
  TLC *l = inicializa();
  l = ins_ini(l, 1);
  l = ins_ini(l, 2);
  l = ins_ini(l, 3);
  l = ins_ini(l, 4);
  l = ins_ini(l, 5);

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

  l = desloca(l,1);
  printf("\nLista Descolada IMPAR:\n");
  imprime(l);
}

TLC* desloca(TLC*l, int n) {
  if (!l)
    return l;

  if (n%2 == 0) {
    return l->prox;
  } else {
    TLC *p = l;
    while (p->prox != l) {
      p = p->prox;
    }
    return p;
  }
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