#include <stdio.h>
#include <stdlib.h>

int main (void) {

  int *v = (int*) malloc(3*sizeof(int));

  v[0] = 10;
  v[1] = 20;
  v[2] = 30;

  for(int i = 0; i < 3; i++) {
    printf("\n%d\n", v[i]);
  }

  free(v);

  return 0;
}