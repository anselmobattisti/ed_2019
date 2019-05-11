#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *prox;
}TNO;

typedef struct pilha {
  TNO *prim;
}TPILHA;

TPILHA* cria();
int vazia(TPILHA *p);
void libera(TPILHA *p);
void push(TPILHA *p, int x);
int pop(TPILHA *p);
void imprime(TPILHA *p);

int main() {
  TPILHA *mp = cria();



  return 0;
}

TPILHA* cria() {
  TPILHA *p = (TPILHA*) malloc(sizeof(TPILHA));
  p->prim = NULL;
  return p;
}

int vazia(TPILHA *p) {
  return p->prim == NULL;
}

void libera(TPILHA *p) {
  TNO *q = p->prim;
  TNO *aux;

  while(!vazia(p)) {
    aux = q;
    q = q->prox;
    free(aux);
  }

  free(p);
}

void push(TPILHA *p, int x) {
  TNO *no = (TNO*) malloc(sizeof(TNO));
  no->info = x;
  no->prox = p->prim;
  p->prim = no;
}

int pop(TPILHA *p) {
  if (vazia(p)) {
    exit(1);
  }

  TNO *prim = p->prim;
  int x = prim->info;
  p->prim = p->prim->prox;

  free(prim);
  return x;
}
void imprime(TPILHA *p) {
    while(!vazia(p)) {
      printf("%d -> ",pop(p));
    }
}
