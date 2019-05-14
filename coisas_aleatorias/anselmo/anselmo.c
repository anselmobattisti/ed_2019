#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
  char nome[30];
  int idade;
}TPessoa;

TPessoa* cria_pessoa(char* nome, int idade);
void set_idade(TPessoa* p, int idade);
int pessoa_mais_velha(TPessoa** pessoas, int n);


int main() {

  int t = 4;
  TPessoa* pessoas[10];

  pessoas[0] = cria_pessoa("Anselmo",35);
  pessoas[1] = cria_pessoa("Maria",15);
  pessoas[2] = cria_pessoa("Pedro",50);
  pessoas[3] = cria_pessoa("Carlos",5);

  printf("\n%d\n",pessoa_mais_velha(pessoas, t));
}

int pessoa_mais_velha(TPessoa** pessoas, int n) {

  if (pessoas == NULL)
    return -1;

  int i_mais_velha = 0;
  for (int i = 0; i < n; i++) {
    printf("%d - ",i);
    if (pessoas[i] != NULL) {
      if (pessoas[i]->idade > pessoas[i_mais_velha]->idade)
        i_mais_velha = i;
    }
  }

  return i_mais_velha;
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