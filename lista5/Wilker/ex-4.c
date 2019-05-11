#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  int mat;
  float cr;
  struct aluno *prox;
}TAluno;

TAluno* inicializa();
TAluno* ins_ini(TAluno *l, int x);
TAluno *copia (TAluno* l);
TAluno *copia2 (TAluno* l);
void imprime(TAluno*l);

int main(void) {
  TAluno *l = inicializa();
  TAluno *p = inicializa();

  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 1);
  l = ins_ini(l, 3);
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);
  l = ins_ini(l, 4);  
  l = ins_ini(l, 2);
  l = ins_ini(l, 2);


  printf("\nLista Original:\n");
  imprime(l);   
  p=copia(l); 
  printf("\nLista p:\n");
  imprime(p);  
  return 0;
}

TAluno *copia (TAluno* l) {
  if(!l) return NULL;
  TAluno * p= (TAluno*)malloc(sizeof(TAluno));
  p->mat=l->mat;
  p->cr=l->cr;
  p->prox=copia(l->prox);
}



void imprime(TAluno*l) {
  printf("\nLista\n");
  if (l) {
    TAluno *p = l;
    while (p->prox) {
      printf("%d - ", p->mat);
      p = p->prox;
    }
    // imprime o últiom elemento da lista
    printf("%d - ", p->mat);
  }
  printf("\n\n");
}

TAluno* ins_ini(TAluno *l, int x) {
  TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
  novo->mat = x;
  novo->prox = l;
  novo->cr = 2;
  return novo;
}

TAluno* inicializa()  {
  return NULL;
}