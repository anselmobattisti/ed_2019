#include <stdio.h>

void somaprod(float, float, float*, float*);

int main(void) {
  float a = 10, b = 20, s, p;

  somaprod(a, b, &s, &p);

  printf("\n\nUso de ponteiros\n\n");
  printf("\n\nSoma: %0.f\n",s);
  printf("\n\nProduto: %0.f\n",p);
  printf("\n\n");

  return 0;
}

void somaprod(float a, float b, float *s, float *p ) {

  *s = a+b;
  *p = a*b;

}