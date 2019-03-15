// includes das libbs
#include <stdio.h>
#include <stdlib.h>

// cabeçalhos das funções
float c2f(float);

// método main
int main (void) {

  float c = 0;

  printf("Digite a temperatura em graus Célcius: ");

  scanf("%f",&c);

  printf("A temperatura convertida em Fahrenheit é de: %f \n\n",c2f(c));

  return 0;
}

// início das funções
float c2f(float c) {
  return ((c*9)/5)+32;
}