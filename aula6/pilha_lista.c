#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *prox;
}TNO;

typedef struct pilha
{
  TNO *prim;
}TP;

TP* cria();
int vazia(TP *p);
void libera(TP *p);
void push(TP *p, int x);
int pop(TP *p);
void ordena(TP *p);
void imprime(TP *p);

int main() {
  TP *p = cria();

  if (vazia(p)){
    printf("\nPilha Vazia.\n");
  }

  push(p,1);
  push(p,2);
  push(p,3);
  push(p,4);
  push(p,5);
  push(p,6);

  if (!vazia(p)){
    printf("\nPilha Populada.\n");
  }

  ordena(p);

  imprime(p);

  return 0;
}

TP* cria() {
  TP *p = (TP*) malloc(sizeof(TP));
  p->prim = NULL;
}

int vazia(TP *p) {
  return p->prim == NULL;
}

void push(TP *p, int x) {

  TNO *aux = (TNO*) malloc(sizeof(TNO));
  aux->info = x;
  aux->prox = p->prim;
  p->prim = aux;

}

int pop(TP *p) {
  if (vazia(p)) {
    exit(1);
  }

  TNO *q = p->prim;
  int ret = q->info;

  p->prim = p->prim->prox;
  free(q);

  return ret;
}

void libera(TP *p) {
  TNO *q = p->prim, *t;

  while(q) {
    t = q;
    q = q->prox;
    free(t);
  }

  free(p);
}

void ordena(TP *p) {

  TP *a1 = cria();
  TP *a2 = cria();

  while (!vazia(p)) {

    int menor = pop(p);

    while(!vazia(p)) {
      int x = pop(p);

      if (menor <= x) {
        push(a1,x);
      } else {
        push(a1,menor);
        menor = x;
      }
    }
    push(a2, menor);

    while(!vazia(a1)) {
      push(p,pop(a1));
    }

  }

  while(!vazia(a2)) {
    push(p,pop(a2));
  }

  free(a1);
  free(a2);
}

void imprime(TP *p) {
  printf("\n - Pilha -");
  while (!vazia(p)) {
    printf("\n%d",pop(p));
  }
  printf("\n- - - \n");
}



