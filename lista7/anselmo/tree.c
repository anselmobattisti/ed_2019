#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define COUNT 10

TAB* inicializa() {
  return NULL;
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

int altura(TAB* t){
  return 0;
}

TAB* maior(TAB* t) {

  if (!t) return NULL;

  TAB* maior_esq = maior(t->esq);
  TAB* maior_dir = maior(t->dir);
  TAB* resp = t;

  if (maior_esq && maior_esq->info > resp->info) {
    resp = maior_esq;
  }

  if (maior_dir && maior_dir->info > resp->info) {
    resp = maior_dir;
  }

  return resp;
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

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TAB *root, int space)
{
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