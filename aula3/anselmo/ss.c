/**
 * Implementação do Selection Sort:
 * a: iterativa
 * b: recursiva
*/
#include <stdio.h>

void ss(int n, int* vet);
void ssrec(int n, int* vet);

int main(void) {

  int n = 5;
  int vet[] = {10, 20, 5, 51, 80};

  // ss(n, vet);
  ssrec(n, vet);

  printf("\n");
  for(int i = 0; i < n; i++) {
    printf("%d - ", vet[i]);
  }
  printf("\n");
  return 0;
}

/**
 * Versão interativa do selection sort.
*/
void ss(int n, int* vet) {

  int i, j, menor, tmp;
  for (i = 0; i < n; i++) {
    menor = i;
    for (j = i; j < n; j++) {
      if (vet[menor] > vet[j]) {
        menor = j;
      }
    }

    if (menor != i) {
      tmp = vet[i];
      vet[i] = vet[menor];
      vet[menor] = tmp;
    }
  }
}

void ssrec(int n, int* vet) {
  if (n <= 1) return;
  int i;
  int menor = 0;
  for (i = 1; i < n; i++) {
    if (vet[menor] > vet[i]) {
      menor = i;
    }
  }

  if (menor > 0) {
    int tmp = vet[0];
    vet[0] = vet[menor];
    vet[menor] = tmp;
  }

  ssrec((n-1), &vet[1]);
}