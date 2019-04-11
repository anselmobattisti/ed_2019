#include <stdio.h>
#include <math.h>
/*

  12 km / l

  t = tempo  8 horas
  v = velocidade 10 km

  consumo em litros = (v * t) / 12

*/

int main(void) {
  int t, v;

  scanf("%d",&t);
  scanf("%d",&v);

  printf("%.3f\n",(float) (v*t)/12);
}