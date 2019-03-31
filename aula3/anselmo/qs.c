/**
 * Implementação do QuickSort em C
*/
#include <stdio.h>

void qs(int *vet, int n);

int main(void) {
  int n = 5;
  int vet[] = {10, 20, 5, 51, 80};

  // ss(n, vet);
  qs(vet, n);

  printf("\n");
  for(int i = 0; i < n; i++) {
    printf("%d - ", vet[i]);
  }
  printf("\n");
  return 0;
}

void qs(int *vet, int n) {

  // condição de parada
  if (n <= 1) return;

  int pivot = vet[0], a = 1, b = n-1;

  do {

    while (a < n && vet[a] < pivot) a++;
    while (vet[b] > pivot) b--;

    if (a < b) {
      int t = vet[a];
      vet[a] = vet[b];
      vet[b] = t;
      a++;
      b--;
    }
  } while (a <=b);
  vet[0] = vet[b];
  vet[b] = pivot;
  qs(vet, b);
  qs(&vet[b+1], n-b-1);
}

