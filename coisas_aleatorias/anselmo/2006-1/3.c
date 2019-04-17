#include <stdio.h>

int ordenado (int n, int* v);

int main(void) {

  int n = 6;
  int v[] = {1,2,5,4,5,6};

  if (ordenado(n,v)) {
    printf("\nOrdenado\n");
  } else {
    printf("\nFora de ordem\n");
  }

  return 0;
}

int ordenado (int n, int* v) {
  for (int i = 0; i < n-1; i++) {
    if (v[i] > v[i+1])
      return 0;
  }
  return 1;
}