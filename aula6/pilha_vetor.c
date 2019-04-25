#include <stdio.h>
#include <stdlib.h>

int MAX_TAM = 100;

typedef struct pilha
{
  int *vet;
  int pos_livre;
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
  TP *aux = (TP*) malloc(sizeof(TP));
  aux->pos_livre = 0;
  aux->vet = (int*) malloc(sizeof(int)*MAX_TAM);
  return aux;
}

int vazia(TP *p) {
  return p->pos_livre == 0;
}

void push(TP *p, int x) {

  if (p->pos_livre == MAX_TAM) {
    MAX_TAM *= 2;
    p->vet = realloc(p->vet,MAX_TAM);
  }

  // colocar na última posição livre
  p->vet[p->pos_livre++] = x;
}

int pop(TP *p) {
  if (vazia(p)) {
    exit(1);
  }

  return p->vet[--p->pos_livre];
}

void libera(TP *p) {
  free(p->vet);
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



