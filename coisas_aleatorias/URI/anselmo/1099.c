#include <stdio.h>
int main(void) {
  int n, i, j, t, s = 0;

  scanf("%d",&n);
  while(n > 0) {
    scanf("%d",&i);
    scanf("%d",&j);

    if (i > j) {
      t = i;
      i = j;
      j = t;
    }

    s = 0;
    for (int k = i+1; k < j; k++) {
      if (k%2 == 1) {
        s += k;
      }
    }
    printf("%d\n",s);
    n--;
  }
}