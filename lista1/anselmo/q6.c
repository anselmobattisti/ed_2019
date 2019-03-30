#include <stdio.h>

int main(void) {
  int x, y, z;
  int teste;
  x = 5;
  y = x++;
  z = x--;
  teste = !y == !x;
  printf("\n\nx:%d y:%d z:%d teste:%d", x, y, z, teste);

  x = 5;
  y = x++;
  z = x--;
  teste = ((x++ > y) || (--z <= y));
  printf("\n\nx:%d y:%d z:%d teste:%d", x, y, z, teste);

  x = 5;
  y = x++;
  z = x--;
  teste = ((!x) || (!(!z)));
  printf("\n\nx:%d y:%d z:%d teste:%d", x, y, z, teste);

  x = 5;
  y = x++;
  z = x--;
  teste = (((x + y) > z) && (x++));
  printf("\n\nx:%d y:%d z:%d teste:%d", x, y, z, teste);

  x = 5;
  y = x++;
  z = x--;
  teste = x && y + !3 || 4;
  printf("\n\nx:%d y:%d z:%d teste:%d", x, y, z, teste);

}