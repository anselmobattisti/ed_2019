#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caixa {
 int peso;
 char objeto[51];
}Caixa;

typedef struct no {
  Caixa *obj;
  struct no *prox;
}TNO;

typedef struct pilha {
  TNO *prim;
  int tam;
}Pilha;

Pilha* pilha_cria (void);
int pilha_tamanho (Pilha* p);
Caixa* pilha_topo (Pilha* p);
Caixa* pilha_pop (Pilha* p);
void pilha_push (Pilha* p, Caixa* x);
void pilha_libera (Pilha* p);
int Empilha_caixa(Pilha** dep, int n, Caixa* cx);
Caixa* cria_caixa (int peso, char *nome);

void imprime_deposito(Pilha** dep, int n);
void imprime_pilha(Pilha *p);
void imprime_caixa(Caixa *c);

int main() {

  int num_pilhas = 4;
  Pilha *pilhas[num_pilhas];
  for (int i = 0; i < num_pilhas; i++)
    pilhas[i] = pilha_cria();

  Empilha_caixa(pilhas, num_pilhas, cria_caixa(12, "Produto 12"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(5, "Produto 5"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(4, "Produto 4"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(14, "Produto 14"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(13, "Produto 13"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(12, "Produto 12"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(11, "Produto 11"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(10, "Produto 10"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(9, "Produto 9"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(8, "Produto 8"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(7, "Produto 7"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(6, "Produto 6"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(2, "Produto 2"));
  Empilha_caixa(pilhas, num_pilhas, cria_caixa(1, "Produto 1"));

  imprime_deposito(pilhas, num_pilhas);

  return 0;
}

void imprime_caixa(Caixa *c) {
  if (c == NULL) {
    printf("Sem caixa!");
  }

  printf("\n+------+---------+\n");
  printf("| peso | Nome\n");
  printf("+----+---------+\n");
  printf("| %d  | %s\n", c->peso, c->objeto);
  printf("+----+---------+\n");
}

void imprime_deposito(Pilha** dep, int n) {
  printf("\n--------Estoque  -------\n");
  for (int i = 0; i < n; i++) {
    printf("\nPilha %d\n",i);
    imprime_pilha(dep[i]);
  }
  printf("\n------------------------\n");
}

void imprime_pilha(Pilha *p) {
  if (p->tam == 0) {
    printf("\nPilha Vazia\n");
    return;
  }
  TNO *aux = p->prim;
  printf("\nTamanho: %d",p->tam);
  while (aux) {
    Caixa *c = aux->obj;
    printf("\n%s -> %d",c->objeto, c->peso);
    aux = aux->prox;
  }
  printf("\n");
}

int Empilha_caixa(Pilha** dep, int n, Caixa* cx) {
  for (int i = 0; i < n; i++) {
    Caixa *c = pilha_topo(dep[i]);
    if (c == NULL || (c->peso > cx->peso && dep[i]->tam < 8)) {
      pilha_push(dep[i],cx);
      return i;
    }
  }
  return -1;
}

Caixa* cria_caixa (int peso, char *nome) {
  Caixa *c = (Caixa*) malloc(sizeof(Caixa));
  c->peso = peso;
  strcpy(c->objeto, nome);
  return c;
}

Pilha* pilha_cria (void) {
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->prim = NULL;
  p->tam = 0;
  return p;
}

int pilha_tamanho (Pilha* p) {
  return p->tam;
}

Caixa* pilha_topo (Pilha* p) {

  if (p->tam == 0)
    return NULL;

  TNO *q = p->prim;
  while (q->prox){
    q = q->prox;
  }
  return q->obj;
}

Caixa* pilha_pop (Pilha* p) {
  if (p->tam == 0)
    return NULL;

  TNO *q = p->prim;
  TNO *ant = NULL;
  while (q->prox){
    ant = q;
    q = q->prox;
  }

  Caixa *c = q->obj;
  free(q);

  if (ant != NULL) {
    ant->prox = NULL;
  }

  p->tam--;
  return c;
}

void pilha_push (Pilha* p, Caixa* x) {
  TNO *no = (TNO*) malloc(sizeof(TNO));
  no->obj = x;
  no->prox = NULL;
  if (p->tam == 0) {
    p->prim = no;
  } else {
    TNO *aux = p->prim;
    while (aux->prox) {
      aux = aux->prox;
    }
    aux->prox = no;
  }
  p->tam++;
}

void pilha_libera (Pilha* p) {
  TNO *aux = p->prim;
  TNO *q;
  while (aux) {
    q = aux;
    aux = aux->prox;
    free(q);
  }
  free(p);
}