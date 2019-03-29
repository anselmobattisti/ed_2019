#include <stdio.h>

int main(void) {

  int a = 5;

  int *p;

  printf("\nEXEMPLO DO USO DE PONTEIRO\n");
  printf("\nO valor de a eh: %d",a);

  // apontar p para o endereço de memória de a
  p = &a;
  *p = 2;

  printf("\nO valor de a eh: %d\n\n",a);

  return 0;
}