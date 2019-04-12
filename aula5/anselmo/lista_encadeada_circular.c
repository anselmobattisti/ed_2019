#include <stdio.h>
#include <stdlib.h>

/*
  A estrutura é a mesma da lista encadeada,
  só que o "último elemento" aponta para o primeiro.
*/
typedef struct lc
{
  int info;
  struct lc *prox;
}TLC;

TLC* inicializa();
TLC* inserir_o1(TLC* l, int x);
TLC* inserir_on(TLC* l, int x);
TLC* retira(TLC* l, int x);

void libera(TLC* l);
void imprimir(TLC* l);

int main(void) {
  TLC *l = inicializa();

  l = inserir_o1(l, 10);
  l = inserir_o1(l, 20);
  l = inserir_o1(l, 30);
  l = inserir_on(l, 31);

  l = retira(l,31);

  // libera(l);
  imprimir(l);
  return 0;
}

TLC* retira(TLC* l, int x) {
  if (!l) return l;

  if (l->info == x && l == l->prox) {
    free(l);
    return NULL;
  }

  TLC *ant = l, *p = l->prox;

  while (p != ant && p->info != x) {
    ant = p;
    p = p->prox;
  }

  if (p == l && p->info != x)
    return l;

  if (p == l) {
    l = l->prox;
  }

  ant->prox = p->prox;
  free(p);
  return l;
}

void libera(TLC* l) {
  if (!l) return;

  if (l->prox == l) {
    free(l);
    return;
  }

  TLC *p = l->prox, *q;

  while (p != l) {
    q = p;
    p = p->prox;
    free(q);
  }
  free(l);
}

TLC* inserir_o1(TLC* l, int x){
  TLC *novo = (TLC*) malloc(sizeof(TLC));
  novo->info = x;
  if (!l) {
    novo->prox = novo;
    return novo;
  }

  novo->prox = l->prox;
  l->prox = novo;
  return l;
}

TLC* inserir_on(TLC* l, int x){
  TLC *novo = (TLC*) malloc(sizeof(TLC));
  novo->info = x;

  // lista vazia
  if (!l) {
    novo->prox = novo;
    return novo;
  }

  novo->prox = l;

  TLC* p = l->prox;
  // acha o final da lista e coloca ele apontando para o novo
  while (p->prox != l) {
    p = p->prox;
  }
  p->prox = novo;

  return l;
}

void imprimir(TLC* l) {
  if (!l) return;
  printf("%d - ",l->info);
  TLC *p = l->prox;
  while (p != l ){
    printf("%d - ",p->info);
    p = p->prox;
  }
}

TLC* inicializa() {
  return NULL;
}
