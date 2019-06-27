#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limite = 10;

typedef struct aluno {
  int cod;
  char nome[30];
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

  inserir(a1, alunos);
  inserir(a2, alunos);
  inserir(a3, alunos);
  inserir(a4, alunos);

  imprimir(alunos);
}

void imprimir(TALUNO** alunos) {
  for(int i = 0; i < limite; i++) {
    printf("%d - %d = %s\n\n",i,alunos[i]->cod, alunos[i]->nome);
  }
}

int inserir(TALUNO* aluno, TALUNO** alunos) {
  int pos = aluno->cod % limite;
  alunos[pos] = aluno;
  return pos;
}

TALUNO* criar(int cod, char* nome) {
  TALUNO* aluno = (TALUNO*) malloc(sizeof(TALUNO));
  aluno->cod = cod;
  strcpy(aluno->nome,nome);
  return aluno;
}
