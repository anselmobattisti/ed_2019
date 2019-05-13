#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *vet, int n, int x);

int main(void) {
  int vet[10] = {1,2,3,4,5,6,7,8,9,10};

  printf("\n%d\n",busca_binaria(vet,10,-10));
}

int busca_binaria(int *vet, int n, int x) {
  int e = -1, d = n;
  while (e < (d - 1)) {
    int m = (e + d) / 2;
    if (vet[m] < x) {
      e = m;
    } else {
      d = m;
    }
  }
  return d;
}