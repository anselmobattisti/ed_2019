#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa();
TLSE* ins_ini(TLSE *l, int x);
void inverte(TLSE* l);
void imprime(TLSE*l);

int main(void) {
  TLSE *l = inicializa();
  TLSE *p = inicializa();
  TLSE *q = inicializa();

  l = ins_ini(l, 1);


  p = ins_ini(p, 2);
  p = ins_ini(p, 3);
  p = ins_ini(p, 4);
  p = ins_ini(p, 5);

  q = ins_ini(q, 5);
  q = ins_ini(q, 6);
  q = ins_ini(q, 7);
  q = ins_ini(q, 8);
  q = ins_ini(q, 9);
  

  printf("\nLista Original:\n");
  imprime(l);   
  printf("\nLista Invertida:\n");
  inverte(l);
  imprime(l);

  printf("\nLista Original:\n");
  imprime(p);   
  printf("\nLista Invertida:\n");
  inverte(p);
  imprime(p);

    printf("\nLista Original:\n");
  imprime(q);   
  printf("\nLista Invertida:\n");
  inverte(q);
  imprime(q);
  return 0;
}

void inverte(TLSE* l) {
    if(!l || !l->prox)return;
    TLSE *p = l, *q= l , *r= l;
    while(q->prox)
        q=q->prox;
    while(q->prox != p || q==p){
        while(r->prox!=q && r==q)
            r=r->prox;
    int tmp = p-> info;
    p->info = q-> info;
    q-> info = tmp;
    p=p-> prox;
    q = r;
    r=l;
    }
}


void imprime(TLSE*l) {
  printf("\nLista\n");
  if (l) {
    TLSE *p = l;
    while (p->prox) {
      printf("%d - ", p->info);
      p = p->prox;
    }
    // imprime o últiom elemento da lista
    printf("%d - ", p->info);
  }
  printf("\n\n");
}

TLSE* ins_ini(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = l;
  return novo;
}

TLSE* inicializa()  {
  return NULL;
}