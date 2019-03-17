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

  // seta todo mundo com 1 o que será usado como
  // referência para um número primo
  for(int i = 0; i < n; i++) {
    if (i % 2 == 0 && i != 1) {
      l[i] = 0;
    } else {
      l[i] = 1;
    }
  }

  for(int i = 3; i < n; i++) {
    // se o l[i] for igual a zero significa que
    // l já foi validado e que não pode ser primo
    if (l[i] == 1) {
      tmp = i;
      while (tmp < n) {
        tmp *= i;
        if (tmp < n)
          l[tmp] = 0;
      }
    }
  }

  printf("\nOs primos são:\n");
  for(int i = 1; i < n; i++) {
    // se for 1 é priemo
    if (l[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}