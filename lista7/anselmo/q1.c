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
#include <stdlib.h>
#include "tree.h"

int main() {
  TAB* t = inicializa();
  printf("%d",altura(t));
}
