/*
Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void* i_p ( TLSE *l).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_fim(TLSE *l, int x);
void i_p(TLSE* l);
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
  i_p(l);
  imprime(l);
}

void i_p(TLSE* l) {

  TLSE *lp, *li, *p = l, *aux;

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

  // imprime(li);
  // imprime(lp);

  // alterar todos os elementos da lista original
  // com base nas cópias
  p = li;
  aux = l;
  while (p) {
    aux->info = p->info;
    aux = aux->prox;
    p = p->prox;
  }

  p = lp;
  while (p) {
    aux->info = p->info;
    p = p->prox;
    aux = aux->prox;
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