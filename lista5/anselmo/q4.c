/*
Q4) Considere a existência de um tipo que representa um aluno numa universidade
hipotética:
typedef struct aluno {
int mat;
float cr;
struct aluno *prox;
}TAluno;
Escreva uma função que copie uma lista. A lista original deve permanecer inalterada. O
protótipo da função é o seguinte: TAluno *copia (TAluno *l).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  int mat;
  float cr;
  struct aluno *prox;

}TAluno;

TAluno* inicializa();
TAluno* ins_ini(TAluno *l, int mat, float cr);
TAluno *copia (TAluno *l);
void imprime(TAluno*l);

int main(void) {
  TAluno *l = inicializa();
  TAluno *n = inicializa();

  l = ins_ini(l, 1, 80);
  l = ins_ini(l, 2, 90);
  l = ins_ini(l, 1, 80);
  l = ins_ini(l, 3, 100);
  l = ins_ini(l, 1, 80);

  n = copia(l);

  printf("Lista Original.\n");
  l = ins_ini(l, 4, 70);
  imprime(l);


  printf("Lista Copiada.\n");
  imprime(n);
  return 0;
}


TAluno* inicializa() {
  return NULL;
}

TAluno* ins_ini(TAluno *l, int mat, float cr) {
  TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
  novo->mat = mat;
  novo->cr = cr;
  novo->prox = l;
  return novo;
}

TAluno *copia (TAluno *l) {
  TAluno *nl = inicializa();

  while(l) {
    nl = ins_ini(nl, l->mat, l->cr);
    l = l->prox;
  }

  return nl;
}

void imprime(TAluno*l) {
  while (l) {
    printf("\nFicha do aluno:\n");
    printf("Matrícula: %d\n",l->mat);
    printf("CR: %.0f\n\n",l->cr);
    l = l->prox;
  }
}

