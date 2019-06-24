#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct lista {
  int info;
  struct lista *prox;
}TLSE;

TLSE* inicializa_lista();
void imprime_lista(TLSE*l);
TLSE* ins_ini(TLSE *l, int x);

void pre(TAB* t);
TAB* espelho2 (TAB *a);
int maior2 (TAB *a);
int igual2 (TAB *a, TAB *b);
int nf2(TAB *a);
void ancestrais(TAB *a, int x);

int pares(TAB* a);

int estritamente_balanceada(TAB *a);

int apenas_um_filho(TAB *a);
int apenas_um_filho_aux(TAB *a);

int sucessor(TAB *a, int x);
void sucessor_aux(TAB *a, TLSE** maiores, int x);

int sucessor_ab(TAB *a, int x);
int sucessor_ab2(TAB *a, int x);

int ext(TAB* a);
int is_tabb(TAB *a);

int main(){
  TAB *t = inicializa();

  t = inserir(t,8);
  t = inserir(t,6);
  t = inserir(t,10);
  t = inserir(t,3);
  t = inserir(t,7);
  t = inserir(t,12);
  t = inserir(t,9);

  // print2DUtil(t,2);

  /*
  TAB* aux2 = espelho2(t);
  print2DUtil(aux2,2);

  TAB* aux3 = copiar(t);

  printf("%d",igual2(t,aux2));

  printf("\n\nFolhas:\n ----> %d \n\n",nf2(t)); */


  // int b = estritamente_balanceada(t);
  // printf("\n\n%d",b);

  // ancestrais(t,9);

  TAB *t2 = inicializa();

  t2 = inserir(t2,10);
  t2 = inserir(t2,20);
  t2 = inserir(t2,15);
  t2 = inserir(t2,11);
  t2 = inserir(t2,18);

  // print2DUtil(t2,2);
  //printf("\nSó um filho: %d\n\n",apenas_um_filho(t2));

  // printf("%d", sucessor(t2,10));

  TAB *t3 = inicializa();

  //t3 = inserir(t3,6);
  t3 = inserir(t3,4);
  t3 = inserir(t3,1);
  t3 = inserir(t3,2);

  print2DUtil(t,2);

  // printf("\n ab - %d", sucessor(t3,5));
  // printf("\n abb1 - %d", sucessor_ab(t3,5));
  // printf("\n abb2 - %d", sucessor_ab2(t3,5));

  // printf("\n pares - %d", pares(t3));
  // printf("\n ext - %d", ext(t3));

  //print2DUtil(t,0);
  //ancestrais(t,4);

  printf("\n TABB - %d", is_tabb(t));
}

int is_tabb_aux_maior(TAB *a, int k) {
  if (!a) return 0;
  if (a->info > k) return 1;
  return is_tabb_aux_maior(a->esq, k) && is_tabb_aux_maior(a->dir, k);
}

int is_tabb_aux_menor(TAB *a, int k) {
  if (!a) return 0;
  if (a->info < k) return 1;
  return is_tabb_aux_menor(a->esq, k) && is_tabb_aux_menor(a->dir, k);
}

int is_tabb(TAB *a) {

  if (!a) return 1;

  return !(is_tabb_aux_maior(a->esq, a->info) && is_tabb_aux_menor(a->dir, a->info));

}

int ext(TAB* a) {
  if (!a) return 1;
  if ((a->esq && !a->dir) || (!a->esq && a->dir)) return 0;
  return ext(a->esq) && ext(a->dir);
}

int pares(TAB* a) {
  if (!a) return 0;
  int p = 0;
  if (a->info % 2 == 0) p = 1;
  return pares(a->esq) + pares(a->dir) + p;
}


int sucessor_ab(TAB *a, int x) {
  while (a) {
    if (x == a->info) {
      if (a->dir == NULL) return x;
      return a->dir->info;
    }
    if (x > a->info) {
      a = a->dir;
    } else {
      a = a->esq;
    }
    sucessor_ab(a, x);
  }
  return -1;
}

