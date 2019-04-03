/*
Q5) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
programa deve ser “1100”. Seu programa para quando n for menor que zero
*/
#include <stdio.h>

char bin[8];

int main(void) {

  int n, i = 0;
  printf("\nDigite um número menor do que 255: ");
  scanf("%d",&n);

  while (n > 0) {
    bin[i] = n%2;
    n = n/2;
    i++;
  }


  printf("\nEm binário o valor é: ");
  for(int i = 7; i >= 0; i--) {
    printf("%d",bin[i]);
  }
  printf("\n");

  return 0;
}