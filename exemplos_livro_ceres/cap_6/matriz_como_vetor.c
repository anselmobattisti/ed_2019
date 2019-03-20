/**
 * Esse programa implementa a estratégia de usar
 * matrizes como sendo um vetor unidimenciosal
 *
 * */
#include <stdio.h>
#include <stdlib.h>

int* newMatriz(int i, int j);
void set(int* m, int i, int j, int k);
int get(int* m, int i, int j);

int main(void) {

  int* m = newMatriz(3,4);

  set(m,1,2,5);
  set(m,0,0,20);

  printf("\n\n%d\n\n",get(m,0,0));
  printf("\n\n%d\n\n",get(m,1,2));
  printf("\n\n%d\n\n",get(m,1,3));

  return 0;
}

int* newMatriz(int i, int j){
  return (int*) malloc((i*j)*sizeof(int));
}

void set(int* m, int i, int j, int k){
  int pos = i*j+j;
  m[pos] = k;
}

int get(int* m, int i, int j){
  int pos = i*j+j;
  return m[pos];
}