/**
 * Descrição:
 *
 * Implemente um programa que execute "infinitamente"
 * que responda se um número é primo ou não.
 *
 * O programa para quando n for menor ou igual a 1
 *
 * #42 - squid
 * */
#include <stdio.h>
#include <math.h>

int main(void) {

  int n, r, i, c = 0;

  while(1) {
    scanf("%d",&n);
    if (n <= 1) return 0;
    r = sqrt(n);

    for(i = 2; i <= r; i++){
      if (n%i == 0) {
        break;
      }
    }

    printf("\n\nO número %d é primo?\n",n);
    if (i <= r) {
      printf("Não");
    } else {
      printf("Sim");
    }
  }

  return 0;
}