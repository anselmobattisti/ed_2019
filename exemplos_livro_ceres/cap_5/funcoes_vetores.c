#include <stdio.h>
#include <stdlib.h>

const int  TAM = 5;

float media(float *dados);

float media2(float* dados, int n);

float* getVet();

int main(void){

  float *d = (float*) malloc(TAM*sizeof(float));

  for (int i = 0; i < TAM; i++) {
    d[i] = 10*(i+1);
  }

  printf("\n\nA média é %.2f.\n\n", media2(d, TAM));

  free(d);

  float *p = getVet();

  printf("\n\n%.1f",p[0]);

  free(p);

  return 0;
}

float media(float *dados) {
  float m = 0;
  for (int i = 0; i < TAM; i++) {
    m += dados[i];
  }
  return m/TAM;
}

float media2(float* dados, int n) {
  float m = 0;
  for (int i = 0; i < n; i++) {
    m += dados[i];
  }
  return m/TAM;
}

float* getVet(){
  float *p = (float*) malloc(3*sizeof(float));

  p[0] = 10;
  p[1] = 20;
  p[2] = 30;

  return p;
}