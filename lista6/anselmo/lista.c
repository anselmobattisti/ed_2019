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

// - C
TFila* sep_fila (TFila *f);

// - D
TFila* Junta_Filas (TFila *f1, TFila *f2);

// - E
void retira_pares (TPilha *p);

// - F
TFila* p2f (TPilha *p);

// - G
void separa_filas(TFila * f, TFila *par, TFila * impar);

int main() {

  TFila *f = inicializa_fila();
  insere_fila(f,1);
  insere_fila(f,2);
  insere_fila(f,3);
  insere_fila(f,4);
  insere_fila(f,5);
  insere_fila(f,6);
  insere_fila(f,7);
  insere_fila(f,8);

  /*
  ====== A teste
  TPilha *p = f2p(f);
  imprime_pilha(p);
  */

  /*
  ====== B teste
  TFila *fa = inv_fila(f);
  imprime_fila(fa);
  */

  /*
  ====== C teste
  TFila *i = sep_fila(f);
  imprime_fila(f);
  imprime_fila(i);
  */

  /*
  ====== D teste
  TFila *i = sep_fila(f);
  imprime_fila(f);
  imprime_fila(i);

  TFila *f1 = inicializa_fila();
  insere_fila(f1,1);
  insere_fila(f1,2);

  TFila *f2 = inicializa_fila();
  insere_fila(f2,3);
  insere_fila(f2,4);
  insere_fila(f2,5);

  TFila *f3 = Junta_Filas(f1, f2);

  imprime_fila(f1);
  imprime_fila(f2);
  imprime_fila(f3);
  */


  /*
  TPilha *p = inicializa_pilha();
  push_pilha(p,1);
  push_pilha(p,2);
  push_pilha(p,3);
  push_pilha(p,4);
  ====== E teste
  retira_pares(p);
  imprime_pilha(p);
  */

  /*
  ====== F teste
  TFila *faux = p2f(p);
  imprime_pilha(p);
  imprime_fila(faux);
  */

  // - G teste

  TFila *fp = inicializa_fila();
  TFila *fi = inicializa_fila();
  separa_filas(f, fp, fi);

  imprime_fila(f);
  imprime_fila(fp);
  imprime_fila(fi);

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
  free(aux);
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

  free(aux_pilha);
  return aux_fila;
}

/*
(c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f,
e modifique a fila original (f) para que ela possua somente os elementos ímpares, respeitando
a ordem de entrada em f. A função deve obedecer o seguinte protótipo: TFila* sep_fila (TFila
*f);
*/
TFila* sep_fila (TFila *f) {
  TPilha *aux_impares = inicializa_pilha();
  TPilha *aux_pares = inicializa_pilha();
  TPilha *aux_aux = inicializa_pilha();
  TFila *i = inicializa_fila();

  while(!vazia_fila(f)) {
    int x = retira_fila(f);

    if (x%2 == 0) {
      push_pilha(aux_pares,x);
    } else {
      push_pilha(aux_impares,x);
    }
  }

  // inverte a ordem dos impares e coloca na nova fila
  while(!vazia_pilha(aux_impares)) {
    push_pilha(aux_aux,pop_pilha(aux_impares));
  }

  while (!vazia_pilha(aux_aux)) {
    insere_fila(i,pop_pilha(aux_aux));
  }

  // inverte a ordem dos impares e coloca na nova fila
  while(!vazia_pilha(aux_pares)) {
    push_pilha(aux_aux,pop_pilha(aux_pares));
  }

  while (!vazia_pilha(aux_aux)) {
    insere_fila(f,pop_pilha(aux_aux));
  }

  free(aux_aux);
  free(aux_impares);
  free(aux_pares);
  return i;
}

/*
(d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);
*/
TFila* Junta_Filas (TFila *f1, TFila *f2) {
  TFila *f3 = inicializa_fila();
  TFila *aux = inicializa_fila();

  while(!vazia_fila(f1)) {
    int x = retira_fila(f1);
    insere_fila(f3,x);
    insere_fila(aux,x);
  }

  // coloca de volta dos dados em f1
  while(!vazia_fila(aux)) {
    insere_fila(f1,retira_fila(aux));
  }

  while(!vazia_fila(f2)) {
    int x = retira_fila(f2);
    insere_fila(f3,x);
    insere_fila(aux,x);
  }

  // coloca de volta dos dados em f1
  while(!vazia_fila(aux)) {
    insere_fila(f2,retira_fila(aux));
  }

  free(aux);
  return f3;
}

/*
(e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);
*/
void retira_pares (TPilha *p) {
  TPilha *aux = inicializa_pilha();
  TPilha *aux_2 = inicializa_pilha();

  while(!vazia_pilha(p)) {
    int x = pop_pilha(p);
    if (x%2 == 0)
      push_pilha(aux,x);
  }

  while(!vazia_pilha(aux)) {
    push_pilha(aux_2,pop_pilha(aux));
  }

  while(!vazia_pilha(aux_2)) {
    push_pilha(p,pop_pilha(aux_2));
  }
  free(aux);
  free(aux_2);
}

/*
(f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p);
*/
TFila* p2f (TPilha *p) {
  TPilha *aux = inicializa_pilha();
  TFila *f = inicializa_fila();

  while(!vazia_pilha(p)) {
    int x = pop_pilha(p);
    push_pilha(aux,x);
    insere_fila(f,x);
  }

  while (!vazia_pilha(aux)) {
    push_pilha(p,pop_pilha(aux));
  }

  free(aux);
  return f;
}

/*
(g) implemente uma função que receba três filas, f, impares e pares, e separe todos os valores
guardados em f de tal forma que os valores pares são colocados na fila pares e os valores
ímpares na impares. Ao final da execução desta função, f permanecerá com todos os seus
elementos. O protótipo desta função é o seguinte: void separa_filas(TFila * f, TFila *par,
TFila * impar).
*/
void separa_filas(TFila * f, TFila *par, TFila * impar) {
  TPilha *aux = inicializa_pilha();
  TPilha *aux_2 = inicializa_pilha();

  while(!vazia_fila(f)) {
    int x = retira_fila(f);
    push_pilha(aux, x);

    if (x % 2 == 0) {
      insere_fila(par,x);
    } else {
      insere_fila(impar,x);
    }
  }

  while(!vazia_pilha(aux)){
    push_pilha(aux_2,pop_pilha(aux));
  }

  while(!vazia_pilha(aux_2)){
    insere_fila(f,pop_pilha(aux_2));
  }

  free(aux);
  free(aux_2);
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