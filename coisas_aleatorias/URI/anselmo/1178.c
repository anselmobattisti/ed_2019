#include <stdio.h>

int main(void) {
  double t;
  scanf("%lf",&t);
  int aux = 0;
  double valor = t;
  for(int i = 0; i < 100; i++) {
    printf("N[%d] = %.4lf\n",i,valor);
    valor = (double) valor / 2;
  }
}