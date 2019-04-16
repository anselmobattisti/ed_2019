#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../utils/utils.c"

struct horario {
  char tipo[50];
  int hora;
  int min;
};

struct ponto {
  int x;
  int y;
};
/*
Renomeia  typedef struct ponto (para) Ponto
*/
typedef struct ponto Ponto;

struct circulo {
  Ponto p;
  float r;
};
typedef struct circulo Circulo;


float distancia_euclidiana(struct ponto p1, struct ponto p2);
float area(Circulo c);
int interior(Circulo c, Ponto p);

int main(void) {

  int num[3] = {1,2,3};

  imprime(num, 3);

  /*
  struct horario agora;
  agora.hora = 1;
  agora.min = 2;
  strcpy(agora.tipo, "Manhã");

  printf("Tipo: %s Hora: %d Minuto: %d\n\n", agora.tipo, agora.hora, agora.min);


  struct ponto p1;
  struct ponto p2;

  p1.x = 10;
  p1.y = 20;

  p2.x = 15;
  p2.y = 25;

  printf("%.3f", distancia_euclidiana(p1, p2));

  Ponto *pa;
  (*pa).x = 10;
  pa->y = 20;
  */

  Ponto p1;
  p1.x = 10;
  p1.y = 10;

  Ponto p2;
  p1.x = 100;
  p1.y = 100;

  Circulo c;
  c.p = p1;
  c.r = 20;

  printf("\n\nO círculo com centro em (%d.%d) tem uma área de %.2f",c.p.x, c.p.y,area(c));

  printf("\n\n%d\n\n",interior(c,p2));

  Ponto *p = (Ponto*) malloc(3*sizeof(Ponto));

  p[0].x = 20;
  p[0].y = 10;

  p[1].x = 21;
  p[1].y = 11;

  p[2].x = 22;
  p[2].y = 12;

  for(int i = 0; i < 3; i++) {
    printf("\n(%d,%d)\n",p[i].x, p[i].y);
  }
  return 0;
}

float distancia_euclidiana(struct ponto p1, struct ponto p2) {
  return sqrt(pow(p2.x - p1.x,2)+pow(p2.y - p1.y, 2));
}

float area(Circulo c) {
  return 3.14*pow(c.r,2);
}

int interior(Circulo c, Ponto p) {
  float d = distancia_euclidiana(c.p, p);
  if (d < c.r) {
    return 1;
  }
  return 0;
}