#include <stdio.h>
#include <stdlib.h>

void media(int *vet, int n, float* ar) {
  *ar = 0;
  for (int i = 0; i < n; i++) {
    *ar += vet[i];
  }
  *ar = *ar / n;
}

int main(void) {
  int vet[] = {10, 20, 30};
  float ar;
  media(vet, 3, &ar);
  printf("Média: %.3f",ar);
  return 0;
}

