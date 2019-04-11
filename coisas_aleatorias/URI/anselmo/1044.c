#include <stdio.h>
int main(void) {
  int a, b, tmp;

  scanf("%d",&a);
  scanf("%d",&b);

  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  if (b%a == 0) {
    printf("Sao Multiplos\n");
  } else {
    printf("Nao sao Multiplos\n");
  }
}