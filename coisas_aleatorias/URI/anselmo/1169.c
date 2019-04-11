#include <stdio.h>
#include <math.h>

int main(void) {
  int n, t;
  unsigned long long num_grao;

  scanf("%d",&n);

  // 12 graos igual a uma grama
  while (n>0) {
    scanf("%d",&t);
    num_grao = pow(2,t)/12000;
    printf("%Ld kg\n", num_grao);
    n--;
  }
}