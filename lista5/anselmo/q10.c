/*
Q10) Considerando a seguinte declaração de uma lista encadeada:
typedef struct lista{
int mat;
char nome[81];
float cr;
struct lista *prox;
}TL;
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 é a
inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
Contrario (TL *l1, TL *l2).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
  int mat;
  char nome[81];
  float cr;
  struct lista *prox;
}TLista;

TLista* inicializa();
TLista* ins_ini(TLista *l, int mat, char* nome, float cr);
TLista* ins_fim(TLista *l, int mat, char* nome, float cr);
void imprime(TLista*l);
int contrario(TLista *l1, TLista *l2);

int main() {

  TLista *l1 = inicializa();
  TLista *l2 = inicializa();

  l1 = ins_ini(l1, 1, "Anselmo", 100);
  l1 = ins_ini(l1, 2, "Pedro", 80);
  l1 = ins_ini(l1, 3, "Carlos", 80);

  l2 = ins_fim(l2, 1, "Anselmo", 100);
  l2 = ins_fim(l2, 2, "Pedro", 80);
  l2 = ins_fim(l2, 3, "Carloss", 80);

  if (contrario(l1, l2)) {
    printf("\nListas invertidas!\n");
  } else {
    printf("\nListas não invertidas!\n");
  }

  return 0;
}

int contrario(TLista *l1, TLista *l2) {

  TLista *p1 = l1, *p2 = l2;
  TLista *l_aux; // cópia invertida da linsta 2
  l_aux = inicializa();

  if (!l1 && !l2) return 1;

  while (p2) {
    l_aux = ins_ini(l_aux, p2->mat, p2->nome, p2->cr);
    p2 = p2->prox;
  }

  p2 = l_aux;
  while (p1 && p2) {
    if (p1->mat != p2->mat)
      return 0;

    if (p1->cr != p2->cr)
      return 0;

    // strcmp volta 0 se são iguais
    if (strcmp(p1->nome, p2->nome))
      return 0;

    p1 = p1->prox;
    p2 = p2->prox;
  }

  // se terminou uma lista mas não acabou a outra usa um XOR
  if (p1 == NULL ^ p2 == NULL){
    return 0;
  }

  return 1;
}

TLista* inicializa() {
  return NULL;
}

TLista* ins_ini(TLista *l, int mat, char* nome, float cr) {
  TLista *novo = (TLista*) malloc(sizeof(TLista));
  novo->mat = mat;
  strcpy(novo->nome, nome);
  novo->cr = cr;
  novo->prox = l;
  return novo;
}

TLista* ins_fim(TLista *l, int mat, char* nome, float cr) {
  TLista *novo = (TLista*) malloc(sizeof(TLista));
  TLista *p = l;

  novo->mat = mat;
  strcpy(novo->nome, nome);
  novo->cr = cr;
  novo->prox = NULL;

  if (!l)
    return novo;

  while (p->prox) {
    p = p->prox;
  }
  p->prox = novo;
  return l;
}

void imprime(TLista*l) {
  while (l) {
    printf("\nFicha do aluno:\n");
    printf("Matrícula: %d\n",l->mat);
    printf("Nome: %s\n",l->nome);
    printf("CR: %.0f\n\n",l->cr);
    l = l->prox;
  }
}
