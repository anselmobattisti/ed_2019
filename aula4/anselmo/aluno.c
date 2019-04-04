/*

  Exemplo do uso de struct de alunos

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno {
  char nome[31];
  float cr;
}TALUNO;

void imprime_aluno(TALUNO a);
TALUNO* copia_aluno(TALUNO a);

/*
  Esse ela não deu o exemplo em sala mas apenas fez o
  comentároi a respeito.
*/
TALUNO* copia_aluno_ponteiro(TALUNO *a);

int main(void) {

  TALUNO a;
  a.cr = 7;
  strcpy(a.nome, "Maria da Silva");

  TALUNO *b;
  b = copia_aluno(a);
  strcpy(a.nome, "Pedro");
  imprime_aluno(a);
  imprime_aluno(*b);

  TALUNO c;
  c.cr = 6;
  strcpy(c.nome, "Carlos de Almeida");
  TALUNO *d;

  imprime_aluno(c);

  d = copia_aluno_ponteiro(&c);
  d->cr = 7.5;
  imprime_aluno(*d);

  return 0;
}

/*
  Nesse exemplo é feita uma cópia completa do objeto para
  a pilha de execução
*/
TALUNO* copia_aluno(TALUNO a) {
  TALUNO *b = (TALUNO*) malloc(sizeof(TALUNO));
  b->cr = a.cr;
  strcpy(b->nome, a.nome);
  return b;
}

/*
  Nesse exemplo é feita uma cópia apenas do
  endereo de memória que aponta para o aluno que será
  copiaddo
*/
TALUNO* copia_aluno_ponteiro(TALUNO *a) {
  TALUNO *b = (TALUNO*) malloc(sizeof(TALUNO));
  b->cr = a->cr;
  strcpy(b->nome, a->nome);
  return b;
}

void imprime_aluno(TALUNO a) {
  printf("\nFicha do aluno\n");
  printf("\n-------------\n");
  printf("\nNome: %s",a.nome);
  printf("\nCR: %.2f",a.cr);
  printf("\n-------------\n");
}
