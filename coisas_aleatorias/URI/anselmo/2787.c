#include <stdio.h>
int main(void) {
  int cor = 1, l, c;

  scanf("%d",&l);
  scanf("%d",&c);

  if (c%2)
    cor = 0;

  if (l%2)
    cor = !cor;

  printf("%d\n",cor);
}