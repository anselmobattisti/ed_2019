#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *prox;
}TNO;

typedef struct fila
{
  TNO *ini, *fim;
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

  imprime(f);

  return 0;
}

TF* cria() {
  TF *f = (TF*) malloc(sizeof(TF));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

int vazia(TF *f) {
  return f->ini == NULL;
}

void libera(TF *f) {
  TNO *q = f->ini, *t;

  while (q) {
    t = q;
    q = q->prox;
    free(t);
  }
  free(f);
}

void insere(TF *f, int x) {
  TNO *n = (TNO*) malloc(sizeof(TNO));
  n->info = x;
  if(vazia(f)) {
    f->ini = n;
    f->fim = n;
  } else {
    f->fim->prox = n;
    f->fim = n;
  }
}

int retira(TF *f) {
  if (vazia(f)) {
    exit(1);
  }

  int resp = f->ini->info;

  TNO *q = f->ini;

  f->ini = f->ini->prox;

  // SE FOR O FIM DA FILA
  if (!f->ini) f->fim =  NULL;
  free(q);

  return resp;
}

void imprime(TF *f) {
  printf("\n - Fila -");
  while (!vazia(f)) {
    printf("\n%d",retira(f));
  }
  printf("\n- - - \n");
}