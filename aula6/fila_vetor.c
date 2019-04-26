#include <stdio.h>
#include <stdlib.h>

int MAX_TAM = 100;

typedef struct fila
{
  int *vet;
  int fim;
}TF;

TF* cria();
int vazia(TF *f);
void libera(TF *f);
void insere(TF *f, int x);
int retira(TF *f);
void imprime(TF *f);

int main() {

  TF *f = cria();

  if (vazia(f)) {
    printf("\nFila vazia.");
  }

  insere(f,1);

  if (!vazia(f)) {
    printf("\nFila não vazia.");
  }

  insere(f,2);
  insere(f,3);
  insere(f,4);

  imprime(f);

  return 0;
}


TF* cria() {
  TF* f = (TF*) malloc(sizeof(TF));
  f->vet = (int*) malloc(sizeof(int)*MAX_TAM);
  f->fim = -1;
  return f;
}

int vazia(TF *f) {
  return f->fim == -1;
}

void libera(TF *f) {
  free(f->vet);
  free(f);
}

void insere(TF *f, int x) {
  if (f->fim == MAX_TAM) {
    MAX_TAM *= 2;
    f->vet = realloc(f->vet, MAX_TAM);
  }

  f->vet[++f->fim] = x;
}

int retira(TF *f) {

  if (vazia(f)) exit(1);

  // a lista só tem 1 elemento;
  if (f->fim == 0) {
    f->fim = -1;
    return f->vet[0];
  }

  int aux = f->vet[0];
  for (int i = 0; i <= f->fim-1; i++) {
    f->vet[i] = f->vet[i+1];
  }

  f->fim--;
  return aux;
}


void imprime(TF *f) {
  printf("\n - Fila -");
  while (!vazia(f)) {
    printf("\n%d",retira(f));
  }
  printf("\n- - - \n");
}