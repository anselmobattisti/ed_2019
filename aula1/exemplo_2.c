#include <stdio.h>

/*
  Exemplos genéricos sobre operadores, cast, tipos de variáveis
*/

int main(void) {

  float a = 0, b = 0, c = 0;

  char d = ' ';

  int e = 10;

  // Apesar do tipo da variável A ser float, como a divisão é
  // realizada primeiro E eles são interiros então o resultado será truncado
  a = 5/2;
  printf("%f\n",a); // a resposta aqui é 2

  b = (float)5/2;
  printf("%f\n",b); // como o 5 (int) sofreu um cast pra flot o resultado será 2.5

  c = 5.0/2;
  printf("%f\n",c); // quando escreve 5.0 o valor é float e o resultado tbm será 5.0

  d = 'd';
  printf("%c\n",d);

  d++; // mesmo sendo 'char' o valor é tratado como int
  printf("%c\n",d); // o valor impresso será e

  printf("Exemplo de operadores antes e depois da variável!\n");
  printf("-----------\n");
  printf("%d, ",e); // imprime o valor 10
  printf("%d, ",++e); // imprime o valor 11 (soma e depois imprime)
  printf("%d, ",e++); // imprime o valor 11 (imprime e depois soma)
  printf("%d",e); // imprime o valor 12
  printf("\n-----------\n\n");

  return 0;
}
