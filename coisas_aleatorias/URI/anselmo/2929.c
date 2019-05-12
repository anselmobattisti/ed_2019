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
int min_p(TPILHA *p);

int main() {
  int n = 0;
  char s[100];
  TPILHA *mp = cria();
  int min = 0;
  scanf("%d",&n);
  while(n--){
    scanf("%[^n]",s);
    printf("%s\n\n",s);
    if (strcmp(s,"PUSH 5")){
      int aux;
      scanf("%d",&aux);
      push(mp,aux);
      printf("%d------------",aux);
    }

    if (strcmp(s,"POP")){
      if(vazia(mp)) {
        printf("EMPTYa\n");
      } else {
        int k = pop(mp);
      }
      continue;
    }

    if (strcmp(s,"MIN")){
      if(vazia(mp)) {
        printf("EMPTYn\n");
      } else {
        printf("%d", min_p(mp));
      }
      continue;
    }
  }
  return 0;
}

int min_p(TPILHA *p) {
  TPILHA *aux;

  int min = 0;

  while (!vazia(p)){
    int k = pop(p);
    if (k < min) {
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
