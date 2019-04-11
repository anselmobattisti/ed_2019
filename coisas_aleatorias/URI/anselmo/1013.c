#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c;

  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);

  int mab = (a+b+abs(a-b)) / 2;

  if (c > mab) {
    mab = c;
  }

  printf("%d eh o maior\n",mab);
}