/*
Q6) Considerando a definição de lista de Q1, escreva uma função em C que, dada uma
lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares
da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta
função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os
pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus
elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_fim(TLSE *l, int x);
TLSE* i_p(TLSE* l);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();

  l = ins_fim(l, 1);
  l = ins_fim(l, 2);
  l = ins_fim(l, 3);
  l = ins_fim(l, 4);
  l = ins_fim(l, 5);

  printf("\nLista Original:\n");
  imprime(l);

  printf("\nPrimeiro impar depois par:\n");
  imprime(i_p(l));
}

TLSE* i_p(TLSE* l) {

  TLSE *lp, *li, *p = l;

  lp = inicializa();
  li = inicializa();

  while (p) {
    if (p->info % 2 == 1) {
      li = ins_fim(li, p->info);
    } else {
      lp = ins_fim(lp, p->info);
    }
    p = p->prox;
  }

  // unir as duas listas
  // encontra o último elementos dos ímpares
  // aponta o próximo desse elemento
  // para o primeiro dos pares
  p = li;
  while (p->prox) {
    p = p->prox;
  }

  p->prox = lp;

  return li;
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


TLSE* ins_fim(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = NULL;

  if (!l) {
    return novo;
  }

  TLSE *p = l;
  while (p->prox) {
    p = p->prox;
  }

  p->prox = novo;

  return l;
}

TLSE* inicializa()  {
  return NULL;
}