#include <stdio.h>

int main(void) {
  int t;
  scanf("%d",&t);
  int aux = 0;
  for(int i = 0; i < 1000; i++) {
    printf("N[%d] = %d\n",i,aux);
    aux++;
    if (aux == t) {
      aux = 0;
    }
  }
}