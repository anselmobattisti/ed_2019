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


void retira_pares(TP *p){
    if(!p || pilha_vazia(p)) return;
    int x=pop(p);
    retira_pares(p);
    if(x%2!=0)
      push(p,x);
}


int main(int argc, char const *argv[]) {
    TP *p = inicializa_pilha();
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);
    push(p, 8);
    push(p, 11);
    push(p, 10);
    push(p, 13);

    retira_pares(p);

    imprime_pilha(p);		
    libera_pilha(p);

    return 0;
}