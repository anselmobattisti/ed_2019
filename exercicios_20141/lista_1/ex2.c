/*
  Entrada: int n
  Programa: calcula os n primeiros primos

  Precisa implementar uma função que verifica se um número n
  é primo ou não, a forma mais fácil de fazer isso:
  1 - só verifica os ímpares, apenas o número 2 é um primo par
  2 - calcula a raiz de n e verifica se algum valor entre 3 e raiz de n tem resto da divisão 0
*/
#include <stdio.h>

int isPrime(int n);

int main(void) {
  int n = 0;
  int c = 0;
  int i = 0;

  while (n >= 0) {
    printf("\nDigite um número inteiro:");
    scanf("%d", &n);

    printf("\nOs números primos menores do que o valor %d são:\n\n",n);
    while(c<n){
      i++;
      if (isPrime(i)){
        c++;
        printf("%d ",i);
      }
    }
    c = 0;
    i = 0;
    printf("\n===============\n\n");
  }

  return 0;
}

int isPrime(int n) {
  // se for par nem faz a conta
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