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
  int tmp;

  printf("Digite o valor de n:");
  scanf("%d",&n);
  n++;

  int *l = (int*) malloc(n*sizeof(int));

  if (l==NULL) {
    printf("Não foi possível alocar a memória.");
    return 0;
  }

  for(int i = 0; i < n; i++) {
    l[i] = 0;
  }

  // seta todo mundo com 1 o que será usado como
  // referência para um número primo
  int c = 0;
  for(int i = 2; i < n; i++) {
    int multiplo = i;
    c = 2;
    while (multiplo < n) {
      multiplo = i*c;
      l[multiplo] = 1;
      c++;
    }
  }

  printf("\nOs primos são:\n");
  for(int i = 1; i < n; i++) {
    // se for 1 é priemo
    if (l[i] == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}