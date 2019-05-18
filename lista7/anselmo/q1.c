/*
Dada a seguinte representação de uma árvore binária:
typedef struct ab{
int info;
struct ab *esq, *dir;
}TAB;
Escreva as seguintes funções:
*/

// (Q1) cópia de uma árvore: TAB* copia (TAB *a);

#include <stdio.h>
#include "tree.h"

int main() {
  TAB* t = inicializa();

  // 10,5,15,4,6,14,16
  t = cria_no(10);
  t->esq = cria_no(5);
  t->dir = cria_no(15);

  t->esq->esq = cria_no(4);
  t->esq->dir = cria_no(6);

  t->dir->esq = cria_no(14);
  t->dir->dir = cria_no(16);

  t->dir->dir->dir = cria_no(20);

  TAB *r = copiar(t);

  printf("\nOriginal");
  print2DUtil(t,10);
  printf("\n");
  printf("\nCópia");
  print2DUtil(r,10);
  printf("\n");

  /*
  TAB *r = busca(t,16);


  print2DUtil(t,10);

  printf("\nPré-ordem:");
  printf("\n--------\n");
  imprime_pre(t);
  printf("\n--------\n");

  printf("\nPós-ordem:");
  printf("\n--------\n");
  imprime_pos(t);
  printf("\n--------\n");

  printf("\nSimétrica: ## ordem crescente");
  printf("\n--------\n");
  imprime_sim(t);
  printf("\n--------\n");

  printf("%d",altura(t));
  */
}
