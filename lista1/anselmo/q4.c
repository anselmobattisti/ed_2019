/*
Q4) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero
*/

#include <stdio.h>

int isPrime(int n);

int main(void) {
  int n = 0;
  while (n >= 0) {
    printf("\nDigite um número inteiro:");
    scanf("%d", &n);

    printf("\nOs %d números primos maiores que %d são:\n\n",n,n);

    // versão não otimizada
    n++;
    for (int i = n; n > 1; i++) {
      int primo = 1;
      for(int j = 2; j <= i/2; j++) {
        if (i%j == 0) {
          primo = 0;
          break;
        }
      }
      if(primo) {
        printf("%d - ",i);
        n--;
      }
    }

    /* versão 1
    int count = n;
    while (count) {

      if (isPrime(n)) {
        count--;
        printf("%d - ", n);
      }
      n++;
    }
    */
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