#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
  char *nome;
  int idade;
}TPessoa;

TPessoa* cria_pessoa(char* nome, int idade);
void set_idade(TPessoa* p, int idade);

int main() {

  TPessoa *p = cria_pessoa("Anselmo",35);
  set_idade(p, 40);
  printf("%d",p->idade);
}

TPessoa* cria_pessoa(char* nome, int idade) {
  TPessoa* p = (TPessoa*) malloc(sizeof(TPessoa));
  strcpy(p->nome, nome);
  p->idade = idade;
  return p;
}

void set_idade(TPessoa* p, int idade) {
  if (p != NULL) {
    p->idade = idade;
  }
}