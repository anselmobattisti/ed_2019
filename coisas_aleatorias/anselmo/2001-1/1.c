#include <stdio.h>

void ordena(float *x, float *y);

int main(void) {

  float a = 3.4;
  float b = 2.1;

  ordena(&a, &b);

  printf("a=%.2f\nb=%.2f\n",a,b);

}

void ordena(float *a, float *b) {
  float tmp;
  if (*a>*b) {
    tmp = *a;
    *a = *b;
    *b = tmp;
  }
}