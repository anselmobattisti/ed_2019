// include das libs
#include <stdio.h>

// declaração dos cabeçalhos
float fat(float);

// função principal
int main(void) {

  float n = 5;

  printf("\n\nO fatorial de %.0f é %.0f\n\n", fat(n), n);

  return 0;
}

/*
  Implementação da função fatorial
*/
float fat(float n) {

  if (n < 0) {
    return 0;
  }

  float f = 1;

  while (n > 0) {
    f = f * n;
    n--;
  }

  return f;

}