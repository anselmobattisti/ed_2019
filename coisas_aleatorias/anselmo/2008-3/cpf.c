#include <stdio.h>
#include <stdlib.h>

void controle(int *cpf9d, int *dc1, int *dc2);
int verifica(int *cpf11d);

int main(void) {

  int n = 11;
  int cpfd11[11];

  while (n) {
    scanf("%d",&cpfd11[11-n]);
    n--;
  }

  for (int i = 0; i < 11; i++) {
    printf("%d",cpfd11[i]);
  }
  printf("\n");

  if (verifica(cpfd11)) {
    printf("\nCORRETO\n");
  } else {
    printf("\nINCORRETO\n");
  }
  return 0;
}

void controle(int *cpf9d, int *dc1, int *dc2) {

  int k = 10, soma1 = 0, soma2 = 0;

  for(int i = 0; i < 9; i++) {
    soma1 += k*cpf9d[i];
    soma2 += (k+1)*cpf9d[i];
    k--;
  }

  if (soma1 % 11 < 2) {
    *dc1 = 2;
  } else {
    *dc1 = 11 - (soma1 % 11);
  }

  soma2 += *dc1*2;

  if (soma2 % 11 < 2) {
    *dc2 = 2;
  } else {
    *dc2 = 11 - (soma2 % 11);
  }
}

int verifica(int *cpf11d) {

  int dc1, dc2;

  controle(cpf11d, &dc1, &dc2);

  if (cpf11d[9] == dc1 && cpf11d[10] == dc2)
    return 1;
  return 0;
}