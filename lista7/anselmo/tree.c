#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define COUNT 10

TAB* inicializa() {
  return NULL;
}

TAB* retira(TAB* t, int x) {

  if (t->info < x) {
    t->dir = retira(t->dir,x);
  }

  if (t->info > x) {
    t->esq = retira(t->esq,x);
  }

  // achou o nó
  if (t->info == x) {
    // primeira possibilidade, 0 filhos
    if (!t->esq && !t->dir) {
      free(t);
      return NULL;
    }

    // segunda possibilidade, 1 filho
    if (t->esq) {
      // pega o menor da esquerda
      TAB *maior_esq = maior(t->esq);
      t->info = maior_esq->info;
      t->esq = retira(t->esq,t->info);
      return t;
    }

    if (t->dir && !t->esq) {
      TAB *menor_dir = menor(t->dir);
      t->info = menor_dir->info;
      t->dir = retira(t->dir,t->info);
      return t;
    }
  }

  return t;
}

void libera(TAB* t) {
  if (t) {
    libera(t->esq);
    libera(t->dir);
    free(t);
  }
}

TAB* cria_no(int x) {
  TAB* aux = (TAB*) malloc(sizeof(TAB));
  aux->info = x;
  aux->esq = NULL;
  aux->dir = NULL;
}

TAB* copiar(TAB* t) {
  if (t) {
    TAB* aux = cria_no(t->info);
    aux->esq = copiar(t->esq);
    aux->dir = copiar(t->dir);
    return aux;
  } else {
    return NULL;
  }
}


void imprime_pre(TAB* t) {
  if (t) {
    printf(" %d, ",t->info);
    imprime_pre(t->esq);
    imprime_pre(t->dir);
  }
}

void imprime_pos(TAB* t) {
  if (t) {
    imprime_pos(t->esq);
    imprime_pos(t->dir);
    printf(" %d, ",t->info);
  }
}

void imprime_sim(TAB* t) {
  if (t) {
    imprime_sim(t->esq);
    printf(" %d, ",t->info);
    imprime_sim(t->dir);
  }
}

TAB* busca(TAB* t, int x) {

  if ((!t) || (t->info == x))
    return t;

  TAB* esq = busca(t->esq, x);

  if (esq)
    return esq;

  return busca(t->dir, x);
}

TAB* inserir(TAB* t, int x) {
  if (!t) {
    return cria_no(x);
  }

  if (t->info > x) {
    t->esq = inserir(t->esq, x);
  }

  if (t->info < x) {
    t->dir = inserir(t->dir, x);
  }

  return t;
}

int altura(TAB* t){
  if (!t->esq && !t->dir) return 0;

  int a_esq = 0;
  int a_dir = 0;

  if (t->esq)
    a_esq = altura(t->esq)+1;

  if (t->dir)
    a_dir = altura(t->dir)+1;

  if (a_esq > a_dir){
    return a_esq;
  } else {
    return a_dir;
  }
}

TAB* maior(TAB* t) {

  if (!t || (!t->esq && !t->dir)) return t;

  return maior(t->dir);
}

TAB* menor(TAB* t) {

  if (!t) return NULL;

  TAB* menor_esq = menor(t->esq);
  TAB* menor_dir = menor(t->dir);
  TAB* resp = t;

  if (menor_esq && menor_esq->info < resp->info) {
    resp = menor_esq;
  }

  if (menor_dir && menor_dir->info < resp->info) {
    resp = menor_dir;
  }

  return resp;
}

void print_tree(TAB* t, char* title) {
  printf("\n -----------> %s",title);
  print2DUtil(t,0);
  printf("\n <-----------\n");
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TAB *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->dir, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);

    // Process left child
    print2DUtil(root->esq, space);
}