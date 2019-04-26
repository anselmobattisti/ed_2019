/*
  Todos os exercícos serão feitos no mesmo arquivo
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *prox;
}TNO;

// PILHA
typedef struct pilha
{
  TNO *prim;
}TPilha;

TPilha * inicializa_pilha ();
void push_pilha (TPilha *p, int elem);
int pop_pilha (TPilha *p);
void libera_pilha (TPilha *p);
int vazia_pilha (TPilha *p);
void imprime_pilha (TPilha *p);

// FILA
typedef struct fila
{
  TNO *ini, *fim;
}TFila;

TFila* inicializa_fila ();
TFila* insere_fila (TFila *f, int elem);
int retira_fila (TFila *f);
void libera_fila (TFila *f);
int vazia_fila (TFila *f);
void imprime_fila (TFila *f);

// EXERCÍCIOS
// - A
TPilha* f2p (TFila *f);

// - B
TFila* inv_fila (TFila *f);

int main() {

  TFila *f = inicializa_fila();
  insere_fila(f,1);
  insere_fila(f,2);
  insere_fila(f,3);
  /*
  ====== A
  TPilha *p = f2p(f);
  imprime_pilha(p);
  */

  /*
  ====== B
  TFila *fa = inv_fila(f);
  imprime_fila(fa);
  */

  return 0;
}

/*
(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);
*/
TPilha* f2p (TFila *f) {
  TPilha *p = inicializa_pilha();
  TPilha *aux = inicializa_pilha();

  while(!vazia_fila(f)) {
    push_pilha(aux,retira_fila(f));
  }

  while (!vazia_pilha(aux)) {
    push_pilha(p,pop_pilha(aux));
  }
  return p;
}

/*
(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);
*/
TFila* inv_fila (TFila *f) {
  TPilha *aux_pilha = inicializa_pilha();
  TFila *aux_fila = inicializa_fila();

  while(!vazia_fila(f)){
    push_pilha(aux_pilha,retira_fila(f));
  }

  while(!vazia_pilha(aux_pilha)){
    insere_fila(aux_fila, pop_pilha(aux_pilha));
  }

  return aux_fila;
}

////////////////////////// IMPLEMENTAÇÕES DAS FUNÇÕES BÁSICAS
TPilha * inicializa_pilha () {
  TPilha *p = (TPilha*) malloc(sizeof(TPilha));
  p->prim = NULL;
}

void push_pilha (TPilha *p, int elem) {
  TNO *aux = (TNO*) malloc(sizeof(TNO));
  aux->info = elem;
  aux->prox = p->prim;
  p->prim = aux;
}

int pop_pilha (TPilha *p){
  if (vazia_pilha(p))exit(1);
  TNO *q = p->prim;
  int ret = q->info;
  p->prim = p->prim->prox;
  free(q);
  return ret;
}

void libera_pilha (TPilha *p) {
  TNO *q = p->prim, *t;
  while(q) {
    t = q;
    q = q->prox;
    free(t);
  }
  free(p);
}

int vazia_pilha (TPilha *p) {
  return p->prim == NULL;
}

void imprime_pilha (TPilha *p) {
  if (vazia_pilha(p)) return;
  printf("\n - Pilha -");
  while (!vazia_pilha(p)) {
    printf("\n%d",pop_pilha(p));
  }
  printf("\n- - - \n");
}

TFila* inicializa_fila () {
  TFila *f = (TFila*) malloc(sizeof(TFila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

TFila* insere_fila (TFila *f, int elem) {
  TNO *n = (TNO*) malloc(sizeof(TNO));
  n->info = elem;
  if(vazia_fila(f)) {
    f->ini = n;
    f->fim = n;
  } else {
    f->fim->prox = n;
    f->fim = n;
  }
}

int retira_fila (TFila *f) {
  if (vazia_fila(f)) exit(1);

  int resp = f->ini->info;

  TNO *q = f->ini;

  f->ini = f->ini->prox;

  // SE FOR O FIM DA FILA
  if (!f->ini) f->fim =  NULL;
  free(q);

  return resp;
}

void libera_fila (TFila *f) {
  TNO *q = f->ini, *t;

  while (q) {
    t = q;
    q = q->prox;
    free(t);
  }
  free(f);
}

int vazia_fila (TFila *f) {
  return f->ini == NULL;
}

void imprime_fila (TFila *f) {
  printf("\n - Fila -");
  while (!vazia_fila(f)) {
    printf("\n%d",retira_fila(f));
  }
  printf("\n- - - \n");
}