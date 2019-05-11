#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no {
  char info;
  struct no *prox;
}TNO;

typedef struct pilha {
  TNO *prim;
}TPILHA;

TPILHA* cria();
int vazia(TPILHA *p);
void libera(TPILHA *p);
void push(TPILHA *p, char x);
char pop(TPILHA *p);
void imprime(TPILHA *p);
void push_face(TPILHA *p);

int main() {
  int n = 0;
  char s[100];
  TPILHA *mp = cria();
  push_face(mp);
  int total = 0;

  scanf("%d",&n);
  fgets(s,20,stdin);
  while(n >= 0){
    n--;
    char q0 = pop(mp);
    char q1 = pop(mp);
    char q2 = pop(mp);
    char q3 = pop(mp);

    fgets(s,20,stdin);

    // printf("\nPilha   = %c - %c - %c - %c ",q0,q1,q2,q3);
   // printf("\nEntrada = %c - %c - %c - %c",s[0],s[2],s[4],s[6]);

    if (s[0] == q0 && s[2] == q1 && s[4] == q2 && s[6] == q3) {
      total++;
    } else {
      push(mp, q3);
      push(mp, q2);
      push(mp, q1);
      push(mp, q0);
      push(mp, s[0]);
      push(mp, s[2]);
      push(mp, s[4]);
      push(mp, s[6]);
    }

    if (vazia(mp)) {
      push_face(mp);
    }

  }

  printf("%d\n",total);
  free(mp);

  return 0;
}

void push_face(TPILHA *p) {
  push(p,'F');
  push(p,'A');
  push(p,'C');
  push(p,'E');
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

void push(TPILHA *p, char x) {
  TNO *aux = (TNO*) malloc(sizeof(TNO));
  aux->info = x;
  aux->prox = p->prim;
  p->prim = aux;
}

char pop(TPILHA *p) {
  if (vazia(p)) {
    exit(1);
  }

  TNO *q = p->prim;
  int ret = q->info;

  p->prim = p->prim->prox;
  free(q);

  return ret;
}

void imprime(TPILHA *p) {

    TPILHA *aux = cria();

    printf("\n");
    while(!vazia(p)) {
      char c = pop(p);
      printf("%c .",c);
      push(aux,c);
    }

    while(!vazia(aux)) {
      push(p,pop(aux));
    }

    printf("\n");
}
