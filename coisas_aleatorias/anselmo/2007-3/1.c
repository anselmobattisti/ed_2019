#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista* prox;
}Lista;

Lista* insere (Lista* L, int x);
Lista* dif (Lista* L, Lista* M);
void imprime (Lista* L);

int main(void) {
  Lista *L = NULL;
  Lista *M = NULL;

  L = insere(L, 1);
  L = insere(L, 2);
  L = insere(L, 3);
  L = insere(L, 4);
  L = insere(L, 5);

  M = insere(M,5);
  M = insere(M,1);
  M = insere(M,2);
  M = insere(M,4);

  imprime(L);

  L = dif(L, M);

  imprime(L);

  return 0;
}

Lista* insere (Lista* L, int x) {
  Lista *aux = (Lista*) malloc(sizeof(Lista));
  aux->info = x;
  aux->prox = L;
  return aux;
}

Lista* dif (Lista* L, Lista* M) {

  if (!L || !M) return L;

  Lista *p = L, *ant = NULL, *q = NULL, *aux;

  while (p) {
    q = M;
    while (q) {
      if (q->info == p->info) {
        aux = p;
      }
      q = q->prox;
    }

    if (aux) {
      if (aux == L) {
        L = L->prox;
      }

      if (ant) {
        ant->prox = aux->prox;
      }
      free(aux);
      aux = NULL;
    } else {
      ant = p;
    }
    p = p->prox;
  }

  return L;
}

void imprime (Lista* L) {
  if (!L) return;
  printf("Lista\n");
  do {
    printf("%d - ",L->info);
    L = L->prox;
  } while(L);
  printf("\n");
}