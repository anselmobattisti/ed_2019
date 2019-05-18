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

  t = inserir(t,10);
  t = inserir(t,20);
  t = inserir(t,5);
  t = inserir(t,3);
  t = inserir(t,4);
  t = inserir(t,15);
  t = inserir(t,21);
  t = inserir(t,16);

  print_tree(t,"Original");
  printf("\nNúmero de folhas: %d\n",nf(t));
  printf("\nNúmero de nós internos: %d\n",ni(t));

  /*
  print_tree(t,"Original");
  print_tree(retira_pares(t),"Original");

  print_tree(t,"Original");
  t = retira(t,10);
  print_tree(t,"Original");

  TAB* copia = copiar(t);

  printf("Iguais? %d\n",igual(t,copia));

  print_tree(t,"Original");
  print_tree(espelho(t),"Espelho");

  print_tree(t,"Original");

  t = retira(t,20);
  print_tree(t,"Sem o 20");


  t = retira(t,4);
  t = retira(t,3);
  print2DUtil(t,0);
  printf("\n");


  printf("\nMaior");
  TAB* m = menor(t->esq);
  printf(" %d ",m->info);

  TAB *r = copiar(t);

  printf("\nOriginal");
  print2DUtil(t,10);
  printf("\n");
  printf("\nCópia");
  print2DUtil(r,10);
  printf("\n");

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