int sucessor_ab2(TAB *a, int x) {
  if (!a) return -1;
  if (x == a->info) {
    if (a->dir == NULL) return x;
    return a->dir->info;
  }
  if (x > a->info) {
    sucessor_ab2(a->dir, x);
  } else {
    sucessor_ab2(a->esq, x);
  }
}

int sucessor(TAB *a, int x) {
  TLSE* maiores = inicializa_lista();
  sucessor_aux(a, &maiores, x);
  int menor = maiores->info;
  while(maiores->prox) {
    if (menor > maiores->info) {
      menor = maiores->info;
    }
    maiores = maiores->prox;
  }
  return menor;
}

void sucessor_aux(TAB *a, TLSE **maiores, int x) {

  if (!a) return;

  if (a->info > x) {
    *maiores = ins_ini(*maiores, a->info);
  }

  if (a->esq) {
    sucessor_aux(a->esq, maiores, x);
  }

  if (a->dir) {
    sucessor_aux(a->dir, maiores, x);
  }
}

int apenas_um_filho(TAB *a) {
  if (!a) return 0;
  return apenas_um_filho_aux(a->esq) && apenas_um_filho_aux(a->dir);
}

int apenas_um_filho_aux(TAB *a) {
  if (!a || (!a->esq && !a->dir)) {
    return 1;
  }
  if (a->esq && a->dir) {
    return 0;
  }

  if (a->esq) {
    return apenas_um_filho_aux(a->esq);
  }

  if (a->dir) {
    return apenas_um_filho_aux(a->dir);
  }
}

void ancestrais(TAB *a, int x) {
  if (!a) return;
  int val = -1;
  while (a) {
    val = a->info;
    printf("%d - ",val);
    if (x > val) {
      a = a->dir;
    } else {
      a = a->esq;
    }
  }
  if (val == x) {
    printf("Achou");
  }
}

int estritamente_balanceada(TAB *a) {
  if (!a) return 1;

  if (a->esq && !a->dir) return 0;
  if (!a->esq && a->dir) return 0;

  if (!a->esq && !a->dir) return 1;

  if (a->esq && a->dir) {
    return estritamente_balanceada(a->esq) && estritamente_balanceada(a->dir);
  }
}

int nf2(TAB *a) {
  if (!a) return 0;

  if (!a->dir && !a->esq) return 1;

  return nf2(a->esq) + nf2(a->dir);
}


int maior2 (TAB *a) {
  if (!a) return -1;

  int val = a->info;
  int maior = -1;
  int val_esq = -1;
  int val_dir = -1;

  if (a->esq)
    val_esq = maior2(a->esq);

  if (a->dir)
    val_dir = maior2(a->dir);

  if (val_esq > val_dir) {
    maior = val_esq;
  } else {
    maior = val_dir;
  }

  if (maior > val) {
    return maior;
  } else {
    return val;
  }
}

TAB* espelho2 (TAB *a) {
  if (!a) return NULL;

  TAB *aux = inicializa();
  aux = cria_no(a->info);
  aux->dir = espelho2(a->esq);
  aux->esq = espelho2(a->dir);

  return aux;
}

int igual2 (TAB *a, TAB *b){
  if (!a && !b) return 0;

  if ((!a && b) || (a && !b)) return 1;

  if ((!a->dir && b->dir) || (a->dir && !b->dir)) return 1;

  if ((!a->esq && b->esq) || (a->esq && !b->esq)) return 1;

  if (a->info != b->info) {
    return 1;
  } else {
    return igual2(a->esq, b->esq) && igual2(a->dir, b->dir);
  }
}

void pre(TAB* t) {
  if (!t) return;

  pre(t->esq);
  printf("%d - ",t->info);
  pre(t->dir);

}


TLSE* ins_ini(TLSE *l, int x) {
  TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = x;
  novo->prox = l;
  return novo;
}

TLSE* inicializa_lista()  {
  return NULL;
}

void imprime_lista(TLSE*l) {
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