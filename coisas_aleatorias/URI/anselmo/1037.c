/*
  Você deve fazer um programa que leia um valor qualquer e
  apresente uma mensagem dizendo em qual dos seguintes
  intervalos
  (
    [0,25],
    (25,50],
    (50,75],
    (75,100])
    este valor se encontra. Obviamente se o valor não estiver em nenhum destes intervalos, deverá ser impressa a mensagem
    “Fora de intervalo”.
*/
#include <stdio.h>

int main(void) {

  double n;

  scanf("%lf",&n);

  if (n >= 0 && n <=25) {
    printf("Intervalo [0,25]\n");
    return 0;
  }

  if (n > 25 && n <=50) {
    printf("Intervalo (25,50]\n");
    return 0;
  }

  if (n > 50 && n <= 75) {
    printf("Intervalo (50,75]\n");
    return 0;
  }

  if (n > 75 && n <= 100) {
    printf("Intervalo (75,100]\n");
    return 0;
  }

  printf("Fora de intervalo\n");

  return 0;
}