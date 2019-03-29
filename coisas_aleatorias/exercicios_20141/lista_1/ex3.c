/*
  Programa que recebe dois inteiros,

  pazer a potência do segundo até que a
  mesma seja menor do que o primeiro número

  20 2 imprime 2 4 8 16

  20 3 imprime 3 9

  # Estratégia
  Para calcular a lista de potência, pega o número m
  e multiplica por ele mesmo e o resultado disso
  multiplica de novo por ele mesmo até que o resultado
  for menor ou igual a n
*/
#include <stdio.h>

int main(void) {
  int n, m, p;

  printf("\n\nDigite o limite n: ");
  scanf("%d",&n);

  printf("\n\nDigite o valor inicial m: ");
  scanf("%d",&m);

  if (n <= 1) {
    printf("N deve ser maior do que 1");
  }

  printf("\nLista de potências de %d até %d é: \n",m,n);
  p = m;
  while (p <= n) {
    printf("%d ",p);
    p = m * p;
  }
  printf("\n");
}