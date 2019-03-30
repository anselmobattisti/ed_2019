/*
Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
segmento crescente destes n números. Exemplos:
 Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
 Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
Seu programa para quando n for menor ou igual a zero.
*/
#include <stdio.h>

int main(void) {
  int n = 1;
  int tam_max = 0;
  int a = -1, tmp = -1;

  while (n) {
    scanf("%d", &n);
    n++;
    while(n > 1) {
      tmp = a;
      scanf("%d",&a);

      if (a > tmp) {
        tam_max++;
      } else {
        tam_max = 1;
      }
      n--;
    }
    printf("\n\nA maior sequência positiva tinha: %d números.\n",tam_max);
  }
  return 0;
}
