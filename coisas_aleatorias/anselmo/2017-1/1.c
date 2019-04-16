#include<stdio.h>

float nota_minima (float p1, float p2);

int main(void) {

  float p1, p2;

  scanf("%f",&p1);
  scanf("%f",&p2);

  printf("\nP1 = %.2f\nP2 = %.2f\nNota mínima em P3 = %.2f\n",p1, p2, nota_minima(p1,p2));

  return 0;
}

/*
  a P3 * 2 + média tem que ser maior do que 5
*/
float nota_minima (float p1, float p2) {
  return (200-p1-p2) / 2;
}