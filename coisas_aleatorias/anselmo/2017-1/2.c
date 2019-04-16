#include <stdio.h>

int valida_senha (int m, int* vet);

int main(void) {

  int m = 4;
  int senha[] = {5,3,2,3};

  //int m = 5;
  //int senha[] = {7,2,0,1,6};

  if(valida_senha(m, senha)){
    printf("\nSenha Válida.\n");
  } else {
    printf("\nSenha Inválido.\n");
  }

  return 0;
}

int valida_senha (int m, int* vet) {
  int total = 0;
  int digito = vet[m-1] ;
  for (int i = 0; i < m-1; i++) {
    total += vet[i];
  }

  if (total%7 == digito) {
    return 1;
  }

  return 0;
}