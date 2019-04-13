/*
Q11) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, ordene os elementos de l em uma outra lista de saída. Portanto, a lista de
entrada não pode ser alterada. O protótipo da função desta função é o seguinte: TLSE *
ordena (TLSE* l).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_fim(TLSE *l, int x);
TLSE* ordena(TLSE *l1);
void imprime(TLSE*l);

int main(void) {
  TLSE *l1 = inicializa();

  l1 = ins_fim(l1, 5);
  l1 = ins_fim(l1, 4);
  l1 = ins_fim(l1, 3);
  l1 = ins_fim(l1, 2);
  l1 = ins_fim(l1, 1);

  printf("\nListas ordenadas:\n");
  imprime(l1);
  imprime(ordena(l1));

}

TLSE* ordena(TLSE *l){
  if (!l) return l;
  TLSE *p = l, *q = NULL;
  while (p) {
    q = p->prox;
    while (q) {
      if (p->info > q->info) {
        int t = p->info;
        p->info = q->info;
        q->info = t;
      }
      q = q->prox;
    }
    p = p->prox;
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