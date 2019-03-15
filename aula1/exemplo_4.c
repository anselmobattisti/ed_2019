#include <stdio.h>

void dezlinhas();

int main (void) {

  int x = 10, y = 20, z, t;

  z = x > y? x : y;

  t = printf("%d",z); // 20

  printf("\n\nFoi impresso anterioremente %d caracteres\n\n",t);

  dezlinhas();

  return 0;
}

void dezlinhas() {
  printf("Dez linhas \n");
  printf("--------- \n");
  for (int i = 1; i < 11; ++i) {
    printf("%d - \n",i);
  }
}