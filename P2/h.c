#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limite = 10;

typedef struct aluno {
  int cod;
  char nome[30];
  struct aluno* prox;
}TALUNO;

int inserir(TALUNO*, TALUNO**);
void imprimir(TALUNO**);
TALUNO* criar(int, char*);

int main() {
  TALUNO* alunos[10];
  for(int i = 0; i < limite; i++) {
    alunos[i] = (TALUNO*) malloc(sizeof(TALUNO));
    alunos[i] = criar(0,"");
  }

  TALUNO* a1 = criar(15,"Maria") ;
  TALUNO* a2 = criar(20,"Pedro") ;
  TALUNO* a3 = criar(3,"Paulo") ;
  TALUNO* a4 = criar(2,"Antônio") ;
  TALUNO* a5 = criar(2,"Cleber") ;

  inserir(a1, alunos);
  inserir(a2, alunos);
  inserir(a3, alunos);
  inserir(a4, alunos);
  inserir(a5, alunos);

  imprimir(alunos);
}

void imprimir(TALUNO** alunos) {
  for(int i = 0; i < limite; i++) {
    TALUNO* aux = alunos[i];
    printf("\nChave %d",i);
    if (aux->cod != 0) {
      while (aux) {
        printf("\n%d = %s",aux->cod, aux->nome);
        aux = aux->prox;
      }
      printf("\n--------\n");
    }
  }
}

int inserir(TALUNO* aluno, TALUNO** alunos) {
  int pos = aluno->cod % limite;
  if (alunos[pos]->cod == 0) {
    alunos[pos] = aluno;
  } else {
    // insere no fim
    TALUNO* aux = alunos[pos];
    while (aux->prox){
      aux = aux->prox;
    }
    aux->prox = aluno;
  }

  return pos;
}

TALUNO* criar(int cod, char* nome) {
  TALUNO* aluno = (TALUNO*) malloc(sizeof(TALUNO));
  aluno->cod = cod;
  strcpy(aluno->nome,nome);
  return aluno;
}
