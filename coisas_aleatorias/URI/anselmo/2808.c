#include <stdio.h>

int main(void) {
  char pi[2] = "";
  char pd[2] = "";

  int x1, y1, x2, y2;

  scanf("%s",pi);
  scanf("%s",pd);

  x1 = (pi[0]%97)+1;
  y1 = pi[1]%48;

  x2 = (pd[0]%97)+1;
  y2 = pd[1]%48;

  // printf("x1:%d y1:%d x2:%d y2:%d",x1,y1,x2,y2);
  // return 0;

  // m1 +1 +2
  if (x1+1 == x2 && y1+2 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m2
  if (x1+2 == x2 && y1+1 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m3
  if (x1+2 == x2 && y1-1 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m4
  if (x1+1 == x2 && y1-2 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m5
  if (x1-1 == x2 && y1-2 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m6
  if (x1-2 == x2 && y1-1 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m7
  if (x1-2 == x2 && y1+1 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  // m8
  if (x1-1 == x2 && y1+2 == y2) {
    printf("VALIDO\n");
    return 0;
  }

  printf("INVALIDO\n");
  return 0;
}