#include <stdio.h>
#include <stdlib.h>
// ==========================================
typedef struct no {
  int info;
  struct no *prox;
}TNO;

typedef struct fila
{
  TNO *ini, *fim;
}TF;


TF* inicializa_fila() {
  TF *f = (TF*) malloc(sizeof(TF));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

int fila_vazia(TF *f) {
  return f->ini == NULL;
}

void libera_fila(TF *f) {
  TNO *q = f->ini, *t;

  while (q) {
    t = q;
    q = q->prox;
    free(t);
  }
  free(f);
}

TF* insere(TF *f, int x) {
  TNO *n = (TNO*) malloc(sizeof(TNO));
  n->info = x;
  n->prox = NULL;
  if(fila_vazia(f)) {
    f->ini = n;
    f->fim = n;
  } else {
    f->fim->prox = n;
    f->fim = n;
  }
}

int retira(TF *f) {
  if (fila_vazia(f)) {
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

void imprime_fila(TF *f) {
  printf("- Fila -\n");
  while (!fila_vazia(f)) {
    printf("%d -> ",retira(f));
  }
  printf("//\n- - - \n");
}



// ==========================================

// ******************************************
typedef struct pilha
{
  TNO *prim;
}TP;


TP* inicializa_pilha() {
  TP *p = (TP*) malloc(sizeof(TP));
  p->prim = NULL;
  return p;
}

int pilha_vazia(TP *p) {
  return p->prim == NULL;
}

void push(TP *p, int x) {

  TNO *aux = (TNO*) malloc(sizeof(TNO));
  aux->info = x;
  aux->prox = p->prim;
  p->prim = aux;

}

int pop(TP *p) {
  if (pilha_vazia(p)) {
    exit(1);
  }

  TNO *q = p->prim;
  int ret = q->info;

  p->prim = p->prim->prox;
  free(q);

  return ret;
}

void libera_pilha(TP *p) {
  TNO *q = p->prim, *t;

  while(q) {
    t = q;
    q = q->prox;
    free(t);
  }

  free(p);
}

void imprime_pilha(TP *p) {
  printf("\n - Pilha -");
  while (!pilha_vazia(p)) {
    printf("\n%d",pop(p));
  }
  printf("\n- - - \n");
}


// ******************************************


void separa_filas(TF *f, TF *par,TF *impar){
    if(!f) return;
    if(fila_vazia(f)) return;
    int x = retira(f);
    separa_filas(f,par,impar);
    if(x%2==0)
      insere(par,x);
    else
     insere(impar,x);
    insere(f,x);
}


int main(int argc, char const *argv[]) {
    TF *f = inicializa_fila();
    TF *p = inicializa_fila();
    TF *i = inicializa_fila();
    insere(f, 2);
    insere(f, 3);
    insere(f, 5);
    insere(f, 7);
    insere(f, 11);
    insere(f, 13);
    insere(f,102);
    insere(f,103);
    insere(f,105);
    insere(f,107);
    insere(f,108);
    insere(f,109);

    separa_filas(f,p,i);
 
    imprime_fila(f);
    imprime_fila(p);
    imprime_fila(i);

    libera_fila(f);
    libera_fila(p);
    libera_fila(i);
    return 0;
}