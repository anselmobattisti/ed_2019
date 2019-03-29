/*
  Esse exemplo é do uso dos operadores binários

  & = and bit a bit
  | = or bit a bit
  ^ = xor bit a bit
  >> = shift para direita
  << = shift para esquerda
*/
#include <stdio.h>

int main(void) {

  int x = 25, y = 8, r;

  printf("AND bit a bit \n");
  r = x & y;
  printf("%d\n\n",r); // 8

  printf("OR bit a bit \n");
  r = x | y;
  printf("%d\n\n",r); // 25

  printf("XOR bit a bit \n");
  r = x ^ y;
  printf("%d\n\n",r); // 17

  printf(">> Deslcoamento para direita (divisão), cada >> divede por 2 \n");
  r = x >> 2;
  printf("%d\n\n",r); // 6 pois a parte inteira de 25/4 = 6

  printf("<< Deslcoamento para esquerda (multiplicação), cada << multiplica por 2 \n");
  r = y << 3;
  printf("%d\n\n",r); // 64 pois 8 * 8 = 64


  // o retrono do sizeof é uma variável do tipo size_t que é printada com %zu
  printf("O tamanho do char é: %zu\n", sizeof(char));
  printf("O tamanho do interiro é: %zu\n",sizeof(int));
  printf("O tamanho do short é: %zu\n",sizeof(short));
  printf("O tamanho do float é: %zu\n", sizeof(float));

  return 0;
}