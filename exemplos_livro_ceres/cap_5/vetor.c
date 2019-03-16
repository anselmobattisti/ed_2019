/*
  ATENÇÃO

  Para complicar esse código é necessário linkar a biblioteca math

   gcc -o vetor.sh vetor.c -lm

   Pasasndo -lm na hora da compilação

*/
#include <stdio.h>
#include <math.h>

int main(void) {

  int v[3];
  float m = 0, s = 0;

  printf("\n\nCálculo da média de 3 valores.\n\n");

  for(int i=0; i < 3; i++) {
    printf("\nDigite o valor %d: ",i);
    scanf("%d",&v[i]);
  }

  for(int i=0; i < 3; i++) {
    m += v[i];
  }

  m = m/3;

  printf("\n------------\n");
  printf("\nMedia: %.2f",m);

  // cálculo da variância
  for(int i=0; i < 3; i++) {
    s += pow((v[i] - m),2);
  }
  s = s/3;
  printf("\nVariância: %.2f\n\n",s);

  return 0;
}