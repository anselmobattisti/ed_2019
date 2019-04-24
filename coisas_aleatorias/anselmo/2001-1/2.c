/*
(a) Escreva uma função em C que receba como parâmetro um número inteiro não
negativo e retorne, como resultado da função, o valor do seu fatorial. A
assinatura desta função deve ser:
int fat (int n);

(b) Escreva um programa que capture um número inteiro entrado pelo usuário via
teclado e imprima o valor do fatorial usando a função escrita no item acima.
Pode-se assumir que o usuário nunca entrará com um valor menor do que zero.

*/
#include <stdio.h>

int fat (int n);

int main(void) {
  int n;
  scanf("%d",&n);
  printf("%d\n",fat(n));
  return 0;
}

int fat (int n) {
  int total = 1;

  while (n > 1) {
    total *= n;
    n--;
  }

  return total;
}