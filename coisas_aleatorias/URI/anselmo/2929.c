#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  long info;
  struct no *prox;
}TNO;

typedef struct pilha {
  TNO *prim;
}TPILHA;

TPILHA* cria();
int vazia(TPILHA *p);
void libera(TPILHA *p);
void push(TPILHA *p, long x);
long pop(TPILHA *p);
void imprime(TPILHA *p);
int min_p(TPILHA *p);

int main() {
  int n = 0;
  char s[100];
  long menor = -1;
  TPILHA *mp = cria();

  scanf("%d",&n);

  while (n--) {
    scanf(" %[^\n]",s);

    if (s[0] == 'M') {
      if(!vazia(mp)) {
        printf("%ld\n",menor);
      } else {
        printf("EMPTY\n");
      }
    } else if(s[1] == 'O') {
      if(!vazia(mp)){
        int k = pop(mp);
        if (k == menor)
          menor = min_p(mp);
      } else {
        printf("EMPTY\n");
      }
    } else {
      int v = atoi(&s[5]);
      if (v < menor || menor == -1)
        menor = v;
      push(mp,v);
    }
  }

  return 0;
}


int min_p(TPILHA *p) {
  TPILHA *aux = cria();
  int min = -1;

  while (!vazia(p)){
    int k = pop(p);
    if (k < min || min == -1) {
      min = k;
    }
    push(aux,k);
  }

  while (!vazia(aux)){
    push(p, pop(aux));
  }

  return min;
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

void push(TPILHA *p, long x) {
  TNO *aux = (TNO*) malloc(sizeof(TNO));
  aux->info = x;
  aux->prox = p->prim;
  p->prim = aux;
}

long pop(TPILHA *p) {
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
