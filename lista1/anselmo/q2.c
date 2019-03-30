/*
Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou
igual a zero.
*/
#include <stdio.h>

int isPrime(int n);

int main(void) {

  int n = 1;

  while (n > 0) {
    scanf("%d", &n);
    printf("\n\nOs %d primeiros primos são: ",n);
    int count = n;
    for (int i = 1; count; i++) {
      if (isPrime(i)) {
        printf("%d -",i);
        count--;
      }
    }
  }
}

int isPrime(int n) {
  // se for par nem faz a conta
  if (n == 2 || n == 1) {
    return 1;
  }

  if (n%2 == 0) {
    return 0;
  }

  int metade = n/2;

  for (int i = 3; i <= metade; i += 2) {
    if (n%i == 0) {
      return 0;
    }
  }
  return 1;
}