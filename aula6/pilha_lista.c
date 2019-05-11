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
void ordena_2(TP *p);

int main() {
  TP *p = cria();

  // if (vazia(p))printf("\nPilha Vazia.\n");

  push(p,1);
  push(p,6);
  push(p,5);
  push(p,3);
  push(p,4);
  push(p,2);

  ordena_2(p);

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

void ordena_2(TP *p) {
  printf("\nORDENA COM DUAS PILHAS\n");

  TP *a1 = cria();
  int ja_ordenado = 0;
  int total = 0;

  // p vazio, tudo no a1 e conta o total
  while (!vazia(p)) {
    push(a1, pop(p));
    total++;
  }

  int menor;

  while (1) {

    menor = pop(a1);

    // para iniciar a contagem novamente
    int total_aux = total - 1;

    // ver qual o menor em p
    while(total_aux > ja_ordenado) {
      int x = pop(a1);
      if (menor <= x) {
        push(p,x);
      } else {
        push(p,menor);
        menor = x;
      }
      total_aux--;
    }


    total_aux = total - 1;
    while(total_aux > ja_ordenado) {
      push(a1, pop(p));
      total_aux--;
    }

    // coloca o menor em p
    push(p,menor);
    ja_ordenado++;

    printf("\nmenor %d",menor);

    if (vazia(a1)){
      return;
    }
  }
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



