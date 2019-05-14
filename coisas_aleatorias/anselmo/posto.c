#include <stdio.h>
#include <stdlib.h>

float autonomia(float g, float a);
float custo(float g, float pg, float a, float pa);
float custo_medio(float g, float pg, float a, float pa);

int main(void) {

  float g, pg, a, pa;
  printf("Entre com a quantidades de gasolina e álcool e o preço da gasolina e do álcool: ");

  scanf("%f",&g);
  scanf("%f",&a);
  scanf("%f",&pg);
  scanf("%f",&pa);

  printf("\n\nAutonomia: %.2f km",autonomia(g,a));
  printf("\nCusto médio: %.2f R$/km",custo_medio(g, pg, a, pa));

  printf("\n-----------------\n");
  printf("Viagem longa\n");
  for(int i = 0; i <= 50; i+=5) {
    int temp_a = 50 - i;
    printf("\n Gasolina: %d Alcool: %d Autonomia: %.2f Custo: %.2f Custo Médio: %.2f",i, temp_a, autonomia(i, temp_a), custo(i, pg, temp_a, pa), custo_medio(i, pg, temp_a, pa));
  }
  printf("\n-----------------\n");
  return 0;
}

float custo(float g, float pg, float a, float pa) {
  return (g*pg+a*pa);
}

float custo_medio(float g, float pg, float a, float pa) {
  return custo(g, pg, a, pa)/autonomia(g,a);
}

float autonomia(float g, float a) {
  return 13 * g + 9 * a;
}