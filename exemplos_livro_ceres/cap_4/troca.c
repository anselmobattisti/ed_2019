#include <stdio.h>

void troca(int*, int*);

int main(void) {

  int x = 10;
  int y = 20;

  printf("\n\nTroca dos valores de duas variáveis.\n\n");
  printf("\nAntes da troca x = %d e y = %d",x,y);
  troca(&x,&y);
  printf("\nDeopis da troca x = %d e y = %d\n",x,y);


}

void troca(int *x, int *y) {
  int temp = *x; // temp recebe o valor que estava armazenado na variável x
  *x = *y; // o ponteiro x recebe o valor do ponteiro de y
  *y = temp; // o ponteiro de y recebe o valor de temp que era x
}