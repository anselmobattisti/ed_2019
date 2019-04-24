#include <stdio.h>

void SP(int a, int b, int *s, int *p);

int main(void) {
  int n1, n2, soma, prod;
  n1=2;
  n2=3;
  soma=0;
  prod=0;
  SP(n1,n2,&soma,&prod);

  printf("%d %d\n",soma, prod);
  return 0;
}

void SP(int a, int b, int *s, int *p) {
 *s=a+b; /* s recebe a soma de a e b */
 *p=a*b; /* p recebe o produto de a e b */
}