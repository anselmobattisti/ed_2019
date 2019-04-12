#include <stdio.h>
#include <stdlib.h>

typedef struct tlse {
  int info;
  struct tlse* prox;
}TLSE;

TLSE* inicializa();
TLSE* insere(TLSE *l, int x);
TLSE* busca_rec(TLSE *l, int x);
void imprime_rec(TLSE *l);
void libera_rec(TLSE *l);
TLSE* retira_rec(TLSE *l, int x);
void ordena_rec(TLSE *l);

int main(void) {

  TLSE *l;
  l = inicializa();

  l = insere(l, 10);
  l = insere(l, 20);
  l = insere(l, 30);
  l = insere(l, 5);
  l = insere(l, 35);
  l = insere(l, 25);

  l = retira_rec(l, 20);

  // libera_rec(l);


  // imprime(busca_rec(l,100));

  ordena_rec(l);
  imprime_rec(l);

  //free(l);



  return 0;
}

void ordena_rec(TLSE *l) {
  if (!l) return;
  TLSE *menor = l, *q;

  for (q = l->prox; q; q = q->prox) {
    if (menor->info > q->info) {
      menor = q;
    }
  }

  if (menor != l) {
    int tmp = l->info;
    l->info = menor->info;
    menor->info = tmp;
  }
  ordena_rec(l->prox);
}

TLSE* retira_rec(TLSE *l, int x) {
  if (!l) return l;

  if (l->info == x) {
    TLSE *p = l;
    l = l->prox;
    free(p);
    return l;
  }
  l->prox = retira_rec(l->prox,x);
  return l;
}

void libera_rec(TLSE *l) {
  if(l) {
    libera_rec(l->prox);
    free(l);
  }
}

TLSE* inicializa() {
  return NULL;
}

TLSE* busca_rec(TLSE *l, int x) {

  if (l == NULL || l->info == x) {
    return l;
  }
  return busca_rec(l->prox, x);
}

TLSE* insere(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = l;
  return novo;
}

void imprime_rec(TLSE *l) {
  if (l) {
    printf("%d - ", l->info);
    imprime_rec(l->prox);
  }
}