#include <stdio.h>
#include <stdlib.h>

float media(float** despesas, int m, int n, int i, int j, int k);

int main() {

  float **d = (float**) malloc(sizeof(float*)*4);

  for (int i = 0; i < 5; i++) {
    d[i] = (float*) malloc(sizeof(float));
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      d[i][j] = i+j;
    }
  }

  float d2 = media(d,4,5,2,0,4);

  printf("\nMédia: %.2f.\n",d2);

  return 0;
}

float media(float** despesas, int m, int n, int i, int j, int k) {

  float med = 0;
  for (int x = j; x <= k; x++) {
    med += (float) despesas[i][x];
  }

  return med/(k-j+1);

}