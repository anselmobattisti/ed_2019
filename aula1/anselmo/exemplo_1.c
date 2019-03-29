// includes das libbs
#include <stdio.h>
#include <stdlib.h>

// cabeçalhos das funções
float c2f(float);

// método main
int main (void) {

  float c = 0;

  printf("Digite a temperatura em graus Célcius: ");

  // a função scanf espera como parâmetro o endereço de memória
  // onde o dado será salvo, por essa razão é necessário o & antes
  // do nome da variável
  scanf("%f",&c);

  printf("A temperatura convertida em Fahrenheit é de: %f \n\n",c2f(c));

  // por padrão sempre colocar o return 0 no final do main
  return 0;
}

// início das funções
float c2f(float c) {
  return ((c*9)/5)+32;
}