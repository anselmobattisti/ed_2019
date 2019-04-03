/**
 * Peneira de Eratosthenes
 *
 * Criar um vetor com tamanho n, percorrer da menor
 * posição para a maior, calcular os múltinos de i e marcar
 * no vetor como sendo um número não primo.
 *
 * v[1] = 1;
 * v[2] = 1;
 * v[3] = 1;
 * v[4] = 0; # pois esse valor foi marcado como 0 nas potências de 2
 *
 * */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int n;

  printf("Digite o valor de n: ");
  scanf("%d",&n);
  n++;
  int v[n];
  for(int i = 0; i < n; i++) {
    v[i] = 1;
  }
  // seta todo mundo com 1 o que será usado como
  // referência para um número primo
  int c;
  for(int i = 2; i < n; i++) {

    if (v[i] == 1) {
      c = 2;
      while ( c <= n/i) {
        v[i*c] = 0;
        c++;
      }
    }
  }

  printf("\nOs primos até %d são: \n", n);
  for(int i = 1; i < n; i++) {
    // se for 1 é priemo
    if (v[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}