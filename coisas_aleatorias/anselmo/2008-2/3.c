#include <stdio.h>
#include <stdlib.h>

 struct lista {
   int info;
  struct lista *prox;
 };
 typedef struct lista Lista;

int* Copia_Lista(Lista* L, int* n);
Lista* insere(Lista *l, int x);
void imprime(Lista *l);

int main() {
  Lista *l = NULL;
  l = insere(l,10);
  l = insere(l,20);
  l = insere(l,30);
  l = insere(l,40);

  int n = 0;

  int *aux = Copia_Lista(l,&n);

  for (int i = 0; i < n; i++) {
    printf("%d + ",aux[i]);
  }

  imprime(l);
  return 0;
}

int* Copia_Lista(Lista* L, int* n) {
  int* aux = (int*) malloc(sizeof(int)**n);
  if (!L) return NULL;
  int i = 0;
  do {
    aux[i] = L->info;
    i++;
    L = L->prox;
  } while (L);

  *n = i;
  return aux;
}

Lista* insere(Lista *l, int x) {
  Lista *aux = (Lista*) malloc(sizeof(Lista));
  aux->info = x;
  aux->prox = l;
  return aux;
}

void imprime(Lista *l) {
  printf("\n");
  if (!l) return;

  do {
    printf("%d - ",l->info);
    l = l->prox;
  } while (l);

  printf("\n");
}
